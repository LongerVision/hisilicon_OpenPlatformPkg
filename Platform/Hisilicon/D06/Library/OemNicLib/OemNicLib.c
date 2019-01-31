/** @file
*
*  Copyright (c) 2018, Hisilicon Limited. All rights reserved.
*  Copyright (c) 2017, Linaro Limited. All rights reserved.
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
#include <Library/BaseLib.h>
#include <Library/CpldIoLib.h>
#include <Library/DebugLib.h>
#include <Library/I2CLib.h>
#include <Library/IoLib.h>
#include <Library/OemNicLib.h>

#define CPU2_SFP2_100G_CARD_OFFSET   0x25

#define SOCKET1_NET_PORT_100G         1
#define SOCKET0_NET_PORT_NUM          4
#define SOCKET1_NET_PORT_NUM          2

#define CARD_PRESENT_100G               (BIT7)
#define EEPROM_I2C_PORT          4
#define EEPROM_PAGE_SIZE         0x40
#define MAC_ADDR_LEN             6
#define I2C_OFFSET_EEPROM_ETH0   (0xc00)
#define I2C_SLAVEADDR_EEPROM     (0x52)

#define SRAM_NIC_NCL1_OFFSET_FLAG   0xA0E87FE0
#define SRAM_NIC_NCL2_OFFSET_FLAG   0xA0E87FE4

#pragma pack(1)
typedef struct {
  UINT16 Crc16;
  UINT16 MacLen;
  UINT8  Mac[MAC_ADDR_LEN];
} NIC_MAC_ADDRESS;
#pragma pack()

ETH_PRODUCT_DESC gEthPdtDesc[ETH_MAX_PORT] =
{
    {TRUE,   ETH_SPEED_10KM,  ETH_FULL_DUPLEX, ETH_INVALID, ETH_INVALID},
    {TRUE,   ETH_SPEED_10KM,  ETH_FULL_DUPLEX, ETH_INVALID, ETH_INVALID},
    {FALSE,  ETH_INVALID,     ETH_INVALID,     ETH_INVALID, ETH_INVALID},
    {FALSE,  ETH_INVALID,     ETH_INVALID,     ETH_INVALID, ETH_INVALID},
    {TRUE,   ETH_SPEED_1000M, ETH_FULL_DUPLEX, ETH_PHY_MVL88E1512_ID, 0},
    {TRUE,   ETH_SPEED_1000M, ETH_FULL_DUPLEX, ETH_PHY_MVL88E1512_ID, 1},
    {FALSE,  ETH_INVALID,     ETH_INVALID,     ETH_INVALID, ETH_INVALID},
    {FALSE,  ETH_INVALID,     ETH_INVALID,     ETH_INVALID, ETH_INVALID}
};

EFI_STATUS
OemGetMacE2prom(
  IN  UINT32 Port,
  OUT UINT8  *Addr
  )
{
  I2C_DEVICE       I2cDev = {0};
  EFI_STATUS       Status;
  UINT16           I2cOffset;
  UINT16           Crc16;
  NIC_MAC_ADDRESS  MacDesc = {0};
  UINT16           RemainderMacOffset;
  UINT16           LessSizeOfPage;
  UINT32           I = 0;

  Status = I2CInit (0, EEPROM_I2C_PORT, Normal);
  if (EFI_ERROR (Status))
  {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Call I2CInit failed! p1=0x%x.\n",
            __FUNCTION__, __LINE__, Status));
    return Status;
  }

  I2cOffset = I2C_OFFSET_EEPROM_ETH0 + (Port * sizeof (NIC_MAC_ADDRESS));

  I2cDev.DeviceType = DEVICE_TYPE_E2PROM;
  I2cDev.Port = EEPROM_I2C_PORT;
  I2cDev.SlaveDeviceAddress = I2C_SLAVEADDR_EEPROM;
  I2cDev.Socket = 0;
  RemainderMacOffset = I2cOffset % EEPROM_PAGE_SIZE;
  LessSizeOfPage = EEPROM_PAGE_SIZE - RemainderMacOffset;
  //The length of NIC_MAC_ADDRESS is 10 bytes long,
  //It surly less than EEPROM page size, so we could
  //code as below, check the address whether across the page boundary,
  //and split the data when across page boundary.
  if (sizeof (NIC_MAC_ADDRESS) <= LessSizeOfPage) {
    Status = I2CRead (&I2cDev, I2cOffset, sizeof (NIC_MAC_ADDRESS), (UINT8 *) &MacDesc);
  } else {
    Status = I2CRead (&I2cDev, I2cOffset, LessSizeOfPage, (UINT8 *) &MacDesc);
    if (!EFI_ERROR (Status)) {
      Status |= I2CRead (
                  &I2cDev,
                  I2cOffset + LessSizeOfPage,
                  sizeof (NIC_MAC_ADDRESS) - LessSizeOfPage,
                  (UINT8 *) &MacDesc + LessSizeOfPage
                  );
    }
  }
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Call I2cRead failed! p1=0x%x.\n",
            __FUNCTION__, __LINE__, Status));
    return Status;
  }

  Crc16 = CalculateCrc16 (
            &(MacDesc.MacLen),
            sizeof (MacDesc.MacLen) + sizeof (MacDesc.Mac)
            );
  if ((Crc16 != MacDesc.Crc16) || (Crc16 == 0)) {
    return EFI_NOT_FOUND;
  }

  for (I = 0; I < MAC_ADDR_LEN; I++) {
    Addr[I] = MacDesc.Mac[I];
  }

  return EFI_SUCCESS;
}


EFI_STATUS
OemSetMacE2prom (
  IN UINT32 Port,
  IN UINT8 *Addr
  )
{
  I2C_DEVICE       I2cDev = {0};
  EFI_STATUS       Status;
  UINT16           I2cOffset;
  NIC_MAC_ADDRESS  MacDesc = {0};
  UINT32           I;
  UINT16           RemainderMacOffset;
  UINT16           LessSizeOfPage;

  I = 0;
  MacDesc.MacLen = MAC_ADDR_LEN;

  for (I = 0; I < MAC_ADDR_LEN; I++) {
    MacDesc.Mac[I] = Addr[I];
  }

  MacDesc.Crc16 = CalculateCrc16 (
                    &(MacDesc.MacLen),
                    sizeof (MacDesc.MacLen) + MAC_ADDR_LEN
                    );

  Status = I2CInit (0, EEPROM_I2C_PORT, Normal);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Call I2CInit failed! p1=0x%x.\n",
           __FUNCTION__, __LINE__, Status));
    return Status;
  }

  I2cOffset = I2C_OFFSET_EEPROM_ETH0 + (Port * sizeof (NIC_MAC_ADDRESS));

  I2cDev.DeviceType = DEVICE_TYPE_E2PROM;
  I2cDev.Port = EEPROM_I2C_PORT;
  I2cDev.SlaveDeviceAddress = I2C_SLAVEADDR_EEPROM;
  I2cDev.Socket = 0;
  RemainderMacOffset = I2cOffset % EEPROM_PAGE_SIZE;
  LessSizeOfPage = EEPROM_PAGE_SIZE - RemainderMacOffset;
  //The length of NIC_MAC_ADDRESS is 10 bytes long,
  //It surly less than EEPROM page size, so we could
  //code as below, check the address whether across the page boundary,
  //and split the data when across page boundary.
  if (sizeof (NIC_MAC_ADDRESS) <= LessSizeOfPage) {
    Status = I2CWrite (
               &I2cDev,
               I2cOffset,
               sizeof (NIC_MAC_ADDRESS),
               (UINT8 *) &MacDesc
               );
  } else {
    Status = I2CWrite (&I2cDev, I2cOffset, LessSizeOfPage, (UINT8 *) &MacDesc);
    if (!EFI_ERROR (Status)) {
      Status |= I2CWrite (
                  &I2cDev,
                  I2cOffset + LessSizeOfPage,
                  sizeof (NIC_MAC_ADDRESS) - LessSizeOfPage,
                  (UINT8 *) &MacDesc + LessSizeOfPage
                  );
    }
  }
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Call I2cWrite failed! p1=0x%x.\n",
            __FUNCTION__, __LINE__, Status));
    return Status;
  }
  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
OemGetMac (
  IN OUT EFI_MAC_ADDRESS *Mac,
  IN     UINTN           Port
  )
{
  EFI_STATUS Status;

  if (Mac == NULL) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Mac buffer is null!\n",
            __FUNCTION__, __LINE__));
    return EFI_INVALID_PARAMETER;
  }

  Status = OemGetMacE2prom (Port, Mac->Addr);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR,
      "[%a]:[%dL] Cannot get MAC from EEPROM, Status: %r; using default MAC.\n",
      __FUNCTION__, __LINE__, Status));

    Mac->Addr[0] = 0xFF;
    Mac->Addr[1] = 0xFF;
    Mac->Addr[2] = 0xFF;
    Mac->Addr[3] = 0xFF;
    Mac->Addr[4] = 0xFF;
    Mac->Addr[5] = 0xFF;
    return EFI_SUCCESS;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
OemSetMac (
  IN EFI_MAC_ADDRESS *Mac,
  IN UINTN           Port
  )
{
  EFI_STATUS Status;

  if (Mac == NULL) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Mac buffer is null!\n",
            __FUNCTION__, __LINE__));
    return EFI_INVALID_PARAMETER;
  }

  Status = OemSetMacE2prom (Port, Mac->Addr);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Set mac failed!\n", __FUNCTION__, __LINE__));
    return Status;
  }

  return EFI_SUCCESS;
}

UINT32
OemEthFindFirstSP (
  VOID
  )
{
  UINT32 I;

  for (I = 0; I < ETH_MAX_PORT; I++) {
    if (gEthPdtDesc[I].Valid == TRUE) {
      return I;
    }
  }

  return ETH_INVALID;
}

ETH_PRODUCT_DESC *
OemEthInit (
  UINT32 port
  )
{
  return (ETH_PRODUCT_DESC *)(&(gEthPdtDesc[port]));
}


BOOLEAN
OemIsInitEth (
  UINT32 Port
  )
{
  return TRUE;
}

EFI_STATUS ConfigCDR(UINT32 Socket)
{
    return EFI_SUCCESS;
}

UINT32 OemGetNclConfOffset (UINT32 Socket)
{
    UINT32           Cpu1NclConfOffet = 0;
    UINT32           Cpu2NclConfOffet = 0;

    if (0 == Socket) {
      MmioWrite32 (SRAM_NIC_NCL1_OFFSET_FLAG, Cpu1NclConfOffet);
      return Cpu1NclConfOffet;
    } else {
      //2P only
      // P1
      if ((ReadCpldReg (CPU2_SFP2_100G_CARD_OFFSET) & CARD_PRESENT_100G) != 0) {
        Cpu2NclConfOffet =  0x20000;
      } else {
        Cpu2NclConfOffet =  0x10000;
      }
      MmioWrite32 (SRAM_NIC_NCL2_OFFSET_FLAG, Cpu2NclConfOffet);
      return Cpu2NclConfOffet;
    }
}

UINT32 OemGetNetPortNum (UINT32 Socket)
{
    if (0 == Socket){
    return SOCKET0_NET_PORT_NUM;
    }

    if ((ReadCpldReg (CPU2_SFP2_100G_CARD_OFFSET) & CARD_PRESENT_100G) != 0) {
      return SOCKET1_NET_PORT_100G;
    } else {
      return SOCKET1_NET_PORT_NUM;
    }
}
