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
Device (\_SB.GED2)
{
  Name (_HID, "ACPI0013")
  Name (_UID, 2) //Third instance of this controller on the platform
  Name (_CRS, ResourceTemplate ()
  {
    Interrupt(ResourceConsumer, Level, ActiveHigh, Exclusive) {129}// GICV num
  })

  OperationRegion (GIO2, SystemMemory, 0x94100000, 0x50)
  Field (GIO2, AnyAcc, NoLock, Preserve)
  {
    Offset (0x34),
           GIOM, 32,
  }

         Method (_EVT, 1)   // Handle all ACPI Events signaled by GPIO Controller GED2
  {
    Switch (Arg0)  // INT number
    {
      Case (129)
      {
        Store (0x1, GIOM)  // mask int, may need read and
        Notify (\_SB.ERRD, 0x80)
      }
    }
  } //End of Method
}

Device (\_SB.ERRD)
{
  Name (_HID, EISAID("PNP0C33"))
  Name (_UID, 0)
  Method (_STA, 0x0, NotSerialized)
  {
    Return(0xF)
  }
}

Name(PWCP, Zero) // Platform-Wide Capability value.

Scope (\_SB)
{
  Method (_OSC, 4)
  {
    // Create DWord-adressable for Arg3 First DWORD.
    CreateDWordField(Arg3, 0, CDW1)

    // Check for proper UUID
    If (LEqual(Arg0, ToUUID("0811B06E-4A27-44F9-8D60-3CBBC22E7B48")))
    {
      // Create DWord-adressable fields from the Capabilities Buffer
      CreateDWordField (Arg3, 4, TPD2)

      // Save Capabilities DWord2
      Store (TPD2, PWCP)

      // Set Bit[4]: APEI Support
      Or (PWCP, 0x10, PWCP)

      If (LNotEqual(Arg1, One))   // Unknown revision
      {
        Or (CDW1, 0x08, CDW1)
      }

      // Update DWORD2 in the buffer
      Store (PWCP, TPD2)

      Return (Arg3)
    }
    ElseIf (LEqual(Arg0, ToUUID("ed855e0c-6c90-47bf-a62a-26de0fc5ad5c")))   // Check for WHEA GUID
    {
      CreateDWordField (Arg3, 4, TPD3)

      Or (TPD3, 0x10, TPD3)   //Set Bit[4]: APEI support.

      If (LNotEqual(Arg1, One))   // Unknown revision
      {
        Or (CDW1, 0x08, CDW1)
      }

      return (Arg3)
    }
    Else
    {
      Or (CDW1, 4, CDW1) // Unrecognized UUID
      Return (Arg3)
    }
  } // End _OSC
}
