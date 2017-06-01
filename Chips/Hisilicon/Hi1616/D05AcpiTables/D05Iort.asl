/*
 * Intel ACPI Component Architecture
 * iASL Compiler/Disassembler version 20151124-64
 * Copyright (c) 2000 - 2015 Intel Corporation
 *
 * Template for [IORT] ACPI Table (static data table)
 * Format: [ByteLength]  FieldName : HexFieldValue
 */
[0004]                          Signature : "IORT"    [IO Remapping Table]
[0004]                       Table Length : 000002e4
[0001]                           Revision : 00
[0001]                           Checksum : BC
[0006]                             Oem ID : "HISI  "
[0008]                       Oem Table ID : "HIP07   "
[0004]                       Oem Revision : 00000000
[0004]                    Asl Compiler ID : "INTL"
[0004]              Asl Compiler Revision : 20151124

[0004]                         Node Count : 00000008
[0004]                        Node Offset : 00000034
[0004]                           Reserved : 00000000
[0004]                   Optional Padding : 00 00 00 00

/* ITS 0, for peri a */
[0001]                               Type : 00
[0002]                             Length : 0018
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000000
[0004]                     Mapping Offset : 00000000

[0004]                           ItsCount : 00000001
[0004]                        Identifiers : 00000000
//4c
/* ITS 1, for peri b */
[0001]                               Type : 00
[0002]                             Length : 0018
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000000
[0004]                     Mapping Offset : 00000000

[0004]                           ItsCount : 00000001
[0004]                        Identifiers : 00000001
//64
/* ITS 2, for dsa a */
[0001]                               Type : 00
[0002]                             Length : 0018
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000000
[0004]                     Mapping Offset : 00000000

[0004]                           ItsCount : 00000001
[0004]                        Identifiers : 00000002
//7c
/* ITS 3, for dsa b */
[0001]                               Type : 00
[0002]                             Length : 0018
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000000
[0004]                     Mapping Offset : 00000000

[0004]                           ItsCount : 00000001
[0004]                        Identifiers : 00000003
//94
/*Sec CPU ITS 0, for peri a */
[0001]                               Type : 00
[0002]                             Length : 0018
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000000
[0004]                     Mapping Offset : 00000000

[0004]                           ItsCount : 00000001
[0004]                        Identifiers : 00000004
//ac
/* SEC CPU ITS 1, for peri b */
[0001]                               Type : 00
[0002]                             Length : 0018
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000000
[0004]                     Mapping Offset : 00000000

[0004]                           ItsCount : 00000001
[0004]                        Identifiers : 00000005
//c4
/* SEC CPU ITS 2, for dsa a */
[0001]                               Type : 00
[0002]                             Length : 0018
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000000
[0004]                     Mapping Offset : 00000000

[0004]                           ItsCount : 00000001
[0004]                        Identifiers : 00000006
//dc
/* SEC CPU ITS 3, for dsa b */
[0001]                               Type : 00
[0002]                             Length : 0018
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000000
[0004]                     Mapping Offset : 00000000

[0004]                           ItsCount : 00000001
[0004]                        Identifiers : 00000007

//f4
/* 1P NA PCIe SMMU */
[0001]                               Type : 04
[0002]                             Length : 0050
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 0000003C

[0008]                       Base Address : a0040000
[0004]              Flags (decoded below) : 00000001
                          COHACC Override : 1
                            HTTU Override : 0
[0004]                           Reserved : 00000000
[0008]                      VATOS Address : 0
[0004]                              Model : 00000001
[0004]                    Event Interrupt : 00000000
[0004]                      PRI Interrupt : 00000000
[0004]                     GERR Interrupt : 00000000
[0004]                     Sync Interrupt : 00000000
/* this is the map for PCIe2 in 1P NA */
[0004]                         Input base : 00028000
[0004]                           ID Count : 00000800
[0004]                        Output Base : 00008000
[0004]                   Output Reference : 00000064
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

