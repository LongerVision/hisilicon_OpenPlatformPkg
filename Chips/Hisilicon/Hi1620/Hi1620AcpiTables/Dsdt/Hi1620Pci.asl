/** @file
*
*  Copyright (c) 2011-2015, ARM Limited. All rights reserved.
*  Copyright (c) 2017, Hisilicon Limited. All rights reserved.
*  Copyright (c) 2017, Linaro Limited. All rights reserved.
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
*  Based on the files under ArmPlatformPkg/ArmJunoPkg/AcpiTables/
*
**/

//#include "ArmPlatform.h"
Scope(_SB)
{
  Device (PCI0)
  {
    // PCI0 indicate host bridge 0
    Name (_HID, "PNP0A08")                     // PCI Express Root Bridge
    Name (_UID, 0)
    Name (_CID, "PNP0A03")                     // Compatible PCI Root Bridge, Compatible ID
    Name (_SEG, 0)                             // Segment of this Root complex
    Name (_BBN, 0x0)                           // Base Bus Number
    Name (_CCA, 1)                             // cache coherence attribute

    Name (_PRT, Package ()
    {
      // INTx configure for RP0, whoes device number is 0
      // For ESL/FPGA debug, we should modify this according to
      // specific hardware configuration.
      Package () {0xFFFF, 0, 0, 640},      // INT_A
      Package () {0xFFFF, 1, 0, 641},      // INT_B
      Package () {0xFFFF, 2, 0, 642},      // INT_C
      Package () {0xFFFF, 3, 0, 643},      // INT_D

      // This is an example of RP1 INTx configure. Adding or not
      // adding RPx INTx configure deponds on hardware board topology,
      // if UEFI enables RPx, RPy, RPz... related INTx configure
      // should be added
      Package () {0x8FFFF, 0, 0, 640},      // INT_A
      Package () {0x8FFFF, 1, 0, 641},      // INT_B
      Package () {0x8FFFF, 2, 0, 642},      // INT_C
      Package () {0x8FFFF, 3, 0, 643},      // INT_D

      Package () {0xCFFFF, 0, 0, 640},      // INT_A
      Package () {0xCFFFF, 1, 0, 641},      // INT_B
      Package () {0xCFFFF, 2, 0, 642},      // INT_C
      Package () {0xCFFFF, 3, 0, 643},      // INT_D

      Package () {0x10FFFF, 0, 0, 640},      // INT_A
      Package () {0x10FFFF, 1, 0, 641},      // INT_B
      Package () {0x10FFFF, 2, 0, 642},      // INT_C
      Package () {0x10FFFF, 3, 0, 643},      // INT_D

      Package () {0x11FFFF, 0, 0, 640},      // INT_A
      Package () {0x11FFFF, 1, 0, 641},      // INT_B
      Package () {0x11FFFF, 2, 0, 642},      // INT_C
      Package () {0x11FFFF, 3, 0, 643}       // INT_D
    })

    Method (_CRS, 0, Serialized)             // Root complex resources, _CRS: current resource setting
    {
      // Method is defined in 19.6.82 in ACPI 6.0 spec
      Name (RBUF, ResourceTemplate ()        // Name: 19.6.87, ResourceTemplate: 19.6.111,
      {
        // 19.3.3 in ACPI 6.0 spec
        WordBusNumber (                      // Bus numbers assigned to this root,
          // wordBusNumber: 19.6.144
          ResourceProducer,
          MinFixed,
          MaxFixed,
          PosDecode,
          0,                                 // AddressGranularity
          0x00,                              // AddressMinimum - Minimum Bus Number
          0x3f,                              // AddressMaximum - Maximum Bus Number
          0,                                 // AddressTranslation - Set to 0
          0x40                               // RangeLength - Number of Busses
        )
        QWordMemory (                        // 64-bit prefetch BAR windows
          ResourceProducer,
          PosDecode,
          MinFixed,
          MaxFixed,
          Prefetchable,
          ReadWrite,
          0x0,                               // Granularity
          0x80000000000,                     // Min Base Address pci address
          0x83fffffffff,                     // Max Base Address
          0x0,                               // Translate
          0x4000000000                       // Length, 256G
        )
        QWordMemory (                        // 32-bit non-prefetch BAR windows
          ResourceProducer,
          PosDecode,
          MinFixed,
          MaxFixed,
          Cacheable,
          ReadWrite,
          0x0,                               // Granularity
          0xe0000000,                        // Min Base Address pci address
          0xe7feffff,                        // Max Base Address
          0x0,                               // Translate
          0x7ff0000                          // Length, 128M - 64K
        )
        QWordIO (
          ResourceProducer,
          MinFixed,
          MaxFixed,
          PosDecode,
          EntireRange,
          0x0,                               // Granularity
          0x0,                               // Min Base Address
          0xffff,                            // Max Base Address
          0xe7ff0000,                        // Translate
          0x10000                            // Length, 64K
        )
      })                                      // Name(RBUF)
      Return (RBUF)
    }                                         // Method(_CRS), this method return RBUF!

    //
    // OS Control Handoff
    //
    Name(SUPP, Zero) // PCI _OSC Support Field value
    Name(CTRL, Zero) // PCI _OSC Control Field value

    /*
    See [1] 6.2.10, [2] 4.5
    */

    Method(_OSC, 4)
    {
      // Check for proper UUID
      If(LEqual(Arg0, ToUUID("33DB4D5B-1FF7-401C-9657-7441C03DD766")))
      {
        // Create DWord-adressable fields from the Capabilities Buffer
        CreateDWordField(Arg3, 0, CDW1)
        CreateDWordField(Arg3, 4, CDW2)
        CreateDWordField(Arg3, 8, CDW3)

        // Save Capabilities DWord2 & 3
        Store(CDW2, SUPP)
        Store(CDW3, CTRL)

        // Only allow native hot plug control if OS supports:
        //  ASPM
        //  Clock PM
        //  MSI/MSI-X
        If(LNotEqual(And(SUPP, 0x16), 0x16))
        {
          And(CTRL, 0x1E, CTRL) // Mask bit 0 (and undefined bits)
        }

        // Always allow native PME, AER (no dependencies)

        // Never allow SHPC (no SHPC controller in this system)
        And(CTRL, 0x1D, CTRL)

        If(LNotEqual(Arg1, One))    // Unknown revision
        {
          Or(CDW1, 0x08, CDW1)
        }

        If(LNotEqual(CDW3, CTRL))   // Capabilities bits were masked
        {
          Or(CDW1, 0x10, CDW1)
        }

        // Update DWORD3 in the buffer
        Store(CTRL, CDW3)
        Return(Arg3)
      }
      Else
      {
        Or(CDW1, 4, CDW1) // Unrecognized UUID
        Return(Arg3)
      }
    } // End _OSC

    Method (_HPX, 0) {
      Return (Package(2) {
        Package(6) {    // PCI Setting Record
          0x00,         // Type 0
          0x01,         // Revision 1
          0x08,         // CacheLineSize in DWORDS
          0x40,         // LatencyTimer in PCI clocks
          0x01,         // Enable SERR (Boolean)
          0x01          // Enable PERR (Boolean)
          },
        Package(18) {   // PCI-X Setting Record
          0x02,         // Type 2
          0x01,         // Revision 1
          0xFFFFFFFF,   // Uncorrectable Error Mask Register AND Mask, Keep ->1
          0x00000000,   // Uncorrectable Error Mask Register OR Mask, keep ->0
          0xFFFFFFFF,   // Uncorrectable Error Severity Register AND Mask
          0x00000000,   // Uncorrectable Error Severity Register OR Mask
          0xFFFFFFFF,   // Correctable Error Mask Register AND Mask
          0x00000000,   // Correctable Error Mask Register OR Mask
          0xFFFFFFFF,   // Advanced Error Capabilities and Control Register AND Mask
          0x00000000,   // Advanced Error Capabilities and Control Register OR Mask
          0xFFF7,       // Device Control Register AND Mask
          0x0007,       // Device Control Register OR Mask
          0xFFFF,       // Link Control Register AND Mask
          0x0000,       // Link Control Register OR Mask
          0xFFFFFFFF,   // Secondary Uncorrectable Error Severity Register AND Mask
          0x00000000,   // Secondary Uncorrectable Error Severity Register OR Mask
          0xFFFFFFFF,   // Secondary Uncorrectable Error Mask Register AND Mask
          0x00000000    // Secondary Uncorrectable Error Mask Register OR Mask
          }
        }
      )
    }

    Method (_STA, 0x0, NotSerialized)
    {
      Return (0xf)
    }
  } // Device(PCI0)

  Device (PCI1)
  {
    // PCI1 indicate host bridge 1
    Name (_HID, "PNP0A08")                   // PCI Express Root Bridge
    Name (_UID, 1)
    Name (_CID, "PNP0A03")                   // Compatible PCI Root Bridge, Compatible ID
    Name (_SEG, 0)                            // Segment of this Root complex
    Name (_BBN, 0x7e)                         // Base Bus Number ??
    Name (_CCA, 1)                            // cache coherence attribute ??
    Method (_CRS, 0, Serialized)             // Root complex resources, _CRS: current resource setting
    {
      // Method is defined in 19.6.82 in ACPI 6.0 spec
      Name (RBUF, ResourceTemplate ()        // Name: 19.6.87, ResourceTemplate: 19.6.111,
      {
        // 19.3.3 in ACPI 6.0 spec
        WordBusNumber (                      // Bus numbers assigned to this root,
          // wordBusNumber: 19.6.144
          ResourceProducer,
          MinFixed,
          MaxFixed,
          PosDecode,
          0,                                 // AddressGranularity
          0x7e,                              // AddressMinimum - Minimum Bus Number
          0x7e,                              // AddressMaximum - Maximum Bus Number
          0,                                 // AddressTranslation - Set to 0
          0x1                                // RangeLength - Number of Busses
        )
        QWordMemory (                        // 64-bit BAR Windows, where to show this ??
          ResourceProducer,
          PosDecode,
          MinFixed,
          MaxFixed,
          Prefetchable,
          ReadWrite,
          0x0,                               // Granularity
          0x148800000,                       // Min Base Address pci address ??
          0x148ffffff,                       // Max Base Address
          0x0,                               // Translate
          0x800000                           // Length, 8M
        )
      })                                      // Name(RBUF)
      Return (RBUF)
    }                                         // Method(_CRS), this method return RBUF!
    Method (_STA, 0x0, NotSerialized)
    {
      Return (0x0)
    }
  } // Device(PCI1)

  Device (PCI2)
  {
    Name (_HID, "PNP0A08")                   // PCI Express Root Bridge
    Name (_CID, "PNP0A03")                   // Compatible PCI Root Bridge, Compatible ID
    Name (_UID, 2)
    Name (_SEG, 0)                            // Segment of this Root complex
    Name (_BBN, 0x7a)                         // Base Bus Number
    Name (_CCA, 1)                            // cache coherence attribute ??
    Method (_CRS, 0, Serialized)             // Root complex resources, _CRS: current resource //                               setting
    {
      // Method is defined in 19.6.82 in ACPI 6.0 spec
      Name (RBUF, ResourceTemplate ()        // Name: 19.6.87, ResourceTemplate: 19.6.111,
      {
        // 19.3.3 in ACPI 6.0 spec
        WordBusNumber (                      // Bus numbers assigned to this root,
          // wordBusNumber: 19.6.144
          ResourceProducer,
          MinFixed,
          MaxFixed,
          PosDecode,
          0,                                 // AddressGranularity
          0x7a,                              // AddressMinimum - Minimum Bus Number
          0x7a,                              // AddressMaximum - Maximum Bus Number
          0,                                 // AddressTranslation - Set to 0
          0x1                                // RangeLength - Number of Busses
        )
        QWordMemory (                        // 64-bit BAR Windows
          ResourceProducer,
          PosDecode,
          MinFixed,
          MaxFixed,
          Prefetchable,
          ReadWrite,
          0x0,                               // Granularity
          0x20c000000,                       // Min Base Address pci address
          0x20c1fffff,                       // Max Base Address
          0x0,                               // Translate
          0x200000                           // Length, 2M
        )
      })                                      // Name(RBUF)
      Return (RBUF)
    }                                         // Method(_CRS), this method return RBUF!
    Method (_STA, 0x0, NotSerialized)
    {
      Return (0x0)
    }
  }

  Device (PCI3)
  {
    Name (_HID, "PNP0A08")                   // PCI Express Root Bridge
    Name (_UID, 3)
    Name (_CID, "PNP0A03")                   // Compatible PCI Root Bridge, Compatible ID
    Name (_SEG, 0)                            // Segment of this Root complex
    Name (_BBN, 0x78)                         // Base Bus Number ??
    Name (_CCA, 1)                            // cache coherence attribute ??
    Method (_CRS, 0, Serialized)             // Root complex resources, _CRS: current resource //                               setting
    {
      // Method is defined in 19.6.82 in ACPI 6.0 spec
      Name (RBUF, ResourceTemplate ()        // Name: 19.6.87, ResourceTemplate: 19.6.111,
      {
        // 19.3.3 in ACPI 6.0 spec
        WordBusNumber (                      // Bus numbers assigned to this root,
          // wordBusNumber: 19.6.144
          ResourceProducer,
          MinFixed,
          MaxFixed,
          PosDecode,
          0,                                 // AddressGranularity
          0x78,                              // AddressMinimum - Minimum Bus Number
          0x79,                              // AddressMaximum - Maximum Bus Number
          0,                                 // AddressTranslation - Set to 0
          0x2                                // RangeLength - Number of Busses
        )
        QWordMemory (                        // 64-bit BAR Windows
          ResourceProducer,
          PosDecode,
          MinFixed,
          MaxFixed,
          Prefetchable,
          ReadWrite,
          0x0,                               // Granularity
          0x208000000,                       // Min Base Address pci address
          0x208ffffff,                       // Max Base Address
          0x0,                               // Translate
          0x1000000                          // Length, 16M
        )
      })                                      // Name(RBUF)
      Return (RBUF)
    }                                         // Method(_CRS), this method return RBUF!
    Method (_STA, 0x0, NotSerialized)
    {
      Return (0x0)
    }
  }

  Device (PCI4)
  {
    Name (_HID, "PNP0A08")                   // PCI Express Root Bridge
    Name (_UID, 4)
    Name (_CID, "PNP0A03")                   // Compatible PCI Root Bridge, Compatible ID
    Name (_SEG, 0)                            // Segment of this Root complex
    Name (_BBN, 0x7c)                         // Base Bus Number ??
    Name (_CCA, 1)                            // cache coherence attribute ??
    Method (_CRS, 0, Serialized)             // Root complex resources, _CRS: current resource //                               setting
    {
      // Method is defined in 19.6.82 in ACPI 6.0 spec
      Name (RBUF, ResourceTemplate ()        // Name: 19.6.87, ResourceTemplate: 19.6.111,
      {
        // 19.3.3 in ACPI 6.0 spec
        WordBusNumber (                      // Bus numbers assigned to this root,
          // wordBusNumber: 19.6.144
          ResourceProducer,
          MinFixed,
          MaxFixed,
          PosDecode,
          0,                                 // AddressGranularity
          0x7c,                              // AddressMinimum - Minimum Bus Number
          0x7d,                              // AddressMaximum - Maximum Bus Number
          0,                                 // AddressTranslation - Set to 0
          0x2                                // RangeLength - Number of Busses
        )
        QWordMemory (                        // 64-bit BAR Windows
          ResourceProducer,
          PosDecode,
          MinFixed,
          MaxFixed,
          Prefetchable,
          ReadWrite,
          0x0,                               // Granularity
          0x120000000,                       // Min Base Address pci address
          0x13fffffff,                       // Max Base Address
          0x0,                               // Translate
          0x20000000                         // Length, 512M
        )
      })                                      // Name(RBUF)
      Return (RBUF)
    }                                         // Method(_CRS), this method return RBUF!
    Method (_STA, 0x0, NotSerialized)
    {
      Return (0x0)
    }
  }

  Device (PCI5)
  {
    Name (_HID, "PNP0A08")                   // PCI Express Root Bridge
    Name (_UID, 5)
    Name (_CID, "PNP0A03")                   // Compatible PCI Root Bridge, Compatible ID
    Name (_SEG, 0)                            // Segment of this Root complex
    Name (_BBN, 0x74)                         // Base Bus Number ??
    Name (_CCA, 1)                            // cache coherence attribute ??

    Name (_PRT, Package
    {
      Package{0x3FFFF, 0, 0, 640},      // INT_A
    })

    Method (_CRS, 0, Serialized)             // Root complex resources, _CRS: current resource setting
    {
      // Method is defined in 19.6.82 in ACPI 6.0 spec
      Name (RBUF, ResourceTemplate ()        // Name: 19.6.87, ResourceTemplate: 19.6.111,
      {
        // 19.3.3 in ACPI 6.0 spec
        WordBusNumber (                      // Bus numbers assigned to this root,
          // wordBusNumber: 19.6.144
          ResourceProducer,
          MinFixed,
          MaxFixed,
          PosDecode,
          0,                                 // AddressGranularity
          0x74,                              // AddressMinimum - Minimum Bus Number
          0x76,                              // AddressMaximum - Maximum Bus Number
          0,                                 // AddressTranslation - Set to 0
          0x3                                // RangeLength - Number of Busses
        )
        QWordMemory (                        // 64-bit BAR Windows
          ResourceProducer,
          PosDecode,
          MinFixed,
          MaxFixed,
          Prefetchable,
          ReadWrite,
          0x0,                               // Granularity
          0x144000000,                       // Min Base Address pci address
          0x147ffffff,                       // Max Base Address
          0x0,                               // Translate
          0x4000000                          // Length, 32M
        )
        QWordMemory (                        // 32-bit non-prefetch BAR Windows
          ResourceProducer,
          PosDecode,
          MinFixed,
          MaxFixed,
          Cacheable,
          ReadWrite,
          0x0,                               // Granularity
          0xa2000000,                        // Min Base Address pci address
          0xa2ffffff,                        // Max Base Address
          0x0,                               // Translate
          0x1000000                          // Length, 16M
        )
      })                                      // Name(RBUF)
      Return (RBUF)
    }                                         // Method(_CRS), this method return RBUF!
    Method (_STA, 0x0, NotSerialized)
    {
      Return (0x0)
    }
  }

  Device (PCI6)
  {
    // PCI0 indicate host bridge 0
    Name (_HID, "PNP0A08")                   // PCI Express Root Bridge
    Name (_UID, 6)
    Name (_CID, "PNP0A03")                   // Compatible PCI Root Bridge, Compatible ID
    Name(_SEG, 0)                            // Segment of this Root complex
    Name(_BBN, 0x80)                         // Base Bus Number
    Name(_CCA, 1)                            // cache coherence attribute

    Name (_PRT, Package ()
    {
      // INTx configure for RP0, whoes device number is 0
      // For ESL/FPGA debug, we should modify this according to
      // specific hardware configuration.
      Package () {0x8000FFFF, 0, 0, 640},      // INT_A
      Package () {0x8000FFFF, 1, 0, 641},      // INT_B
      Package () {0x8000FFFF, 2, 0, 642},      // INT_C
      Package () {0x8000FFFF, 3, 0, 643},      // INT_D

      // This is an example of RP1 INTx configure. Adding or not
      // adding RPx INTx configure deponds on hardware board topology,
      // if UEFI enables RPx, RPy, RPz... related INTx configure
      // should be added
      Package () {0x8008FFFF, 0, 0, 640},      // INT_A
      Package () {0x8008FFFF, 1, 0, 641},      // INT_B
      Package () {0x8008FFFF, 2, 0, 642},      // INT_C
      Package () {0x8008FFFF, 3, 0, 643},      // INT_D

      Package () {0x800CFFFF, 0, 0, 640},      // INT_A
      Package () {0x800CFFFF, 1, 0, 641},      // INT_B
      Package () {0x800CFFFF, 2, 0, 642},      // INT_C
      Package () {0x800CFFFF, 3, 0, 643},      // INT_D

      Package () {0x8010FFFF, 0, 0, 640},      // INT_A
      Package () {0x8010FFFF, 1, 0, 641},      // INT_B
      Package () {0x8010FFFF, 2, 0, 642},      // INT_C
      Package () {0x8010FFFF, 3, 0, 643}       // INT_D
    })

    Method (_CRS, 0, Serialized)             // Root complex resources, _CRS: current resource setting
    {
                                             // Method is defined in 19.6.82 in ACPI 6.0 spec
      Name (RBUF, ResourceTemplate ()        // Name: 19.6.87, ResourceTemplate: 19.6.111,
      {
                                             // 19.3.3 in ACPI 6.0 spec
        WordBusNumber (                      // Bus numbers assigned to this root,
                                             // wordBusNumber: 19.6.144
          ResourceProducer,
          MinFixed,
          MaxFixed,
          PosDecode,
          0,                                 // AddressGranularity
          0x80,                              // AddressMinimum - Minimum Bus Number
          0x9f,                              // AddressMaximum - Maximum Bus Number
          0,                                 // AddressTranslation - Set to 0
          0x20                               // RangeLength - Number of Busses
        )
        QWordMemory (                        // 64-bit prefetch BAR windows
          ResourceProducer,
          PosDecode,
          MinFixed,
          MaxFixed,
          Prefetchable,
          ReadWrite,
          0x0,                               // Granularity
          0x480000000000,                    // Min Base Address pci address
          0x483fffffffff,                    // Max Base Address
          0x0,                               // Translate
          0x4000000000                       // Length, 256G
        )
        QWordMemory (                        // 32-bit non-prefetch BAR windows
          ResourceProducer,
          PosDecode,
          MinFixed,
          MaxFixed,
          Cacheable,
          ReadWrite,
          0x0,                               // Granularity
          0xe8000000,                        // Min Base Address pci address
          0xeffeffff,                        // Max Base Address
          0x0,                               // Translate
          0x7ff0000                          // Length, 128M - 64K
        )
        QWordIO (
          ResourceProducer,
          MinFixed,
          MaxFixed,
          PosDecode,
          EntireRange,
          0x0,                               // Granularity
          0x0,                               // Min Base Address
          0xffff,                            // Max Base Address
          0xefff0000,                        // Translate
          0x10000                            // Length, 64K
        )
      })                                     // Name(RBUF)
      Return (RBUF)
    }                                        // Method(_CRS), this method return RBUF!

    //
    // OS Control Handoff
    //
    Name(SUPP, Zero) // PCI _OSC Support Field value
    Name(CTRL, Zero) // PCI _OSC Control Field value

    /* See [1] 6.2.10, [2] 4.5 */
    Method(_OSC, 4)
    {
      // Check for proper UUID
      If(LEqual(Arg0, ToUUID("33DB4D5B-1FF7-401C-9657-7441C03DD766")))
      {
        // Create DWord-adressable fields from the Capabilities Buffer
        CreateDWordField(Arg3, 0, CDW1)
        CreateDWordField(Arg3, 4, CDW2)
        CreateDWordField(Arg3, 8, CDW3)

        // Save Capabilities DWord2 & 3
        Store(CDW2, SUPP)
        Store(CDW3, CTRL)

        // Only allow native hot plug control if OS supports:
        //  ASPM
        //  Clock PM
        //  MSI/MSI-X
        If(LNotEqual(And(SUPP, 0x16), 0x16))
        {
          And(CTRL, 0x1E, CTRL) // Mask bit 0 (and undefined bits)
        }

        // Always allow native PME, AER (no dependencies)

        // Never allow SHPC (no SHPC controller in this system)
        And(CTRL, 0x1D, CTRL)

        If(LNotEqual(Arg1, One))       // Unknown revision
        {
          Or(CDW1, 0x08, CDW1)
        }

        If(LNotEqual(CDW3, CTRL))      // Capabilities bits were masked
        {
          Or(CDW1, 0x10, CDW1)
        }

        // Update DWORD3 in the buffer
        Store(CTRL, CDW3)
        Return(Arg3)
      }
      Else
      {
        Or(CDW1, 4, CDW1) // Unrecognized UUID
        Return(Arg3)
      }
    } // End _OSC

    Method (_HPX, 0) {
      Return (Package(2) {
        Package(6) {    // PCI Setting Record
          0x00,         // Type 0
          0x01,         // Revision 1
          0x08,         // CacheLineSize in DWORDS
          0x40,         // LatencyTimer in PCI clocks
          0x01,         // Enable SERR (Boolean)
          0x01          // Enable PERR (Boolean)
          },
        Package(18) {   // PCI-X Setting Record
          0x02,         // Type 2
          0x01,         // Revision 1
          0xFFFFFFFF,   // Uncorrectable Error Mask Register AND Mask, Keep ->1
          0x00000000,   // Uncorrectable Error Mask Register OR Mask, keep ->0
          0xFFFFFFFF,   // Uncorrectable Error Severity Register AND Mask
          0x00000000,   // Uncorrectable Error Severity Register OR Mask
          0xFFFFFFFF,   // Correctable Error Mask Register AND Mask
          0x00000000,   // Correctable Error Mask Register OR Mask
          0xFFFFFFFF,   // Advanced Error Capabilities and Control Register AND Mask
          0x00000000,   // Advanced Error Capabilities and Control Register OR Mask
          0xFFF7,       // Device Control Register AND Mask
          0x0007,       // Device Control Register OR Mask
          0xFFFF,       // Link Control Register AND Mask
          0x0000,       // Link Control Register OR Mask
          0xFFFFFFFF,   // Secondary Uncorrectable Error Severity Register AND Mask
          0x00000000,   // Secondary Uncorrectable Error Severity Register OR Mask
          0xFFFFFFFF,   // Secondary Uncorrectable Error Mask Register AND Mask
          0x00000000    // Secondary Uncorrectable Error Mask Register OR Mask
          }
        }
      )
    }

    Method (_STA, 0x0, NotSerialized)
    {
      Return (0xf)
    }
  } // Device(PCI6)
}
