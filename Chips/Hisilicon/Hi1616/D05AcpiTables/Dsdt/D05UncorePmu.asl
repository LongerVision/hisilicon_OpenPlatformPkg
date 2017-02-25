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
    Name (_HID, "HISI0202")  // _HID: Hardware ID
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
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x01, 0x01}},
        }
      })
    }

    // L3C Bank 1 for SCL #1
    Device (L3C1) {
      Name (_ADR, 1)
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x02, 0x01}},
        }
      })
    }

    // L3C Bank 2 for SCL #1
    Device (L3C2) {
      Name (_ADR, 2)
      Name (_CID, "HISI0212")
      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x03, 0x01}},
        }
      })
    }

    // L3C Bank 3 for SCL #1
    Device (L3C3) {
      Name (_ADR, 3)
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x04, 0x01}},
        }
      })
    }

    // MN1 for SCL #1
    Device (MN1) {
      Name (_ADR, 4)
      Name (_CID, "HISI0222")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", 0x21},
        }
      })
    }
  }

  // Djtag for CPU die #2 (scl #3)
  Device (DJT1) {
    Name (_HID, "HISI0202")  // _HID: Hardware ID
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
        Package () {"hisilicon,scl-id", 0x03},
		}
    })

    // L3C Bank 0 for SCL #3
    Device (L3C0) {
      Name (_ADR, 0)
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x01, 0x01}},
        }
      })
    }

    // L3C Bank 1 for SCL #3
    Device (L3C1) {
      Name (_ADR, 1)
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x02, 0x01}},
        }
      })
    }

    // L3C Bank 2 for SCL #3
    Device (L3C2) {
      Name (_ADR, 2)
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x03, 0x01}},
        }
      })
    }

    // L3C Bank 3 for SCL #3
    Device (L3C3) {
      Name (_ADR, 3)
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x04, 0x01}},
        }
      })
    }

    // MN1 for SCL #3
    Device (MN1) {
      Name (_ADR, 4)
	   Name (_CID, "HISI0222")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", 0x21},
        }
      })
    }
  }

  // Djtag for CPU die #3 (scl #5)
  Device (DJT2) {
    Name (_HID, "HISI0202")  // _HID: Hardware ID
    Name (_CRS, ResourceTemplate () { // _CRS: Current Resource Settings
      QWordMemory ( // CPU die sysctrl memory region
        ResourceProducer,
        PosDecode,
        MinFixed,
        MaxFixed,
        Cacheable,
        ReadWrite,
        0x0, // Granularity
        0x40040010000, // Min Base Address
        0x4004001FFFF, // Max Base Address
        0x0, // Translate
        0x10000 // Length
      )
    })

    Name (_DSD, Package () {
      ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
      Package () {
        Package () {"hisilicon,scl-id", 0x05}
      }
    })

    // L3C Bank 0 for SCL #5
    Device (L3C0) {
      Name (_ADR, 0)
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x01, 0x01}},
        }
      })
    }

    // L3C Bank 1 for SCL #5
    Device (L3C1) {
      Name (_ADR, 1)
      Name (_CID, "HISI0212")
      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x02, 0x01}},
        }
      })
    }

    // L3C Bank 2 for SCL #5
    Device (L3C2) {
      Name (_ADR, 2)
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x03, 0x01}},
        }
      })
    }

    // L3C Bank 3 for SCL #5
    Device (L3C3) {
      Name (_ADR, 3)
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x04, 0x01}},
        }
      })
    }

    // MN1 for SCL #5
    Device (MN1) {
      Name (_ADR, 4)
      Name (_CID, "HISI0222")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", 0x21},
        }
      })
    }
  }

  // Djtag for CPU die #4 (scl #7)
  Device (DJT3) {
    Name (_HID, "HISI0202")  // _HID: Hardware ID
    Name (_CRS, ResourceTemplate () { // _CRS: Current Resource Settings
      QWordMemory ( // CPU die sysctrl memory region
        ResourceProducer,
        PosDecode,
        MinFixed,
        MaxFixed,
        Cacheable,
        ReadWrite,
        0x0, // Granularity
        0x40060010000, // Min Base Address
        0x4006001FFFF, // Max Base Address
        0x0, // Translate
        0x10000 // Length
      )
    })

    Name (_DSD, Package () {
      ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
      Package () {
        Package () {"hisilicon,scl-id", 0x07}
      }
    })

    // L3C Bank 0 for SCL #7
    Device (L3C0) {
      Name (_ADR, 0)
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x01, 0x01}},
        }
      })
    }

    // L3C Bank 1 for SCL #7
    Device (L3C1) {
      Name (_ADR, 1)
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x02, 0x01}},
        }
      })
    }

    // L3C Bank 2 for SCL #7
    Device (L3C2) {
      Name (_ADR, 2)
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x03, 0x01}},
        }
      })
	}
	
    // L3C Bank 3 for SCL #7
    Device (L3C3) {
      Name (_ADR, 3)
      Name (_CID, "HISI0212")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", Package () {0x04, 0x01}},
        }
      })
    }

    // MN1 for SCL #7
    Device (MN1) {
      Name (_ADR, 4)
      Name (_CID, "HISI0222")

      Name (_DSD, Package () {
        ToUUID("daffd814-6eba-4d8c-8a91-bc9bbf4aa301"),
        Package () {
          Package () {"hisilicon,module-id", 0x21},
        }
      })
    }
  }
}
