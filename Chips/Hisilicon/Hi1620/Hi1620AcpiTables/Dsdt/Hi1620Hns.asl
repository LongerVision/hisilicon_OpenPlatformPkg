/** @file
  Differentiated System Description Table Fields (DSDT)

  Copyright (c) 2014, ARM Ltd. All rights reserved.<BR>
    This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

Scope(_SB)
{
  Device (MDIO) {
    OperationRegion (CLKR, SystemMemory, 0x94000560, 8)
    Field (CLKR, DWordAcc, NoLock, Preserve) {
      CLKE, 1,  // clock enable
      , 31,
      CLKD, 1,  // clode disable
      , 31,
    }
    OperationRegion (RSTR, SystemMemory, 0x94000c40, 8)
    Field (RSTR, DWordAcc, NoLock, Preserve) {
      RSTE, 1,  // reset
      , 31,
      RSTD, 1,  // de-reset
      , 31,
    }

    Name (_HID, "HISI0141")
    Name (_CRS, ResourceTemplate () {
      Memory32Fixed (ReadWrite, 0x940E0000 , 0x10000)
    })

    Method(_RST, 0, Serialized) {
    }
  }

  Device (PRT0) {
    Name (_ADR, 30)
    Name (_DSD, Package () {
      ToUUID ("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
      Package () {
          Package () {"reg", 30},
          Package () {"phy-mode", "mii"},
          Package () {"phy-addr", 30},
          Package () {"mdio-node", Package (){\_SB.MDIO}},
          Package () {"max-speed", 100},
      }
    })
  }

  Device (ETH0)
  {
    Name (_HID, "HISI00C2")
    Name (_CCA, 0) // Cache-coherent controller
    Name (_DSD, Package ()
    {
      ToUUID ("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
             Package ()
      {
        Package () {"phy-id", 0x01410e80},
        Package () {"phy-mode", "mii"},
        Package () {"phy-handle", Package () {\_SB.PRT0}},
      }
    })

    Name(_CRS, ResourceTemplate()
    {
      Memory32Fixed(ReadWrite, 0x95000000, 0x1000)
      Memory32Fixed(ReadWrite, 0x94000000, 0x1000)
    })
  }
}
