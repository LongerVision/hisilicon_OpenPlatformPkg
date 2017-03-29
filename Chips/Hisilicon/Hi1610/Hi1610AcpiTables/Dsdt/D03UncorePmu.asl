/** @file
  Differentiated System Description Table Fields (DSDT)

  Copyright (c) 2017, ARM Ltd. All rights reserved.<BR>
  Copyright (c) 2017, Hisilicon Limited. All rights reserved.<BR>
  Copyright (c) 2017, Linaro Limited. All rights reserved.<BR>
    This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

  Based on the files under ArmPlatformPkg/ArmJunoPkg/AcpiTables/

**/

Scope(_SB) {
  // Djtag for CPU die #1 (scl #1)
  Device (DJT0) {
    Name (_HID, "HISI0201")  // _HID: Hardware ID
    Name (_CRS, ResourceTemplate () { // _CRS: Current Resource Settings
      QWordMemory ( // CPU die sysctrl memory region
        ResourceProducer,
        PosDecode,
        MinFixed,
        MaxFixed,
        Cacheable,
        ReadWrite,
        0x0, // Granularity
        0x40010000, // Min Base Address
        0x4001FFFF, // Max Base Address
        0x0, // Translate
        0x10000 // Length
      )
    })

    Name (_DSD, Package () {
      ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
      Package () {
        Package () {"hisilicon,scl-id", 0x01}
      }
    })

    // L3C Bank 0 for SCL #1
    Device (L3C0) {
      Name (_ADR, 0)
      Name (_CID, "HISI0211")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x04, 0x02}},
		}
      })
    }

    // L3C Bank 1 for SCL #1
    Device (L3C1) {
      Name (_ADR, 1)
      Name (_CID, "HISI0211")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x04, 0x04}},
        }
      })
    }

    // L3C Bank 2 for SCL #1
    Device (L3C2) {
      Name (_ADR, 2)
      Name (_CID, "HISI0211")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x04, 0x01}},
        }
      })
    }

    // L3C Bank 3 for SCL #1
    Device (L3C3) {
      Name (_ADR, 3)
      Name (_CID, "HISI0211")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x04, 0x08}},
        }
      })
    }

    // MN1 for SCL #1
    Device (MN1) {
      Name (_ADR, 4)
      Name (_CID, "HISI0221")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", 0xb},
        }
      })
    }
  }

  // Djtag for CPU die #2 (scl #2)
  Device (DJT1) {
    Name (_HID, "HISI0201")  // _HID: Hardware ID
    Name (_CRS, ResourceTemplate () { // _CRS: Current Resource Settings
      QWordMemory ( // CPU die sysctrl memory region
        ResourceProducer,
        PosDecode,
        MinFixed,
        MaxFixed,
        Cacheable,
        ReadWrite,
        0x0, // Granularity
        0x60010000, // Min Base Address
        0x6001FFFF, // Max Base Address
        0x0, // Translate
        0x10000 // Length
      )
    })

    Name (_DSD, Package () {
      ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
      Package () {
        Package () {"hisilicon,scl-id", 0x02},
      }
    })

    // L3C Bank 0 for SCL #2
    Device (L3C0) {
      Name (_ADR, 0)
      Name (_CID, "HISI0211")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x04, 0x02}},
        }
      })
    }

    // L3C Bank 1 for SCL #2
    Device (L3C1) {
      Name (_ADR, 1)
      Name (_CID, "HISI0211")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x04, 0x04}},
        }
      })
    }

    // L3C Bank 2 for SCL #2
    Device (L3C2) {
      Name (_ADR, 2)
      Name (_CID, "HISI0211")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x04, 0x01}},
        }
      })
    }

    // L3C Bank 3 for SCL #2
    Device (L3C3) {
      Name (_ADR, 3)
      Name (_CID, "HISI0211")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x04, 0x08}},
        }
      })
    }

    // MN1 for SCL #2
    Device (MN1) {
      Name (_ADR, 4)
      Name (_CID, "HISI0221")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", 0xb},
        }
      })
    }
  }

  // DDRC Channel 0 for CPU die #1 (scl #1)
  Device (DDR0) {
    Name (_HID, "HISI0231")  // _HID: Hardware ID
    Name (_UID, 0)  // _UID: Unique ID
    Name (_CRS, ResourceTemplate () { // _CRS: Current Resource Settings
      QWordMemory (
        ResourceProducer,
        PosDecode,
        MinFixed,
        MaxFixed,
        NonCacheable,
        ReadWrite,
        0x0, // Granularity
        0x40348000, // Min Base Address
        0x40348FFF, // Max Base Address
        0x0, // Translate
        0x1000 // Length
      )
    })

    Name (_DSD, Package () {
      ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
      Package () {
        Package () {"hisilicon,scl-id", 0x01},
        Package () {"hisilicon,ch-id", 0x00},
      }
    })

    Method (_STA, 0x0, NotSerialized)
    {
      Return (0xf)
    }
  }

  // DDRC Channel 1 for CPU die #1 (scl #1)
  Device (DDR1) {
    Name (_HID, "HISI0231")  // _HID: Hardware ID
    Name (_UID, 1)  // _UID: Unique ID
    Name (_CRS, ResourceTemplate () { // _CRS: Current Resource Settings
      QWordMemory (
        ResourceProducer,
        PosDecode,
        MinFixed,
        MaxFixed,
        NonCacheable,
        ReadWrite,
        0x0, // Granularity
        0x40358000, // Min Base Address
        0x40358FFF, // Max Base Address
        0x0, // Translate
        0x1000 // Length
      )
    })

    Name (_DSD, Package () {
      ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
      Package () {
        Package () {"hisilicon,scl-id", 0x01},
        Package () {"hisilicon,ch-id", 0x01},
      }
    })

    Method (_STA, 0x0, NotSerialized)
    {
      Return (0xf)
    }
  }

  // DDRC Channel 0 for CPU die #2 (scl #2)
  Device (DDR2) {
    Name (_HID, "HISI0231")  // _HID: Hardware ID
    Name (_UID, 2)  // _UID: Unique ID
    Name (_CRS, ResourceTemplate () { // _CRS: Current Resource Settings
      QWordMemory (
        ResourceProducer,
        PosDecode,
        MinFixed,
        MaxFixed,
        NonCacheable,
        ReadWrite,
        0x0, // Granularity
        0x60348000, // Min Base Address
        0x60348FFF, // Max Base Address
        0x0, // Translate
        0x1000 // Length
      )
    })

    Name (_DSD, Package () {
      ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
      Package () {
        Package () {"hisilicon,scl-id", 0x02},
        Package () {"hisilicon,ch-id", 0x00},
      }
    })

    Method (_STA, 0x0, NotSerialized)
    {
      Return (0xf)
    }
  }

  // DDRC Channel 1 for CPU die #2 (scl #2)
  Device (DDR3) {
    Name (_HID, "HISI0231")  // _HID: Hardware ID
    Name (_UID, 3)  // _UID: Unique ID
    Name (_CRS, ResourceTemplate () { // _CRS: Current Resource Settings
      QWordMemory (
        ResourceProducer,
        PosDecode,
        MinFixed,
        MaxFixed,
        NonCacheable,
        ReadWrite,
        0x0, // Granularity
        0x60358000, // Min Base Address
        0x60358FFF, // Max Base Address
        0x0, // Translate
        0x1000 // Length
      )
    })

    Name (_DSD, Package () {
      ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
      Package () {
        Package () {"hisilicon,scl-id", 0x02},
        Package () {"hisilicon,ch-id", 0x01},
      }
    })

    Method (_STA, 0x0, NotSerialized)
    {
      Return (0xf)
    }
  }
}
