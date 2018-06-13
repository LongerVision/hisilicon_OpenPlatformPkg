/** @file

  Copyright (c) 2018, Hisilicon Limited. All rights reserved.<BR>
  Copyright (c) 2018, Linaro Limited. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <Uefi.h>
#include <PiDxe.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/CpldD06.h>
#include <Library/CpldIoLib.h>
#include <Library/DebugLib.h>
#include <Library/I2CLib.h>
#include <Library/IoLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PcdLib.h>
#include <Library/TimerLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Protocol/RealTimeClock.h>
#include "M41T83RealTimeClock.h"

extern I2C_DEVICE gDS3231RtcDevice;

EFI_STATUS
SwitchRtcI2cChannelAndLock (
  VOID
  )
{
  UINT8   Temp;
  UINT8   Count;

  for (Count = 0; Count < 100; Count++) {
    Temp = ReadCpldReg (CPLD_I2C_SWITCH_FLAG);  //To get the other side's state is idle first
    if (0 != (Temp & BIT3)) {
      (VOID) MicroSecondDelay (30000);
      if (99 == Count) {                        //Try 100 times, the other side has not released the bus, return preemption failed
        if (!EfiAtRuntime ()) {
          DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Clear cpu_i2c_rtc_state 100 times fail !!!\n", __FUNCTION__, __LINE__));
        }
        return EFI_DEVICE_ERROR;
      }
      continue;                                 //The other side occupies, continue polling is idle
    }

    Temp = ReadCpldReg (CPLD_I2C_SWITCH_FLAG);  //Each other free, can be set 1 preemption
    Temp = Temp | CPU_GET_I2C_CONTROL;          //bit2 = 1
    WriteCpldReg (CPLD_I2C_SWITCH_FLAG, Temp);  //Come up directly write CPU occupied RTC I2C State
    (VOID) MicroSecondDelay (2);
    Temp = ReadCpldReg (CPLD_I2C_SWITCH_FLAG);  //Whether or not to preempt success
    if(CPU_GET_I2C_CONTROL == (Temp & CPU_GET_I2C_CONTROL)) {
      break;                                    //Preemption Successful exit loop continue
    }
    if (99 == Count) {//Try 100 times, the other side has not released the bus, return preemption failed
      if (!EfiAtRuntime ()) {
        DEBUG((DEBUG_ERROR, "[%a]:[%dL]  Clear cpu_i2c_rtc_state fail !!! \n", __FUNCTION__, __LINE__));
      }
      return EFI_DEVICE_ERROR;
    }
    (VOID) MicroSecondDelay (30000);            //Delay 30ms
  }

  //Polling BMC RTC I2C status
  for (Count = 0; Count < 100; Count++) {
    Temp = ReadCpldReg (CPLD_I2C_SWITCH_FLAG);
    if (0 == (Temp & BIT3)) {
      return EFI_SUCCESS;
    }
    (VOID) MicroSecondDelay (30000);            //Delay 30ms
  }

  //If the BMC occupies the RTC I2C Channel, write back the CPU side is idle or the subsequent BMC will not preempt
  Temp = ReadCpldReg (CPLD_I2C_SWITCH_FLAG);
  Temp = Temp & (~CPU_GET_I2C_CONTROL);         //BIT2 = 0
  WriteCpldReg (CPLD_I2C_SWITCH_FLAG, Temp);

  return EFI_NOT_READY;
}


/**
  Read RTC content through its registers.

  @param  Address   Address offset of RTC data.
  @param  Size      Size of RTC data to read.
  @param  Data      The data of UINT8 type read from RTC.

  @return EFI_STATUS
**/
EFI_STATUS
RtcRead (
  IN  UINT8   Address,
  IN  UINT8   Size,
  OUT UINT8   *Data
  )
{
  EFI_STATUS  Status;

  Status = I2CRead (&gDS3231RtcDevice, Address, Size, Data);
  MicroSecondDelay (1000);
  return Status;
}

/**
  Write RTC through its registers.

  @param  Address   Address offset of RTC data.
  @param  Size      Size of RTC data to write.
  @param  Data      The data of UINT8 type write from RTC.

  @return EFI_STATUS
**/
EFI_STATUS
RtcWrite (
  IN  UINT8   Address,
  IN  UINT8   Size,
  UINT8       *Data
  )
{
  EFI_STATUS  Status;

  Status = I2CWrite(&gDS3231RtcDevice, Address, Size, Data);
  MicroSecondDelay (1000);
  return Status;
}