//144
/* 2P NB PCIe SMMU */
[0001]                               Type : 04
[0002]                             Length : 0064
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 0000003C

[0008]                       Base Address : 700a0040000
[0004]              Flags (decoded below) : 00000001
                          COHACC Override : 1
                            HTTU Override : 0
[0004]                           Reserved : 00000000
[0008]                      VATOS Address : 0
[0004]                              Model : 00000001
[0004]                    Event Interrupt : 00000000
[0004]                      PRI Interrupt : 00000000
[0004]                     GERR Interrupt : 00000000
[0004]                     Sync Interrupt : 00000000
/* this is the map for pcie0 in 2p nb */
[0004]                         Input base : 00002000
[0004]                           Id count : 00001000
[0004]                        Output base : 00002000
[0004]                   Output reference : 00000064
[0004]              Flags (decoded below) : 00000000
                           Single mapping : 0
/* this is the map for PCIe1 in 2P NB */
[0004]                         Input base : 00013000
[0004]                           ID Count : 00001000
[0004]                        Output Base : 00003000
[0004]                   Output Reference : 00000064
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

//1a8
[088h 0136   1]                         Type : 04
[089h 0137   2]                       Length : 003C
[08Bh 0139   1]                     Revision : 00
[08Ch 0140   4]                     Reserved : 00000000
[090h 0144   4]                Mapping Count : 00000000
[094h 0148   4]               Mapping Offset : 0000003C

[098h 0152   8]                 Base Address : 00000000C0040000
[0A0h 0160   4]        Flags (decoded below) : 00000001
                             COHACC Override : 1
                               HTTU Override : 0
[0A4h 0164   4]                     Reserved : 00000000
[0A8h 0168   8]                VATOS Address : 0000000000000000
[0B0h 0176   4]                        Model : 00000001
[0B4h 0180   4]                   Event GSIV : 00000000
[0B8h 0184   4]                     PRI GSIV : 00000000
[0BCh 0188   4]                    GERR GSIV : 00000000
[0C0h 0192   4]                    Sync GSIV : 00000000


//1e4
/* 1P NB PCIe SMMU */
[0001]                               Type : 04
[0002]                             Length : 0050
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 0000003C

[0008]                       Base Address : 8a0040000
[0004]              Flags (decoded below) : 00000001
                          COHACC Override : 1
                            HTTU Override : 0
[0004]                           Reserved : 00000000
[0008]                      VATOS Address : 0
[0004]                              Model : 00000001
[0004]                    Event Interrupt : 00000000
[0004]                      PRI Interrupt : 00000000
[0004]                     GERR Interrupt : 00000000
[0004]                     Sync Interrupt : 00000000
/* this is the map for PCIe1 in 1P NB */
[0004]                         Input base : 00010000
[0004]                           ID Count : 00000800
[0004]                        Output Base : 00000000
[0004]                   Output Reference : 00000064
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

//234
/* 2P NA PCIe SMMU */
[0001]                               Type : 04
[0002]                             Length : 0050
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 0000003C

[0008]                       Base Address : 600a0040000
[0004]              Flags (decoded below) : 00000001
                          COHACC Override : 1
                            HTTU Override : 0
[0004]                           Reserved : 00000000
[0008]                      VATOS Address : 0
[0004]                              Model : 00000001
[0004]                    Event Interrupt : 00000000
[0004]                      PRI Interrupt : 00000000
[0004]                     GERR Interrupt : 00000000
[0004]                     Sync Interrupt : 00000000
/* this is the map for PCIe2 in 2P NA */
[0004]                         Input base : 00021000
[0004]                           ID Count : 00001000
[0004]                        Output Base : 00001000
[0004]                   Output Reference : 00000064
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

/* mbi-gen peri b, named component */
[0001]                               Type : 01
[0002]                             Length : 0046
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 00000032

[0004]                         Node Flags : 00000000
[0008]                  Memory Properties : [IORT Memory Access Properties]
[0004]                    Cache Coherency : 00000000
[0001]              Hints (decoded below) : 00
                                Transient : 0
                           Write Allocate : 0
                            Read Allocate : 0
                                 Override : 0
