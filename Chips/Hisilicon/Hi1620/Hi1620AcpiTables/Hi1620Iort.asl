/*
 * Intel ACPI Component Architecture
 * iASL Compiler/Disassembler version 20151124-64
 * Copyright (c) 2000 - 2015 Intel Corporation
 *
 * Template for [IORT] ACPI Table (static data table)
 * Format: [ByteLength]  FieldName : HexFieldValue
 */
[0004]                          Signature : "IORT"    [IO Remapping Table]
[0004]                       Table Length : 01c8
[0001]                           Revision : 00
[0001]                           Checksum : BC
[0006]                             Oem ID : "HISI"
[0008]                       Oem Table ID : "D06"
[0004]                       Oem Revision : 00000000
[0004]                    Asl Compiler ID : "INTL"
[0004]              Asl Compiler Revision : 20150410

[0004]                         Node Count : 00000005           // ITS, SMMU and RC
[0004]                        Node Offset : 00000034
[0004]                           Reserved : 00000000
[0004]                   Optional Padding : 00 00 00 00

/* ITS, for PCIe */
/* Here we use the P680/Hi1620 ACPI table which includes MADT table to help to debuge */
[0001]                               Type : 00
[0002]                             Length : 0018
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000000
[0004]                     Mapping Offset : 00000000

[0004]                           ItsCount : 00000001
[0004]                        Identifiers : 00000000

/* 0x4c */
/* SMMU for PCIe host bridge 0 and 1 */
[0001]                               Type : 04
[0002]                             Length : 0068
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000002
[0004]                     Mapping Offset : 00000040

[0008]                       Base Address : 148000000
[0004]              Flags (decoded below) : 00000009
                          COHACC Override : 1
                            HTTU Override : 0
                    Proximity Domain Valid: 1
[0004]                           Reserved : 00000000
[0008]                      VATOS Address : 0
[0004]                              Model : 00000000
[0004]                    Event Interrupt : 00000000
[0004]                      PRI Interrupt : 00000000
[0004]                     GERR Interrupt : 00000000
[0004]                     Sync Interrupt : 00000000
[0001]                    Proximity domain: 00
[0001]                           Reserved1: 00
[0002]                           Reserved2: 0000

[0004]                         Input base : 00000000
[0004]                           ID Count : 00004000
[0004]                        Output Base : 00000000
[0004]                   Output Reference : 00000034
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

[0004]                         Input base : 00007e00
[0004]                           ID Count : 00000100
[0004]                        Output Base : 00007e00
[0004]                   Output Reference : 00000034
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

/* RC 0 */
[0001]                               Type : 02
[0002]                             Length : 0078
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000004
[0004]                     Mapping Offset : 00000020

[0008]                  Memory Properties : [IORT Memory Access Properties]
[0004]                    Cache Coherency : 00000001
[0001]              Hints (decoded below) : 00
                                Transient : 0
                           Write Allocate : 0
                            Read Allocate : 0
                                 Override : 0
[0002]                           Reserved : 0000
[0001]       Memory Flags (decoded below) : 00
                                Coherency : 0
                         Device Attribute : 0
[0004]                      ATS Attribute : 00000000
[0004]                 PCI Segment Number : 00000000           // should match with above MCFG

/* BDF of pcie host 0 -> stream ID of pcie 0/1 SMMU */
[0004]                         Input base : 00000000
[0004]                           ID Count : 00004000          // the number of IDs in range
[0004]                        Output Base : 00000000
[0004]                   Output Reference : 0000004c
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

/* BDF of pcie host 1 -> stream ID of pcie 0/1 SMMU */
[0004]                         Input base : 00007e00
[0004]                           ID Count : 00000100          // the number of IDs in range
[0004]                        Output Base : 00007e00
[0004]                   Output Reference : 0000004c
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

/* BDF of pcie host 4 -> stream ID of pcie 4 SMMU */
[0004]                         Input base : 00007c00
[0004]                           ID Count : 00000200          // the number of IDs in range
[0004]                        Output Base : 00007c00
[0004]                   Output Reference : 00000034
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

/* BDF of pcie host 5 -> stream ID of pcie 5 SMMU */
[0004]                         Input base : 00007400
[0004]                           ID Count : 00000300          // the number of IDs in range
[0004]                        Output Base : 00007400
[0004]                   Output Reference : 00000034
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0