VOID
ReleaseOwnershipOfRtc (
  VOID
  )
{
  UINT8   Temp;

  Temp = ReadCpldReg (CPLD_I2C_SWITCH_FLAG);
  Temp = Temp & ~CPU_GET_I2C_CONTROL;
  WriteCpldReg (CPLD_I2C_SWITCH_FLAG, Temp);
}


EFI_STATUS
InitializeM41T83 (
  VOID
  )
{
  EFI_STATUS                Status;
  RTC_M41T83_ALARM1HOUR     Alarm1Hour;
  RTC_M41T83_SECOND         Second;
  // Acquire RTC Lock to make access to RTC atomic
  if (!EfiAtRuntime ()) {
    EfiAcquireLock (&mRtcLock);
  }

  Status = I2CInit (gDS3231RtcDevice.Socket, gDS3231RtcDevice.Port, Normal);
  MicroSecondDelay (1000);
  if (EFI_ERROR (Status)) {
    if (!EfiAtRuntime ()) {
      EfiReleaseLock (&mRtcLock);
    }
    return Status;
  }

  Status = SwitchRtcI2cChannelAndLock ();
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Status : %r\n", __FUNCTION__, __LINE__, Status));
    if (!EfiAtRuntime ()) {
      EfiReleaseLock (&mRtcLock);
    }
    return Status;
  }

  MicroSecondDelay(1000);

  // Set ST at Power up to clear Oscillator fail detection(OF)
  Status = RtcRead (M41T83_REGADDR_SECONDS, 1, &Second.u8);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Status : %r\n", __FUNCTION__, __LINE__, Status));
  }
  Second.bits.ST= 1;
  Status = RtcWrite (M41T83_REGADDR_SECONDS, 1, &Second.u8);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Status : %r\n", __FUNCTION__, __LINE__, Status));
    goto Exit;
  }
  Status = RtcRead (M41T83_REGADDR_SECONDS, 1, &Second.u8);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Status : %r\n", __FUNCTION__, __LINE__, Status));
  }
  Second.bits.ST= 0;
  Status = RtcWrite (M41T83_REGADDR_SECONDS, 1, &Second.u8);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Status : %r\n", __FUNCTION__, __LINE__, Status));
    goto Exit;
  }

  // Clear HT bit to enanle write to the RTC registers (addresses 0-7)
  Status = RtcRead (M41T83_REGADDR_ALARM1HOUR, 1, &Alarm1Hour.u8);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Status : %r\n", __FUNCTION__, __LINE__, Status));
  }
  Alarm1Hour.bits.HT = 0;
  Status = RtcWrite (M41T83_REGADDR_ALARM1HOUR, 1, &Alarm1Hour.u8);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Status : %r\n", __FUNCTION__, __LINE__, Status));
    goto Exit;
  }

Exit:
  // Release RTC Lock.
  ReleaseOwnershipOfRtc ();
  if (!EfiAtRuntime ()) {
    EfiReleaseLock (&mRtcLock);
  }
  return Status;
}

BOOLEAN
IsLeapYear (
  IN EFI_TIME   *Time
  )
{
  if (Time->Year % 4 == 0) {
    if (Time->Year % 100 == 0) {
      if (Time->Year % 400 == 0) {
        return TRUE;
      } else {
        return FALSE;
      }
    } else {
      return TRUE;
    }
  } else {
    return FALSE;
  }
}

BOOLEAN
DayValid (
  IN  EFI_TIME  *Time
  )
{
  INTN  DayOfMonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  if (Time->Day < 1 ||
      Time->Day > DayOfMonth[Time->Month - 1] ||
      (Time->Month == 2 && (!IsLeapYear (Time) && Time->Day > 28))
     ) {
    return FALSE;
  }

  return TRUE;
}