[0002]                           Reserved : 0000
[0001]       Memory Flags (decoded below) : 00
                                Coherency : 0
                         Device Attribute : 0
[0001]                  Memory Size Limit : 00
[0016]                        Device Name : "\_SB_.MBI0"
[0004]                            Padding : 00 00 00 00

[0004]                         Input base : 00000000
[0004]                           ID Count : 00000001
[0004]                        Output Base : 000120c7 //device id
[0004]                   Output Reference : 0000004C
[0004]              Flags (decoded below) : 00000001
                           Single Mapping : 1

/* mbi-gen1 dsa a, named component */
[0001]                               Type : 01
[0002]                             Length : 0046
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 00000032

[0004]                         Node Flags : 00000000
[0008]                  Memory Properties : [IORT Memory Access Properties]
[0004]                    Cache Coherency : 00000000
[0001]              Hints (decoded below) : 00
                               Transient : 0
                          Write Allocate : 0
                           Read Allocate : 0
                                Override : 0
[0002]                           Reserved : 0000
[0001]       Memory Flags (decoded below) : 00
                               Coherency : 0
                        Device Attribute : 0
[0001]                  Memory Size Limit : 00
[0016]                        Device Name : "\_SB_.MBI1"
[0004]                            Padding : 00 00 00 00

[0004]                         Input base : 00000000
[0004]                           ID Count : 00000001
[0004]                        Output Base : 00040800    //device id
[0004]                   Output Reference : 00000064
[0004]              Flags (decoded below) : 00000001
                          Single Mapping : 1

/* mbi-gen mbi7 - RoCE named component */
[0001]                               Type : 01
[0002]                             Length : 0046
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 00000032

[0004]                         Node Flags : 00000000
[0008]                  Memory Properties : [IORT Memory Access Properties]
[0004]                    Cache Coherency : 00000000
[0001]              Hints (decoded below) : 00
                                Transient : 0
                           Write Allocate : 0
                            Read Allocate : 0
                                 Override : 0
[0002]                           Reserved : 0000
[0001]       Memory Flags (decoded below) : 00
                                Coherency : 0
                         Device Attribute : 0
[0001]                  Memory Size Limit : 00
[0016]                        Device Name : "\_SB_.MBI9"
[0004]                            Padding : 00 00 00 00

[0004]                         Input base : 00000000
[0004]                           ID Count : 00000001
[0004]                        Output Base : 00040b1e
[0004]                   Output Reference : 00000064
[0004]              Flags (decoded below) : 00000001
                           Single Mapping : 1

/* mbi-gen dsa a - usb named component */
[0001]                               Type : 01
[0002]                             Length : 0046
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 00000032

[0004]                         Node Flags : 00000000
[0008]                  Memory Properties : [IORT Memory Access Properties]
[0004]                    Cache Coherency : 00000000
[0001]              Hints (decoded below) : 00
                               Transient : 0
                          Write Allocate : 0
                           Read Allocate : 0
                                Override : 0
[0002]                           Reserved : 0000
[0001]       Memory Flags (decoded below) : 00
                               Coherency : 0
                        Device Attribute : 0
[0001]                  Memory Size Limit : 00
[0016]                        Device Name : "\_SB_.MBI5"
[0004]                            Padding : 00 00 00 00

[0004]                         Input base : 00000000
[0004]                           ID Count : 00000001
[0004]                        Output Base : 00040080    //device id
[0004]                   Output Reference : 00000064
[0004]              Flags (decoded below) : 00000001
                          Single Mapping : 1

/* mbi-gen1 dsa a, named component */
[0001]                               Type : 01
[0002]                             Length : 0046
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 00000032

[0004]                         Node Flags : 00000000
[0008]                  Memory Properties : [IORT Memory Access Properties]
[0004]                    Cache Coherency : 00000000
[0001]              Hints (decoded below) : 00
                               Transient : 0
                          Write Allocate : 0
                           Read Allocate : 0
                                Override : 0
