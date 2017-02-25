/** @file
*
*  Copyright (c) 2017 Hisilicon Limited. All rights reserved.
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

Device (\_SB.GED1)
{
  Name(_HID, "ACPI0013")
  Name (_UID, 0)
  Name(_CRS, ResourceTemplate () {
    Interrupt (ResourceConsumer, Level, ActiveHigh, Exclusive)  {178}
  })

  OperationRegion (TMR2, SystemMemory, 0x40080000, 0x10)
  Field (TMR2, AnyAcc, NoLock, Preserve) {
    Offset (0x08),
    CNTL, 32,
    INTC, 32,
  }

  Method (_EVT, 1) {
    Switch (Arg0) {
      Case (178) {
        Store (0x1, INTC)
        Notify (\_SB.ERRD, 0x80)
      }
    }
  }
}

Device (\_SB.ERRD)
{
  Name(_HID, EISAID("PNP0C33"))
  Name (_UID, 0)

  Method (_STA, 0x0, NotSerialized) {
    Return(0xF)
  }
}