BOOLEAN TimeValid(
  IN  EFI_TIME  *Time
  )
{
  // Check the input parameters are within the range specified by UEFI
  if ((Time->Year   < 2000) ||
      (Time->Year   > 2399) ||
      (Time->Month  < 1   ) ||
      (Time->Month  > 12  ) ||
      (!DayValid (Time)   ) ||
      (Time->Hour   > 23  ) ||
      (Time->Minute > 59  ) ||
      (Time->Second > 59  ) ||
      (Time->Nanosecond > 999999999) ||
      (!(Time->TimeZone == EFI_UNSPECIFIED_TIMEZONE || (Time->TimeZone >= -1440 && Time->TimeZone <= 1440))) ||
      (Time->Daylight & (~(EFI_TIME_ADJUST_DAYLIGHT | EFI_TIME_IN_DAYLIGHT)))
  ) {
    return FALSE;
  }

  return TRUE;
}


/**
  Sets the current local time and date information.

  @param  Time                  A pointer to the current time.

  @retval EFI_SUCCESS           The operation completed successfully.
  @retval EFI_INVALID_PARAMETER A time field is out of range.
  @retval EFI_DEVICE_ERROR      The time could not be set due due to hardware error.

**/
EFI_STATUS
EFIAPI
LibSetTime (
  IN  EFI_TIME                *Time
  )
{
  EFI_STATUS                  Status = EFI_SUCCESS;
  RTC_M41T83_TIME             BcdTime;
  UINT16                      CenturyBase = 2000;
  UINTN                       LineNum = 0;

  if (NULL == Time) {
    return EFI_INVALID_PARAMETER;
  }

  if (!TimeValid (Time)) {
    if (!EfiAtRuntime ()) {
      DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Status : %r\n", __FUNCTION__, __LINE__, Status));
      DEBUG ((
        DEBUG_ERROR, "Now RTC Time is : %04d-%02d-%02d %02d:%02d:%02d\n",
        Time->Year, Time->Month, Time->Day, Time->Hour, Time->Minute, Time->Second
      ));
    }
    return EFI_INVALID_PARAMETER;
  }

  Status = SwitchRtcI2cChannelAndLock ();
  if (EFI_ERROR (Status)) {
    return Status;
  }
  (VOID) MicroSecondDelay (1000);

  SetMem (&BcdTime, sizeof (RTC_M41T83_TIME), 0);

  // Acquire RTC Lock to make access to RTC atomic
  if (!EfiAtRuntime ()) {
    EfiAcquireLock (&mRtcLock);
  }

  BcdTime.Addr1.bits.Seconds  = DecimalToBcd8 (Time->Second);
  BcdTime.Addr2.bits.Minutes  = DecimalToBcd8 (Time->Minute);
  BcdTime.Addr3.bits.Hours    = DecimalToBcd8 (Time->Hour);
  BcdTime.Addr5.bits.Days     = DecimalToBcd8 (Time->Day);
  BcdTime.Addr6.bits.Months   = DecimalToBcd8 (Time->Month);
  BcdTime.Addr7.bits.Years    = DecimalToBcd8 (Time->Year % 100);
  BcdTime.Addr3.bits.CB       = (Time->Year - CenturyBase) / 100 % 10;

  Status = RtcWrite (M41T83_REGADDR_DOTSECONDS,  1, &BcdTime.Addr0.u8);
  if (EFI_ERROR (Status)) {
    LineNum = __LINE__;
    goto Exit;
  }
  Status = RtcWrite (M41T83_REGADDR_SECONDS,     1, &BcdTime.Addr1.u8);
  if (EFI_ERROR (Status)) {
    LineNum = __LINE__;
    goto Exit;
  }
  Status = RtcWrite (M41T83_REGADDR_MINUTES,     1, &BcdTime.Addr2.u8);
  if (EFI_ERROR (Status)) {
    LineNum = __LINE__;
    goto Exit;
  }
  Status = RtcWrite (M41T83_REGADDR_HOURS,       1, &BcdTime.Addr3.u8);
  if (EFI_ERROR (Status)) {
    LineNum = __LINE__;
    goto Exit;
  }
  Status = RtcWrite (M41T83_REGADDR_DAY,         1, &BcdTime.Addr5.u8);
  if (EFI_ERROR (Status)) {
    LineNum = __LINE__;
    goto Exit;
  }
  Status = RtcWrite (M41T83_REGADDR_MONTH,       1, &BcdTime.Addr6.u8);
  if (EFI_ERROR (Status)) {
    LineNum = __LINE__;
    goto Exit;
  }
  Status = RtcWrite (M41T83_REGADDR_YEAR,        1, &BcdTime.Addr7.u8);
  if (EFI_ERROR (Status)) {
    LineNum = __LINE__;
    goto Exit;
  }

Exit:
  ReleaseOwnershipOfRtc ();
  // Release RTC Lock.
  if (!EfiAtRuntime ()) {
    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Status : %r\n", __FUNCTION__, LineNum, Status));
    }
    EfiReleaseLock (&mRtcLock);
  }
  return Status;
}


