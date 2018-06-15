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

REPORT_PCIEDIDVID2BMC PcieDeviceToReport[PCIEDEVICE_REPORT_MAX] = {
  {67,0,0,0},
  {225,0,0,3},
  {0xFFFF,0xFFFF,0xFFFF,0xFFFF},
  {0xFFFF,0xFFFF,0xFFFF,0xFFFF}
};

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

  return 2;
}


UINTN
OemGetDdrChannel (
  VOID
  )
{
  return 8;
}


UINTN
OemGetDimmSlot (
  UINTN Socket,
  UINTN Channel
  )
{
  return 2;
}


// Nothing to do for EVB
VOID
OemPostEndIndicator (
  VOID
  )
{
  DEBUG ((DEBUG_ERROR,"M3 release reset CONFIG........."));

  MmioWrite32 (0xd0002180, 0x3);
  MmioWrite32 (0xd0002194, 0xa4);
  MmioWrite32 (0xd0000a54, 0x1);

  MicroSecondDelay (10000);

  MmioWrite32 (0xd0002108, 0x1);
  MmioWrite32 (0xd0002114, 0x1);
  MmioWrite32 (0xd0002120, 0x1);
  MmioWrite32 (0xd0003108, 0x1);

  MicroSecondDelay (500000);
  DEBUG ((DEBUG_ERROR, "Done\n"));
}



VOID
CoreSelectBoot (
  VOID
  )
{
  if (!PcdGet64 (PcdTrustedFirmwareEnable))
  {
    StartupAp ();
  }

  return;
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