[0002]                           Reserved : 0000
[0001]       Memory Flags (decoded below) : 00
                               Coherency : 0
                        Device Attribute : 0
[0001]                  Memory Size Limit : 00
[0016]                        Device Name : "\_SB_.MBI2"
[0004]                            Padding : 00 00 00 00

[0004]                         Input base : 00000000
[0004]                           ID Count : 00000001
[0004]                        Output Base : 00040900    //device id
[0004]                   Output Reference : 00000064
[0004]              Flags (decoded below) : 00000001
                          Single Mapping : 1

/* mbi-gen1 pcie, named component */
[0001]                               Type : 01
[0002]                             Length : 0046
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 00000032

[0004]                         Node Flags : 00000000
[0008]                  Memory Properties : [IORT Memory Access Properties]
[0004]                    Cache Coherency : 00000000
[0001]              Hints (decoded below) : 00
                               Transient : 0
                          Write Allocate : 0
                           Read Allocate : 0
                                Override : 0
[0002]                           Reserved : 0000
[0001]       Memory Flags (decoded below) : 00
                               Coherency : 0
                        Device Attribute : 0
[0001]                  Memory Size Limit : 00
[0016]                        Device Name : "\_SB_.MBI3"
[0004]                            Padding : 00 00 00 00

[0004]                         Input base : 00000000
[0004]                           ID Count : 00000001
[0004]                        Output Base : 00040000    //device id
[0004]                   Output Reference : 00000064
[0004]              Flags (decoded below) : 00000001
                          Single Mapping : 1

/* mbi-gen1 pcie, named component */
[0001]                               Type : 01
[0002]                             Length : 0046
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 00000032

[0004]                         Node Flags : 00000000
[0008]                  Memory Properties : [IORT Memory Access Properties]
[0004]                    Cache Coherency : 00000000
[0001]              Hints (decoded below) : 00
                               Transient : 0
                          Write Allocate : 0
                           Read Allocate : 0
                                Override : 0
[0002]                           Reserved : 0000
[0001]       Memory Flags (decoded below) : 00
                               Coherency : 0
                        Device Attribute : 0
[0001]                  Memory Size Limit : 00
[0016]                        Device Name : "\_SB_.MBI4"
[0004]                            Padding : 00 00 00 00

[0004]                         Input base : 00000000
[0004]                           ID Count : 00000001
[0004]                        Output Base : 00040040    //device id
[0004]                   Output Reference : 00000064
[0004]              Flags (decoded below) : 00000001
                          Single Mapping : 1

/* mbi-gen1 alg a, i2c 0 named component */
[0001]                               Type : 01
[0002]                             Length : 0046
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 00000032

[0004]                         Node Flags : 00000000
[0008]                  Memory Properties : [IORT Memory Access Properties]
[0004]                    Cache Coherency : 00000000
[0001]              Hints (decoded below) : 00
                               Transient : 0
                          Write Allocate : 0
                           Read Allocate : 0
                                Override : 0
[0002]                           Reserved : 0000
[0001]       Memory Flags (decoded below) : 00
                               Coherency : 0
                        Device Attribute : 0
[0001]                  Memory Size Limit : 00
[0016]                        Device Name : "\_SB_.MBI6"
[0004]                            Padding : 00 00 00 00

[0004]                         Input base : 00000000
[0004]                           ID Count : 00000001
[0004]                        Output Base : 00040B0E    //device id
[0004]                   Output Reference : 00000064
[0004]              Flags (decoded below) : 00000001
                          Single Mapping : 1

/* mbi-gen1 alg a, i2c 2 named component */
[0001]                               Type : 01
[0002]                             Length : 0046
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 00000032

[0004]                         Node Flags : 00000000
[0008]                  Memory Properties : [IORT Memory Access Properties]
[0004]                    Cache Coherency : 00000000
[0001]              Hints (decoded below) : 00
                               Transient : 0
                          Write Allocate : 0
                           Read Allocate : 0
                                Override : 0