/**
  Returns the current time and date information, and the time-keeping capabilities
  of the hardware platform.

  @param  Time                   A pointer to storage to receive a snapshot of the current time.
  @param  Capabilities           An optional pointer to a buffer to receive the real time clock
                                 device's capabilities.

  @retval EFI_SUCCESS            The operation completed successfully.
  @retval EFI_INVALID_PARAMETER  Time is NULL.
  @retval EFI_DEVICE_ERROR       The time could not be retrieved due to hardware error.
  @retval EFI_SECURITY_VIOLATION The time could not be retrieved due to an authentication failure.
**/
EFI_STATUS
EFIAPI
LibGetTime (
  OUT EFI_TIME                *Time,
  OUT EFI_TIME_CAPABILITIES   *Capabilities
  )
{
  EFI_STATUS                  Status = EFI_SUCCESS;
  RTC_M41T83_TIME             BcdTime;
  UINT16                      CenturyBase = 2000;
  UINTN                       LineNum = 0;
  BOOLEAN                     IsTimeInvalid = FALSE;
  UINT8                       TimeTemp[7] = {0};

  // Ensure Time is a valid pointer
  if (NULL == Time) {
    return EFI_INVALID_PARAMETER;
  }

  Status = SwitchRtcI2cChannelAndLock ();
  if (EFI_ERROR (Status)) {
    return Status;
  }

  MicroSecondDelay(1000);

  SetMem (&BcdTime, sizeof (RTC_M41T83_TIME), 0);
  SetMem (Time    , sizeof (EFI_TIME)       , 0);

  // Acquire RTC Lock to make access to RTC atomic
  if (!EfiAtRuntime ()) {
    EfiAcquireLock (&mRtcLock);
  }

  Status = RtcRead (M41T83_REGADDR_SECONDS, 7, TimeTemp);
  if (EFI_ERROR (Status)) {
    LineNum = __LINE__;
    goto Exit;
  }

  BcdTime.Addr1.u8 = TimeTemp[0];  //SECONDS
  BcdTime.Addr2.u8 = TimeTemp[1];  //MINUTES
  BcdTime.Addr3.u8 = TimeTemp[2];  //HOURS
  BcdTime.Addr5.u8 = TimeTemp[4];  //DAY
  BcdTime.Addr6.u8 = TimeTemp[5];  //MONTH
  BcdTime.Addr7.u8 = TimeTemp[6];  //Year

  Time->Year        = BcdToDecimal8 (BcdTime.Addr7.bits.Years);
  Time->Year       += CenturyBase + BcdTime.Addr3.bits.CB * 100;
  Time->Month       = BcdToDecimal8 (BcdTime.Addr6.bits.Months);
  Time->Day         = BcdToDecimal8 (BcdTime.Addr5.bits.Days);
  Time->Hour        = BcdToDecimal8 (BcdTime.Addr3.bits.Hours);
  Time->Minute      = BcdToDecimal8 (BcdTime.Addr2.bits.Minutes);
  Time->Second      = BcdToDecimal8 (BcdTime.Addr1.bits.Seconds);
  Time->TimeZone    = EFI_UNSPECIFIED_TIMEZONE;

  if (!TimeValid (Time)) {
      Status = EFI_DEVICE_ERROR;
      LineNum = __LINE__;
      IsTimeInvalid = TRUE;
      goto Exit;
  }

Exit:
  ReleaseOwnershipOfRtc ();
  // Release RTC Lock.
  if (!EfiAtRuntime ()) {
    if (EFI_ERROR (Status)) {
      if (IsTimeInvalid == TRUE) {
        DEBUG((DEBUG_ERROR, "%a(%d) Time invalid.\r\n",__FUNCTION__, LineNum));
      } else {
        DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Status : %r\n", __FUNCTION__, LineNum, Status));
      }
    }
    EfiReleaseLock (&mRtcLock);
  }
  return Status;
}


