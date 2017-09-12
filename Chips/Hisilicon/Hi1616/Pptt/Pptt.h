

#ifndef _PPTT_H_
#define _PPTT_H_


#include <IndustryStandard/Acpi.h>
//#include <IndustryStandard/SmBios.h>
//#include <Library/ArmLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Protocol/AcpiTable.h>
#include <Protocol/AcpiSystemDescriptionTable.h>
#include "Hi1616Platform.h"

///
/// "PPTT"  Processor Properties Topology Table
///
#define EFI_ACPI_6_2_PROCESSOR_PROPERTIES_TOPOLOGY_TABLE_SIGNATURE  SIGNATURE_32('P', 'P', 'T', 'T')
#define EFI_ACPI_6_2_PROCESSOR_PROPERTIES_TOPOLOGY_TABLE_REVISION 0x01
#define EFI_ACPI_MAX_NUM_TABLES         20

#define PPTT_TABLE_MAX_LEN   0x6000
//#define PPTT_PRIVATE_RESOURCE_MAX_LEN   0x2000

#define PPTT_SOCKET_NO   0x2
#define PPTT_DIE_NO   0x2
#define PPTT_CULSTER_NO   0x4
#define PPTT_CORE_NO   0x4

#define PPTT_SOCKET_COMPONENT_NO   0x1
//#define PPTT_DIE_COMPONENT_NO   0x0
#define PPTT_CACHE_NO   0x4


#define PPTT_TYPE0_PHYSICAL_PKG   BIT0
#define PPTT_TYPE0_PROCESSORID_VALID   BIT1
#define PPTT_TYPE0_SOCKET_FLAG   PPTT_TYPE0_PHYSICAL_PKG
#define PPTT_TYPE0_DIE_FLAG   PPTT_TYPE0_PHYSICAL_PKG
#define PPTT_TYPE0_CLUSTER_FLAG   0
#define PPTT_TYPE0_CORE_FLAG   PPTT_TYPE0_PROCESSORID_VALID


#define PPTT_TYPE1_SIZE_VALID   BIT0
#define PPTT_TYPE1_NUMBER_OF_SETS_VALID   BIT1
#define PPTT_TYPE1_ASSOCIATIVITY_VALID   BIT2
#define PPTT_TYPE1_ALLOCATION_TYPE_VALID   BIT3
#define PPTT_TYPE1_CACHE_TYPE_VALID   BIT4
#define PPTT_TYPE1_WRITE_POLICY_VALID   BIT5
#define PPTT_TYPE1_LINE_SIZE_VALID   BIT6


/*
//
// Cache Configuration
//
typedef union {
  struct {
    UINT16    Level           :3;
    UINT16    Socketed        :1;
    UINT16    Reserved1       :1;
    UINT16    Location        :2;
    UINT16    Enable          :1;
    UINT16    OperationalMode :2;
    UINT16    Reserved2       :6;
  } Bits;
  UINT16 Data;
}CACHE_CONFIGURATION;

typedef struct {
  UINT32                    SocketId;
  UINT32                    DieId;
  UINT32                    ClusterId;
  UINT32                    CoreId;
  UINT32                    Flags;
  UINT32                    AcpiProcessorUid;
} MADT_INFO;

typedef struct {
  UINT32                    Cluster0;
  UINT32                    Cluster1;
  UINT32                    Cluster2;
  UINT32                    Cluster3;
} CLUSTER_OFFSET_STRUCTURE;

typedef struct {
  UINT32                    Die0;
  CLUSTER_OFFSET_STRUCTURE Die0Cluster;
  UINT32                    Die1;
  CLUSTER_OFFSET_STRUCTURE Die1Cluster;
} DIE_OFFSET_STRUCTURE;

typedef struct {
  UINT32                    Socket0;
  DIE_OFFSET_STRUCTURE Socket0Die;
  UINT32                    Socket1;
  DIE_OFFSET_STRUCTURE Socket1Die;
} OFFSET_STRUCTURE;
*/

typedef union {
  struct {
    UINT32    InD           :1;
    UINT32    Level        :3;
    UINT32    Reserved  :28;
  } Bits;
  UINT32 Data;
}CSSELR_DATA;

typedef union {
  struct {
    UINT32    LineSize           :3;
    UINT32    Associativity    :10;
    UINT32    NumSets           :15;
    UINT32    Wa                    :1;
    UINT32    Ra                     :1;
    UINT32    Wb                    :1;
    UINT32    Wt                     :1;
  } Bits;
  UINT32 Data;
}CCSIDR_DATA;
//
// Processor Hierarchy Node Structure
//
typedef struct {
  UINT8                    Type;
  UINT8                    Length;
  UINT16                  Reserved;
  UINT32                  Flags;
  UINT32                  Parent;
  UINT32                  AcpiProcessorId;
  UINT32                  PrivateResourceNo;
} EFI_ACPI_6_2_PPTT_TYPE0;

//
// Cache Configuration
//
typedef union {
  struct {
    UINT8    AllocateType  :2;
    UINT8    CacheType      :2;
    UINT8    WritePolicy     :1;
    UINT8    Reserved        :3;
  } Bits;
  UINT8 Data;
}PPTT_TYPE1_ATTRIBUTES;

//
// Cache Type Structure
//
typedef struct {
  UINT8                    Type;
  UINT8                    Length;
  UINT16                  Reserved;
  UINT32                  Flags;
  UINT32                  NextLevelOfCache;
  UINT32                  Size;
  UINT32                  NumberOfSets;
  UINT8                    Associativity;
  UINT8                    Attributes;
  UINT16                  LineSize;
} EFI_ACPI_6_2_PPTT_TYPE1;

//
// ID Structure
//
typedef struct {
  UINT8                    Type;
  UINT8                    Length;
  UINT16                  Reserved;
  UINT32                  VendorId;
  UINT64                  Level1Id;
  UINT64                  Level2Id;
  UINT16                  MajorRev;
  UINT16                  MinorRev;
  UINT16                  SpinRev;
} EFI_ACPI_6_2_PPTT_TYPE2;

UINT32
ReadCCSIDR (
  IN UINT32 CSSELR
  );

#endif    // _PPTT_H_

