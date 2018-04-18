/** @file
*
*  Copyright (c) 2018, Hisilicon Limited. All rights reserved.
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
#include <IndustryStandard/Pci.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Protocol/PciIo.h>

VOID
SetIntLine (
  )
{
  EFI_STATUS                         Status;
  UINTN                              HandleIndex;
  EFI_HANDLE                         *HandleBuffer;
  UINTN                              HandleCount;
  EFI_PCI_IO_PROTOCOL                *PciIo;
  UINT8                              INTLine;
  UINTN                              Segment;
  UINTN                              Bus;
  UINTN                              Device;
  UINTN                              Fun;

  Status = gBS->LocateHandleBuffer (
                  ByProtocol,
                  &gEfiPciIoProtocolGuid,
                  NULL,
                  &HandleCount,
                  &HandleBuffer
                  );
  if (EFI_ERROR (Status)) {
      DEBUG  ((DEBUG_ERROR, " Locate gEfiPciIoProtocol Failed.\n"));
      gBS->FreePool ((VOID *)HandleBuffer);
      return;
  }

  for (HandleIndex = 0; HandleIndex < HandleCount; HandleIndex++) {
      Status = gBS->HandleProtocol (
                      HandleBuffer[HandleIndex],
                      &gEfiPciIoProtocolGuid,
                      (VOID **)&PciIo
                      );
      if (EFI_ERROR (Status)) {
          continue;
      }

      INTLine = 0;
      (VOID)PciIo->Pci.Write (
                         PciIo,
                         EfiPciIoWidthUint8,
                         PCI_INT_LINE_OFFSET,
                         1,
                         &INTLine);
      (VOID)PciIo->GetLocation (PciIo, &Segment, &Bus, &Device, &Fun);
      DEBUG ((DEBUG_INFO, "Set BDF(%x-%x-%x) IntLine to 0\n", Bus, Device, Fun));
  }

  gBS->FreePool ((VOID *)HandleBuffer);
  return;
}

EFI_STATUS
EFIAPI
PlatformMiscDxeEntry (
  IN EFI_HANDLE           ImageHandle,
  IN EFI_SYSTEM_TABLE     *SystemTable
  )
{
  EFI_STATUS  Status;
  EFI_EVENT   Event;

  Status = gBS->CreateEventEx (
                  EVT_NOTIFY_SIGNAL,
                  TPL_CALLBACK,
                  SetIntLine,
                  NULL,
                  &gEfiEventReadyToBootGuid,
                  &Event
                  );
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Create event for SetIntLine, %r!\n", Status));
  }

  return EFI_SUCCESS;
}