/**
  Returns the current wakeup alarm clock setting.

  @param  Enabled               Indicates if the alarm is currently enabled or disabled.
  @param  Pending               Indicates if the alarm signal is pending and requires acknowledgement.
  @param  Time                  The current alarm setting.

  @retval EFI_SUCCESS           The alarm settings were returned.
  @retval EFI_INVALID_PARAMETER Any parameter is NULL.
  @retval EFI_DEVICE_ERROR      The wakeup time could not be retrieved due to a hardware error.

**/
EFI_STATUS
EFIAPI
LibGetWakeupTime (
  OUT BOOLEAN     *Enabled,
  OUT BOOLEAN     *Pending,
  OUT EFI_TIME    *Time
  )
{
  // Not a required feature
  return EFI_UNSUPPORTED;
}


/**
  Sets the system wakeup alarm clock time.

  @param  Enabled               Enable or disable the wakeup alarm.
  @param  Time                  If Enable is TRUE, the time to set the wakeup alarm for.

  @retval EFI_SUCCESS           If Enable is TRUE, then the wakeup alarm was enabled. If
                                Enable is FALSE, then the wakeup alarm was disabled.
  @retval EFI_INVALID_PARAMETER A time field is out of range.
  @retval EFI_DEVICE_ERROR      The wakeup time could not be set due to a hardware error.
  @retval EFI_UNSUPPORTED       A wakeup timer is not supported on this platform.

**/
EFI_STATUS
EFIAPI
LibSetWakeupTime (
  IN BOOLEAN      Enabled,
  OUT EFI_TIME    *Time
  )
{
  // Not a required feature
  return EFI_UNSUPPORTED;
}


/**
  This is the declaration of an EFI image entry point. This can be the entry point to an application
  written to this specification, an EFI boot service driver, or an EFI runtime driver.

  @param  ImageHandle           Handle that identifies the loaded image.
  @param  SystemTable           System Table for this image.

  @retval EFI_SUCCESS           The operation completed successfully.

**/
EFI_STATUS
EFIAPI
LibRtcInitialize (
  IN EFI_HANDLE                            ImageHandle,
  IN EFI_SYSTEM_TABLE                      *SystemTable
  )
{
  EFI_STATUS    Status = EFI_SUCCESS;
  EFI_TIME      EfiTime;

  EfiInitializeLock (&mRtcLock, TPL_CALLBACK);

  // Setup the setters and getters
  gRT->GetTime       = LibGetTime;
  gRT->SetTime       = LibSetTime;
  gRT->GetWakeupTime = LibGetWakeupTime;
  gRT->SetWakeupTime = LibSetWakeupTime;

  Status = InitializeM41T83 ();
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL] Status : %r\nRTC M41T83 Init Failed !!!\n",
            __FUNCTION__, __LINE__, Status));
    /*
     * Returning ERROR on failure of RTC initilization will cause the system to hang up.
     * So we add some debug message to indecate the RTC initilization failed,
     * and continue without returning with error to avoid system hanging up.
     *
     *return Status;
     */
  }

  LibGetTime (&EfiTime, NULL);
  if (!TimeValid (&EfiTime)) {
    EfiTime.Year    = 2015;
    EfiTime.Month   = 1;
    EfiTime.Day     = 1;
    EfiTime.Hour    = 0;
    EfiTime.Minute  = 0;
    EfiTime.Second  = 0;
    Status = LibSetTime (&EfiTime);
    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "[%a]:[%dL] RTC settime Status : %r\n", __FUNCTION__, __LINE__, Status));
    }
  }

  DEBUG ((
    DEBUG_ERROR, "Now RTC Time is : %04d-%02d-%02d %02d:%02d:%02d\n",
    EfiTime.Year, EfiTime.Month, EfiTime.Day, EfiTime.Hour, EfiTime.Minute, EfiTime.Second
    ));
    /*
     * Returning ERROR on failure of RTC initilization will cause the system to hang up.
     * So we add some debug message to indecate the RTC initilization failed,
     * and return success to avoid system hanging up.
     */
  return EFI_SUCCESS;
}
