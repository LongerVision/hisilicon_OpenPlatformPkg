/** @file
  Differentiated System Description Table Fields (DSDT)

  Copyright (c) 2014, ARM Ltd. All rights reserved.<BR>
  Copyright (c) 2018, Hisilicon Limited. All rights reserved.<BR>
  Copyright (c) 2015, Linaro Limited. All rights reserved.<BR>
    This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

  Based on the files under ArmPlatformPkg/ArmJunoPkg/AcpiTables/

**/

Scope(_SB)
{
  Device(RDE0) {
    Name(_HID, "HISI0201")
    Name(_UID, 0)
    Name(_CCA, 1)
    Name (_CRS, ResourceTemplate ()  {
      //Memory32Fixed (ReadWrite, 0x602E0000, 0x10000)
      QWordMemory (
        ResourceConsumer,
        ,
        MinFixed,
        MaxFixed,
        NonCacheable,
        ReadWrite,
        0x0,
        0x209000000,
        0x209ffffff,
        0x0,
        0x01000000
      )

      Interrupt (ResourceConsumer, Edge, ActiveHigh, Exclusive, 0, "\\_SB.MBI2")
      { 586,587,588,589,590,591,592,593,594,595,596,597,598,599,600,601,
        602,603,604,605,606,607,608,609,610,611,612,613,614,615,616,617
      }
    })
  }
}
