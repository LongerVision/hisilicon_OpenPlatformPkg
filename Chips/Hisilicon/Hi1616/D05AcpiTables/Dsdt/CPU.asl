/** @file
  Differentiated System Description Table Fields (DSDT)

  Copyright (c) 2014, ARM Ltd. All rights reserved.<BR>
  Copyright (c) 2015-2016, Hisilicon Limited. All rights reserved.<BR>
  Copyright (c) 2015-2016, Linaro Limited. All rights reserved.<BR>
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
  //
  // A57x16 Processor declaration
  //
  Device(CPU0) {
    Name(_HID, "ACPI0007")
    Name(_UID, 0)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CPU1) {
    Name(_HID, "ACPI0007")
    Name(_UID, 1)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CPU2) {
    Name(_HID, "ACPI0007")
    Name(_UID, 2)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CPU3) {
    Name(_HID, "ACPI0007")
    Name(_UID, 3)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CPU4) {
    Name(_HID, "ACPI0007")
    Name(_UID, 4)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CPU5) {
    Name(_HID, "ACPI0007")
    Name(_UID, 5)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CPU6) {
    Name(_HID, "ACPI0007")
    Name(_UID, 6)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CPU7) {
    Name(_HID, "ACPI0007")
    Name(_UID, 7)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CPU8) {
    Name(_HID, "ACPI0007")
    Name(_UID, 8)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CPU9) {
    Name(_HID, "ACPI0007")
    Name(_UID, 9)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP10) {
    Name(_HID, "ACPI0007")
    Name(_UID, 10)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP11) {
    Name(_HID, "ACPI0007")
    Name(_UID, 11)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP12) {
    Name(_HID, "ACPI0007")
    Name(_UID, 12)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP13) {
    Name(_HID, "ACPI0007")
    Name(_UID, 13)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP14) {
    Name(_HID, "ACPI0007")
    Name(_UID, 14)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP15) {
    Name(_HID, "ACPI0007")
    Name(_UID, 15)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP16) {
    Name(_HID, "ACPI0007")
    Name(_UID, 16)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP17) {
    Name(_HID, "ACPI0007")
    Name(_UID, 17)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP18) {
    Name(_HID, "ACPI0007")
    Name(_UID, 18)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP19) {
    Name(_HID, "ACPI0007")
    Name(_UID, 19)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP20) {
    Name(_HID, "ACPI0007")
    Name(_UID, 20)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP21) {
    Name(_HID, "ACPI0007")
    Name(_UID, 21)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP22) {
    Name(_HID, "ACPI0007")
    Name(_UID, 22)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP23) {
    Name(_HID, "ACPI0007")
    Name(_UID, 23)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP24) {
    Name(_HID, "ACPI0007")
    Name(_UID, 24)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP25) {
    Name(_HID, "ACPI0007")
    Name(_UID, 25)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP26) {
    Name(_HID, "ACPI0007")
    Name(_UID, 26)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP27) {
    Name(_HID, "ACPI0007")
    Name(_UID, 27)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP28) {
    Name(_HID, "ACPI0007")
    Name(_UID, 28)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP29) {
    Name(_HID, "ACPI0007")
    Name(_UID, 29)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP30) {
    Name(_HID, "ACPI0007")
    Name(_UID, 30)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP31) {
    Name(_HID, "ACPI0007")
    Name(_UID, 31)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP32) {
    Name(_HID, "ACPI0007")
    Name(_UID, 32)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP33) {
    Name(_HID, "ACPI0007")
    Name(_UID, 33)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP34) {
    Name(_HID, "ACPI0007")
    Name(_UID, 34)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP35) {
    Name(_HID, "ACPI0007")
    Name(_UID, 35)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP36) {
    Name(_HID, "ACPI0007")
    Name(_UID, 36)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP37) {
    Name(_HID, "ACPI0007")
    Name(_UID, 37)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP38) {
    Name(_HID, "ACPI0007")
    Name(_UID, 38)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP39) {
    Name(_HID, "ACPI0007")
    Name(_UID, 39)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP40) {
    Name(_HID, "ACPI0007")
    Name(_UID, 40)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP41) {
    Name(_HID, "ACPI0007")
    Name(_UID, 41)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP42) {
    Name(_HID, "ACPI0007")
    Name(_UID, 42)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP43) {
    Name(_HID, "ACPI0007")
    Name(_UID, 43)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP44) {
    Name(_HID, "ACPI0007")
    Name(_UID, 44)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP45) {
    Name(_HID, "ACPI0007")
    Name(_UID, 45)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP46) {
    Name(_HID, "ACPI0007")
    Name(_UID, 46)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP47) {
    Name(_HID, "ACPI0007")
    Name(_UID, 47)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP48) {
    Name(_HID, "ACPI0007")
    Name(_UID, 48)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP49) {
    Name(_HID, "ACPI0007")
    Name(_UID, 49)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP50) {
    Name(_HID, "ACPI0007")
    Name(_UID, 50)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP51) {
    Name(_HID, "ACPI0007")
    Name(_UID, 51)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP52) {
    Name(_HID, "ACPI0007")
    Name(_UID, 52)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP53) {
    Name(_HID, "ACPI0007")
    Name(_UID, 53)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP54) {
    Name(_HID, "ACPI0007")
    Name(_UID, 54)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP55) {
    Name(_HID, "ACPI0007")
    Name(_UID, 55)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP56) {
    Name(_HID, "ACPI0007")
    Name(_UID, 56)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP57) {
    Name(_HID, "ACPI0007")
    Name(_UID, 57)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP58) {
    Name(_HID, "ACPI0007")
    Name(_UID, 58)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP59) {
    Name(_HID, "ACPI0007")
    Name(_UID, 59)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP60) {
    Name(_HID, "ACPI0007")
    Name(_UID, 60)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP61) {
    Name(_HID, "ACPI0007")
    Name(_UID, 61)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP62) {
    Name(_HID, "ACPI0007")
    Name(_UID, 62)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
  Device(CP63) {
    Name(_HID, "ACPI0007")
    Name(_UID, 63)
    Method(_STA, 0, NotSerialized)
    {
      Return(0x0F)
    }
  }
}
