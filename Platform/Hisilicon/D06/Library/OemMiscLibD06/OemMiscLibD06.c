/** @file
*
*  Copyright (c) 2018, Hisilicon Limited. All rights reserved.
*  Copyright (c) 2018, Linaro Limited. All rights reserved.
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
#include <PlatformArch.h>
#include <Library/BaseMemoryLib.h>
#include <Library/CpldD06.h>
#include <Library/CpldIoLib.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Library/LpcLib.h>
#include <Library/OemAddressMapLib.h>
#include <Library/OemMiscLib.h>
#include <Library/PcdLib.h>
#include <Library/PlatformSysCtrlLib.h>
#include <Library/SerdesLib.h>
#include <Library/SerialPortLib.h>
#include <Library/TimerLib.h>
#include <Library/UefiRuntimeLib.h>

// The delay is need for cpld and I2C. This is a empirical value. MemoryFence is no need.
#define RTC_DELAY_30_MS            30000
// The delay is need for cpld and I2C. This is a empirical value. MemoryFence is no need.
#define RTC_DELAY_2_MACROSECOND    2

REPORT_PCIEDIDVID2BMC PcieDeviceToReport[PCIEDEVICE_REPORT_MAX] = {
  {67,0,0,0},
  {225,0,0,3},
  {0xFFFF,0xFFFF,0xFFFF,0xFFFF},
  {0xFFFF,0xFFFF,0xFFFF,0xFFFF}
};

//Cpu0 Riser type is (X16 + X8) & Cpu1 Riser type is (X16 + X8)
REPORT_PCIEDIDVID2BMC PcieDeviceToReport_2P_Type1 [PCIEDEVICE_REPORT_MAX] = {
  {0x01,0,0,0},
  {0x03,0,0,1},
  {0xFF,0xFF,0xFF,2},
  {0x81,0,0,3},
  {0x84,0,0,4},
  {0xFF,0xFF,0xFF,5}
};

//Cpu0 Riser type is (X16 + X8) & Cpu1 Riser type is (3 * X8)
REPORT_PCIEDIDVID2BMC PcieDeviceToReport_2P_Type2 [PCIEDEVICE_REPORT_MAX] = {
  {0x01,0,0,0},
  {0x03,0,0,1},
  {0xFF,0xFF,0xFF,2},
  {0xFF,0xFF,0xFF,3},
  {0x81,0,0,4},
  {0x85,0,0,5}
};

//Cpu0 Riser type is (3 * X8) & Cpu1 Riser type is (X16 + X8)
REPORT_PCIEDIDVID2BMC PcieDeviceToReport_2P_Type3 [PCIEDEVICE_REPORT_MAX] = {
  {0xFF,0xFF,0xFF,0},
  {0x01,0,0,1},
  {0x04,0,0,2},
  {0x81,0,0,3},
  {0x84,0,0,4},
  {0xFF,0xFF,0xFF,5}
};

//Cpu0 Riser type is (3 * X8) & Cpu1 Riser type is (3 * X8)
REPORT_PCIEDIDVID2BMC PcieDeviceToReport_2P_Type4 [PCIEDEVICE_REPORT_MAX] = {
  {0xFF,0xFF,0xFF,0},
  {0x01,0,0,1},
  {0x04,0,0,2},
  {0xFF,0xFF,0xFF,3},
  {0x81,0,0,4},
  {0x85,0,0,5}
};

VOID
GetPciDidVid (
  REPORT_PCIEDIDVID2BMC *Report
  )
{
  UINT32                             PresentStatus;
  UINT32                             CardType;
  UINT8                              Cpu0CardType = 0;
  UINT8                              Cpu1CardType = 0;

  PresentStatus = MmioRead32 (CPLD_BASE_ADDRESS + CPLD_RISER_PRSNT_FLAG);
  CardType = MmioRead32 (CPLD_BASE_ADDRESS + CPLD_RISER2_BOARD_ID);

  // Offset 0x40: Bit7 = 1 CPU0 Riser present
  if ((PresentStatus & CPU0_RISER_PRESENT) != 0) {
    Cpu0CardType = (UINT8) (PresentStatus >> 8);
  }

  // Offset 0x40: Bit6 = 1 CPU1 Riser present
  if ((PresentStatus & CPU1_RISER_PRESENT) != 0) {
    Cpu1CardType = (UINT8)CardType;
  }

  if (OemIsMpBoot ()) {
    if (Cpu0CardType == CPLD_X16_X8_BOARD_ID) {
      if (Cpu1CardType == CPLD_X16_X8_BOARD_ID) {
        (VOID)CopyMem ((VOID *)Report, (VOID *)PcieDeviceToReport_2P_Type1,
                        sizeof (PcieDeviceToReport_2P_Type1));
      } else {
        (VOID)CopyMem ((VOID *)Report, (VOID *)PcieDeviceToReport_2P_Type2,
                        sizeof (PcieDeviceToReport_2P_Type2));
      }
    } else {
      if (Cpu1CardType == CPLD_X16_X8_BOARD_ID) {
        (VOID)CopyMem ((VOID *)Report, (VOID *)PcieDeviceToReport_2P_Type3,
                        sizeof (PcieDeviceToReport_2P_Type3));
      } else {
        (VOID)CopyMem ((VOID *)Report, (VOID *)PcieDeviceToReport_2P_Type4,
                        sizeof (PcieDeviceToReport_2P_Type4));
      }
    }
  } else {
    (VOID)CopyMem ((VOID *)Report, (VOID *)PcieDeviceToReport,
                    sizeof (PcieDeviceToReport));
  }
}


// Right now we only support 1P
BOOLEAN
OemIsSocketPresent (
  UINTN Socket
  )
{
  UINT32 SocketMask = PcdGet32 (PcdSocketMask);
  return (BOOLEAN)((SocketMask & (1 << Socket)) ? TRUE : FALSE);
}


UINTN
OemGetSocketNumber (
  VOID
  )
{
  if(!OemIsMpBoot ()) {
    return 1;
  }

  return MAX_PROCESSOR_SOCKETS;
}


UINTN
OemGetDdrChannel (
  VOID
  )
{
  return MAX_MEMORY_CHANNELS;
}


UINTN
OemGetDimmSlot (
  UINTN Socket,
  UINTN Channel
  )
{
  return MAX_DIMM_PER_CHANNEL;
}


BOOLEAN
OemIsMpBoot (
  VOID
  )
{
  return PcdGet32 (PcdIsMPBoot);
}

VOID
OemLpcInit (
  VOID
  )
{
  LpcInit ();
  return;
}

UINT32
OemIsWarmBoot (
  VOID
  )
{
  return 0;
}

VOID
OemBiosSwitch (
  UINT32 Master
  )
{
  (VOID)Master;
  return;
}

BOOLEAN
OemIsNeedDisableExpanderBuffer (
  VOID
  )
{
  return TRUE;
}

EFI_STATUS
OemSwitchRtcI2cChannelAndLock (
  VOID
  )
{
  UINT8   Temp;
  UINT8   Count;

  for (Count = 0; Count < 100; Count++) {
    // To get the other side's state is idle first
    Temp = ReadCpldReg (CPLD_I2C_SWITCH_FLAG);
    if ((Temp & BIT3) != 0) {
      (VOID) MicroSecondDelay (RTC_DELAY_30_MS);
      // Try 100 times, if BMC has not released the bus, return preemption failed
      if (Count == 99) {
        if (!EfiAtRuntime ()) {
          DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Clear cpu_i2c_rtc_state 100 times fail!\n",
            __FUNCTION__, __LINE__));
        }
        return EFI_DEVICE_ERROR;
      }
      continue;
    }

    // if BMC free the bus, can be set 1 preemption
    Temp = ReadCpldReg (CPLD_I2C_SWITCH_FLAG);
    Temp = Temp | CPU_GET_I2C_CONTROL;
    // CPU occupied RTC I2C State
    WriteCpldReg (CPLD_I2C_SWITCH_FLAG, Temp);
    (VOID) MicroSecondDelay (RTC_DELAY_2_MACROSECOND);
    Temp = ReadCpldReg (CPLD_I2C_SWITCH_FLAG);
    // Is preempt success
    if(CPU_GET_I2C_CONTROL == (Temp & CPU_GET_I2C_CONTROL)) {
      break;
    }
    if (Count == 99) {
      if (!EfiAtRuntime ()) {
        DEBUG((DEBUG_ERROR, "[%a]:[%dL]  Clear cpu_i2c_rtc_state fail !!! \n",
          __FUNCTION__, __LINE__));
      }
      return EFI_DEVICE_ERROR;
    }
    (VOID) MicroSecondDelay (RTC_DELAY_30_MS);
  }

  //Polling BMC RTC I2C status
  for (Count = 0; Count < 100; Count++) {
    Temp = ReadCpldReg (CPLD_I2C_SWITCH_FLAG);
    if ((Temp & BIT3) == 0) {
      return EFI_SUCCESS;
    }
    (VOID) MicroSecondDelay (RTC_DELAY_30_MS);
  }

  //If the BMC occupies the RTC I2C Channel, write back the CPU side is idle
  // or the subsequent BMC will not preempt
  Temp = ReadCpldReg (CPLD_I2C_SWITCH_FLAG);
  Temp = Temp & (~CPU_GET_I2C_CONTROL);
  WriteCpldReg (CPLD_I2C_SWITCH_FLAG, Temp);

  return EFI_NOT_READY;
}

VOID
OemReleaseOwnershipOfRtc (
  VOID
  )
{
  UINT8   Temp;

  Temp = ReadCpldReg (CPLD_I2C_SWITCH_FLAG);
  Temp = Temp & ~CPU_GET_I2C_CONTROL;
  WriteCpldReg (CPLD_I2C_SWITCH_FLAG, Temp);
}