[0002]                           Reserved : 0000
[0001]       Memory Flags (decoded below) : 00
                               Coherency : 0
                        Device Attribute : 0
[0001]                  Memory Size Limit : 00
[0016]                        Device Name : "\_SB_.MBI7"
[0004]                            Padding : 00 00 00 00

[0004]                         Input base : 00000000
[0004]                           ID Count : 00000001
[0004]                        Output Base : 00040B10    //device id
[0004]                   Output Reference : 00000064
[0004]              Flags (decoded below) : 00000001
                          Single Mapping : 1

/*1P NA PCIe2 */
[0001]                               Type : 02
[0002]                             Length : 0034
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
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
[0004]                 PCI Segment Number : 00000002

[0004]                         Input base : 00008000
[0004]                           ID Count : 00000800
[0004]                        Output Base : 00028000
[0004]                   Output Reference : 000000f4
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0
/* 1P NB PCIe0 */
[0001]                               Type : 02
[0002]                             Length : 0034
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
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
[0004]                 PCI Segment Number : 00000004

[0004]                         Input base : 00008800
[0004]                           ID Count : 00000800
[0004]                        Output Base : 00008800
[0004]                   Output Reference : 0000007c
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

/* 1P NB PCIe1 */
[0001]                               Type : 02
[0002]                             Length : 0034
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
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
[0004]                 PCI Segment Number : 00000005

[0004]                         Input base : 00000000
[0004]                           ID Count : 00000800
[0004]                        Output Base : 00010000
[0004]                   Output Reference : 000001e4
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

/* 1P NB PCIe2 */
[0001]                               Type : 02
[0002]                             Length : 0034
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
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
[0004]                 PCI Segment Number : 00000006

[0004]                         Input base : 0000c000
[0004]                           ID Count : 00000800
[0004]                        Output Base : 0000c000
[0004]                   Output Reference : 0000007c
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0
/* 1P NB PCIe3 */
[0001]                               Type : 02
[0002]                             Length : 0034
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
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
[0004]                 PCI Segment Number : 00000007

[0004]                         Input base : 00009000
[0004]                           ID Count : 00000800
[0004]                        Output Base : 00009000
[0004]                   Output Reference : 0000007c
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0
/* 2P NA PCIe2*/
[0001]                               Type : 02
[0002]                             Length : 0034
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
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
[0004]                 PCI Segment Number : 0000000a

[0004]                         Input base : 00001000
[0004]                           ID Count : 00001000
[0004]                        Output Base : 00021000
[0004]                   Output Reference : 00000234
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

/* 2P NB PCIe0*/
[0001]                               Type : 02
[0002]                             Length : 0034
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
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
[0004]                 PCI Segment Number : 0000000c

[0004]                         Input base : 00002000
[0004]                           ID Count : 00001000
[0004]                        Output Base : 00002000
[0004]                   Output Reference : 00000144
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

 /* 2P NB PCIe1*/
[0001]                               Type : 02
[0002]                             Length : 0034
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
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
[0004]                 PCI Segment Number : 0000000d

[0004]                         Input base : 00003000
[0004]                           ID Count : 00001000
[0004]                        Output Base : 00013000
[0004]                   Output Reference : 00000144
[0004]              Flags (decoded below) : 00000000
                           Single Mapping : 0

/* mbi-gen1 P1 dsa a, named component */
[0001]                               Type : 01
[0002]                             Length : 0046
[0001]                           Revision : 00
[0004]                           Reserved : 00000000
[0004]                      Mapping Count : 00000001
[0004]                     Mapping Offset : 00000032

[0004]                         Node Flags : 00000000
[0008]                  Memory Properties : [IORT Memory Access Properties]
[0004]                    Cache Coherency : 00000000
[0001]              Hints (decoded below) : 00
                               Transient : 0
                          Write Allocate : 0
                           Read Allocate : 0
                                Override : 0
