/** @file
*
*  Copyright (c) 2016, Hisilicon Limited. All rights reserved.
*  Copyright (c) 2016, Linaro Limited. All rights reserved.
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/

#include <Uefi.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>

#include <Library/PlatformSysCtrlLib.h>
#include <Library/SerdesLib.h>
#include <Protocol/PciIo.h>
#include <Protocol/PciRootBridgeIo.h>
#include <IndustryStandard/Pci.h>

UINT64 PCIE_APB_SLVAE_BASE_1616[2][8] = {{0xa0090000, 0xa0200000, 0xa00a0000, 0xa00b0000, 0x8a0090000, 0x8a0200000, 0x8a00a0000, 0x8a00b0000},
                                         {0x600a0090000, 0x600a0200000, 0x600a00a0000, 0x600a00b0000, 0x700a0090000, 0x700a0200000, 0x700a00a0000, 0x700a00b0000},};
UINT8 PCIE_ROOT_BRIDGE_BUS_NUM_1P[8] = {0x81, 0x91, 0xf9, 0xb1, 0x89, 0x79, 0xc1, 0x91};
UINT8 PCIE_ROOT_BRIDGE_BUS_NUM_2P[8] = {0x81, 0x91, 0x11, 0xb1, 0x21, 0x31, 0xa9, 0xb9};

#define RegWrite(addr,data)            (*(volatile UINT32*)(UINTN)(addr) = (data))
#define RegRead(addr,data)             ((data) = *(volatile UINT32*)(UINTN)(addr))


VOID 
EFIAPI 
OemEs3000PerformaceOperation(
  IN EFI_EVENT  Event,
  IN VOID       *Context
  )

{
    EFI_STATUS                         Status;
    UINTN                              HandleIndex;
    EFI_HANDLE                        *HandleBuffer;
    UINTN                              HandleCount;
    EFI_PCI_IO_PROTOCOL               *PciIo;
    UINTN                              SegmentNumber;
    UINTN                              BusNumber;
    UINTN                              DeviceNumber;
    UINTN                              FunctionNumber;
    UINT16 DeviceId = 0;
    UINT16 VenderId = 0;
    UINT8  i = 255;
    UINT32 Value = 0;

    Status = gBS->LocateHandleBuffer (
          ByProtocol,
          &gEfiPciIoProtocolGuid,
          NULL,
          &HandleCount,
          &HandleBuffer
          );
    if(EFI_ERROR(Status)) {
        DEBUG((EFI_D_ERROR, " Locate gEfiPciIoProtocol Failed.\n"));           
        //gBS->FreePool ((VOID *)HandleBuffer);
        return;
    }
    DEBUG((EFI_D_ERROR, "HandleCount = %d\n", HandleCount));  
    for (HandleIndex = 0; HandleIndex < HandleCount; HandleIndex++) {
        (VOID)gBS->HandleProtocol (
            HandleBuffer[HandleIndex],
            &gEfiPciIoProtocolGuid,
            (VOID **)&PciIo
            );

        (VOID)PciIo->GetLocation(PciIo,&SegmentNumber,&BusNumber,&DeviceNumber,&FunctionNumber);
        
                DEBUG((EFI_D_ERROR,"PCIe device plot in slot Seg %d  bdf %d %d %d\r\n",SegmentNumber,BusNumber,DeviceNumber,FunctionNumber));
                (VOID)PciIo->Pci.Read(PciIo,EfiPciIoWidthUint16,PCI_DEVICE_ID_OFFSET,1,&DeviceId);
                (VOID)PciIo->Pci.Read(PciIo,EfiPciIoWidthUint16,PCI_VENDOR_ID_OFFSET,1,&VenderId);
                if((DeviceId == 0x0123) && (VenderId == 0x19e5)) {
                  if (SegmentNumber == 0) {
                    for(i = 0; i < 8; i ++) {
                        if (BusNumber == PCIE_ROOT_BRIDGE_BUS_NUM_1P[i])
                            break;
                    }
                  }
                  if (SegmentNumber == 1) {
                    for(i = 0; i < 8; i ++) {
                        if (BusNumber == PCIE_ROOT_BRIDGE_BUS_NUM_2P[i])
                            break;
                    }   
                  }
                  
                  DEBUG((EFI_D_ERROR,"find es3000 i=%x ...............\n", i));
                  if (i >= 0 && i < 8) {
                    RegWrite((UINT64)PCIE_APB_SLVAE_BASE_1616[SegmentNumber][i] + 0x1110, 0x28002fff);
                    RegRead((UINT64)PCIE_APB_SLVAE_BASE_1616[SegmentNumber][i] + 0x1110, Value);
                    DEBUG((EFI_D_ERROR,"Read reg(%llx) value = %x\n", (UINT64)PCIE_APB_SLVAE_BASE_1616[SegmentNumber][i] + 0x1110, Value));
                  }
                }
                      
    }
    
    return;
}

EFI_STATUS
EFIAPI
Es3000PerformanceDxeEntry (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable)
{
  EFI_STATUS Status;
  EFI_EVENT  Event = NULL;
  
  //
  // Register notify function
  //
  Status = gBS->CreateEvent (
                  EVT_SIGNAL_EXIT_BOOT_SERVICES,
                  TPL_CALLBACK,
                  OemEs3000PerformaceOperation,
                  NULL,
                  &Event
                  );
 
  if (EFI_ERROR(Status))
  {
    DEBUG ((EFI_D_ERROR, "[%a:%d] - Es3000 performace createEvent failed: %r\n", __FUNCTION__,
        __LINE__, Status));
  }

  return Status;
}

