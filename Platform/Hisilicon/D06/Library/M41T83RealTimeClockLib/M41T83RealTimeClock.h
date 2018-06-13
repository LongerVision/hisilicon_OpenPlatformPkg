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

#ifndef __M41T83_REAL_TIME_CLOCK_H__
#define __M41T83_REAL_TIME_CLOCK_H__

#define M41T83_REGADDR_DOTSECONDS       0x00
#define M41T83_REGADDR_SECONDS          0x01
#define M41T83_REGADDR_MINUTES          0x02
#define M41T83_REGADDR_HOURS            0x03
#define M41T83_REGADDR_WEEK_DAY         0x04
#define M41T83_REGADDR_DAY              0x05
#define M41T83_REGADDR_MONTH            0x06
#define M41T83_REGADDR_YEAR             0x07
#define M41T83_REGADDR_ALARM1SEC        0x0E
#define M41T83_REGADDR_ALARM1MIN        0x0D
#define M41T83_REGADDR_ALARM1HOUR       0x0C
#define M41T83_REGADDR_ALARM1DATE       0x0B
#define M41T83_REGADDR_ALARM1MONTH      0x0A

#define M41T83_REGADDR_TIMERCONTROL     0x11

#define M41T83_REGADDR_ALARM2SEC        0x18
#define M41T83_REGADDR_ALARM2MIN        0x17
#define M41T83_REGADDR_ALARM2HOUR       0x16
#define M41T83_REGADDR_ALARM2DATE       0x15
#define M41T83_REGADDR_ALARM2MONTH      0x14

#pragma pack(1)

typedef union {
  struct {
    UINT8 TD0:1;
    UINT8 TD1:1;
    UINT8 RSV:3;
    UINT8 TIE:1;
    UINT8 TITP:1;
    UINT8 TE:1;
  } bits;
  UINT8 u8;
} RTC_M41T83_TIMERCONTROL;

typedef union {
  struct {
    UINT8 MicroSeconds;
  } bits;
  UINT8 u8;
} RTC_M41T83_DOTSECOND;

typedef union {
  struct{
    UINT8 Seconds:7;
    UINT8 ST:1;
  } bits;
  UINT8 u8;
} RTC_M41T83_SECOND;

typedef union {
  struct {
    UINT8 Minutes:7;
    UINT8 Rsv:1;
  } bits;
  UINT8 u8;
} RTC_M41T83_MINUTE;

typedef union {
  struct {
    UINT8 Hours:6;
    UINT8 CB:2;
  } bits;
  UINT8 u8;
} RTC_M41T83_HOUR;

typedef union {
  struct{
    UINT8 Days:3;
    UINT8 Rsv:5;
  } bits;
  UINT8 u8;
} RTC_M41T83_WEEK_DAY;

typedef union {
  struct{
    UINT8 Days:6;
    UINT8 Rsv:2;
  } bits;
  UINT8 u8;
} RTC_M41T83_MONTH_DAY;

typedef union {
  struct {
    UINT8 Months:5;
    UINT8 Rsv:3;
  } bits;
  UINT8 u8;
} RTC_M41T83_MONTH;

typedef union {
  struct {
    UINT8 Years:8;
  } bits;
  UINT8 u8;
} RTC_M41T83_YEAR;

typedef union {
  struct {
    UINT8 Second:7;
    UINT8 RPT11:1;
  } bits;
  UINT8 u8;
} RTC_M41T83_ALARM1SEC;

typedef union {
  struct {
    UINT8 Minute:7;
    UINT8 RPT12:1;
  } bits;
  UINT8 u8;
} RTC_M41T83_ALARM1MIN;

typedef union {
  struct {
    UINT8 Hour:6;
    UINT8 HT:1;
    UINT8 RPT13:1;
  } bits;
  UINT8 u8;
} RTC_M41T83_ALARM1HOUR;

typedef struct {
  RTC_M41T83_DOTSECOND  Addr0;
  RTC_M41T83_SECOND     Addr1;
  RTC_M41T83_MINUTE     Addr2;
  RTC_M41T83_HOUR       Addr3;
  RTC_M41T83_WEEK_DAY   Addr4;
  RTC_M41T83_MONTH_DAY  Addr5;
  RTC_M41T83_MONTH      Addr6;
  RTC_M41T83_YEAR       Addr7;
} RTC_M41T83_TIME;

#pragma pack()

// Define EPOCH (1970-JANUARY-01) in the Julian Date representation
#define EPOCH_JULIAN_DATE                               2440588

// Seconds per unit
#define SEC_PER_MIN                                     ((UINTN)    60)
#define SEC_PER_HOUR                                    ((UINTN)  3600)
#define SEC_PER_DAY                                     ((UINTN) 86400)

#define SEC_PER_MONTH                                   ((UINTN)  2,592,000)
#define SEC_PER_YEAR                                    ((UINTN) 31,536,000)

EFI_LOCK  mRtcLock;

#endif