[0002]                           Reserved : 0000
[0001]       Memory Flags (decoded below) : 00
                               Coherency : 0
                        Device Attribute : 0
[0001]                  Memory Size Limit : 00
[0016]                        Device Name : "\_SB_.MBI8"
[0004]                            Padding : 00 00 00 00

[0004]                         Input base : 00000000
[0004]                           ID Count : 00000001
[0004]                        Output Base : 00044800  //device id
[0004]                   Output Reference : 000000c4
[0004]              Flags (decoded below) : 00000001
                          Single Mapping : 1

[320h 0800   1]                         Type : 01
[321h 0801   2]                       Length : 0040
[323h 0803   1]                     Revision : 00
[324h 0804   4]                     Reserved : 00000000
[328h 0808   4]                Mapping Count : 00000001
[32Ch 0812   4]               Mapping Offset : 0000002C

[330h 0816   4]                   Node Flags : 00000000
[334h 0820   8]            Memory Properties : [IORT Memory Access Properties]
[334h 0820   4]              Cache Coherency : 00000000
[338h 0824   1]        Hints (decoded below) : 00
                                   Transient : 0
                              Write Allocate : 0
                               Read Allocate : 0
                                    Override : 0
[339h 0825   2]                     Reserved : 0000
[33Bh 0827   1] Memory Flags (decoded below) : 00
                                   Coherency : 0
                            Device Attribute : 0
[33Ch 0828   1]            Memory Size Limit : 00
[33Dh 0829  11]                  Device Name : "\_SB_.USB0"
[348h 0840  24]                      Padding : \
    00 00 00 00 00 00 00 00 01 00 00 00 80 00 04 00 \
    4C 00 00 00 01 00 00 00

[34Ch 0844   4]                   Input base : 00000000
[350h 0848   4]                     ID Count : 00000001
[354h 0852   4]                  Output Base : 00040080
[358h 0856   4]             Output Reference : 000000F4
[35Ch 0860   4]        Flags (decoded below) : 00000001
                              Single Mapping : 1

[360h 0864   1]                         Type : 01
[361h 0865   2]                       Length : 0040
[363h 0867   1]                     Revision : 00
[364h 0868   4]                     Reserved : 00000000
[368h 0872   4]                Mapping Count : 00000001
[36Ch 0876   4]               Mapping Offset : 0000002C

[370h 0880   4]                   Node Flags : 00000000
[374h 0884   8]            Memory Properties : [IORT Memory Access Properties]
[374h 0884   4]              Cache Coherency : 00000000
[378h 0888   1]        Hints (decoded below) : 00
                                   Transient : 0
                              Write Allocate : 0
                               Read Allocate : 0
                                    Override : 0
[379h 0889   2]                     Reserved : 0000
[37Bh 0891   1] Memory Flags (decoded below) : 00
                                   Coherency : 0
                            Device Attribute : 0
[37Ch 0892   1]            Memory Size Limit : 00
[37Dh 0893  11]                  Device Name : "\_SB_.SAS0"
[388h 0904  24]                      Padding : \
    00 00 00 00 00 00 00 00 01 00 00 00 00 01 00 00 \
    88 00 00 00 01 00 00 00

[38Ch 0908   4]                   Input base : 00000000
[390h 0912   4]                     ID Count : 00000001
[394h 0916   4]                  Output Base : 00040900
[398h 0920   4]             Output Reference : 000001a8
[39Ch 0924   4]        Flags (decoded below) : 00000001
                              Single Mapping : 1

[3A0h 0928   1]                         Type : 01
[3A1h 0929   2]                       Length : 0040
[3A3h 0931   1]                     Revision : 00
[3A4h 0932   4]                     Reserved : 00000000
[3A8h 0936   4]                Mapping Count : 00000001
[3ACh 0940   4]               Mapping Offset : 0000002C

[3B0h 0944   4]                   Node Flags : 00000000
[3B4h 0948   8]            Memory Properties : [IORT Memory Access Properties]
[3B4h 0948   4]              Cache Coherency : 00000000
[3B8h 0952   1]        Hints (decoded below) : 00
                                   Transient : 0
                              Write Allocate : 0
                               Read Allocate : 0
                                    Override : 0
[3B9h 0953   2]                     Reserved : 0000
[3BBh 0955   1] Memory Flags (decoded below) : 00
                                   Coherency : 0
                            Device Attribute : 0
[3BCh 0956   1]            Memory Size Limit : 00
[3BDh 0957  11]                  Device Name : "\_SB_.SAS1"
[3C8h 0968  24]                      Padding : \
    00 00 00 00 00 00 00 00 01 00 00 00 00 00 04 00 \
    4C 00 00 00 01 00 00 00

[3CCh 0972   4]                   Input base : 00000000
[3D0h 0976   4]                     ID Count : 00000001
[3D4h 0980   4]                  Output Base : 00040000
[3D8h 0984   4]             Output Reference : 000000F4
[3DCh 0988   4]        Flags (decoded below) : 00000001
                              Single Mapping : 1

[3E0h 0992   1]                         Type : 01
[3E1h 0993   2]                       Length : 0040
[3E3h 0995   1]                     Revision : 00
[3E4h 0996   4]                     Reserved : 00000000
[3E8h 1000   4]                Mapping Count : 00000001
[3ECh 1004   4]               Mapping Offset : 0000002C

[3F0h 1008   4]                   Node Flags : 00000000
[3F4h 1012   8]            Memory Properties : [IORT Memory Access Properties]
[3F4h 1012   4]              Cache Coherency : 00000000
[3F8h 1016   1]        Hints (decoded below) : 00
                                   Transient : 0
                              Write Allocate : 0
                               Read Allocate : 0
                                    Override : 0
[3F9h 1017   2]                     Reserved : 0000
[3FBh 1019   1] Memory Flags (decoded below) : 00
                                   Coherency : 0
                            Device Attribute : 0
[3FCh 1020   1]            Memory Size Limit : 00
[3FDh 1021  11]                  Device Name : "\_SB_.SAS2"
[408h 1032  24]                      Padding : \
    00 00 00 00 00 00 00 00 01 00 00 00 40 00 04 00 \
    4C 00 00 00 01 00 00 00

[40Ch 1036   4]                   Input base : 00000000
[410h 1040   4]                     ID Count : 00000001
[414h 1044   4]                  Output Base : 00040040
[418h 1048   4]             Output Reference : 000000F4
[41Ch 1052   4]        Flags (decoded below) : 00000001
                              Single Mapping : 1

/*HNS smmu*/
[420h 1056   1]                         Type : 01
[421h 1057   2]                       Length : 0040
[423h 1059   1]                     Revision : 00
[424h 1060   4]                     Reserved : 00000000
[428h 1064   4]                Mapping Count : 00000001
[42Ch 1068   4]               Mapping Offset : 0000002C

[430h 1072   4]                   Node Flags : 00000000
[434h 1076   8]            Memory Properties : [IORT Memory Access Properties]
[434h 1076   4]              Cache Coherency : 00000000
[438h 1080   1]        Hints (decoded below) : 00
                                   Transient : 0
                              Write Allocate : 0
                               Read Allocate : 0
                                    Override : 0
[439h 1081   2]                     Reserved : 0000
[43Bh 1083   1] Memory Flags (decoded below) : 00
                                   Coherency : 0
                            Device Attribute : 0
[43Ch 1084   1]            Memory Size Limit : 00
[43Dh 1085  11]                  Device Name : "\_SB_.DSF0"
[448h 1096  24]                      Padding : \
    00 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00 \
    94 01 00 00 01 00 00 00

[44Ch 1100   4]                   Input base : 00000000
[450h 1104   4]                     ID Count : 00000001
[454h 1108   4]                  Output Base : 00000000
[458h 1112   4]             Output Reference : 000001a8
[45Ch 1116   4]        Flags (decoded below) : 00000001
                              Single Mapping : 1
