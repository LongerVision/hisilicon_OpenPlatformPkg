/** @file
*
*  Copyright (c) 2016 - 2017, Hisilicon Limited. All rights reserved.
*  Copyright (c) 2016 - 2017, Linaro Limited. All rights reserved.
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

#include <Uefi.h>
#include <Pi/PiBootMode.h>
#include <Pi/PiHob.h>
#include <Library/BaseLib.h>
#include <libfdt.h>
#include <Library/IoLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/FdtUpdateLib.h>
#include <Library/HobLib.h>
#include <PlatformArch.h>
#include <Library/PcdLib.h>
#include <Library/HwMemInitLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/OemMiscLib.h>
#include <Protocol/GenericMemoryTest.h>
#include <Library/OemConfigData.h>

typedef struct
{
  UINTN Base;
  UINTN Size;
}MEM_REGION;

typedef struct
{
  UINTN Base;
  UINTN Size;
  UINTN ScclIndex;
}MEM_MAP_REGION;

#define ScclCnt1616 4

PHY_MEM_REGION    *NodemRegion[4] = {NULL, NULL, NULL, NULL};

UINT8  Numa1616[ScclCnt1616] = {0, 0, 0, 0};
MEM_REGION   *MemRegion1616[ScclCnt1616] = {NULL, NULL, NULL, NULL};
UINTN  MemPages1616[ScclCnt1616] = {0, 0, 0, 0};

MEM_MAP_REGION   *MemMapRegion = NULL;
UINTN             MemMapRegionIndex = 0;

CHAR8  *MemName[ScclCnt1616]=
{
 "memory@0", "memory@1",
 "memory@2", "memory@3"
};

BOOLEAN DeviceTypeFoundFlag = FALSE;

STATIC
BOOLEAN
IsMemMapRegion (
  IN EFI_MEMORY_TYPE MemoryType
  )
{
  switch (MemoryType) {
    case EfiRuntimeServicesCode:
    case EfiRuntimeServicesData:
    case EfiConventionalMemory:
    case EfiACPIReclaimMemory:
    case EfiACPIMemoryNVS:
    case EfiLoaderCode:
    case EfiLoaderData:
    case EfiBootServicesCode:
    case EfiBootServicesData:
    case EfiPalCode:
      return TRUE;
    default:
      return FALSE;
  }
}

/**
Description:    Get Memory node infomation
Input:          fdt - fdt file
                Name - node name
Output:         NULL
Return:         INTN
**/
INTN
GetMemoryNode (
  VOID*  Fdt,
  CHAR8* Name
  )
{
  INTN                node;
  int                 m_oldlen;
  struct              fdt_property *m_prop;
  INTN                Error = 0;

  node = fdt_subnode_offset (Fdt, 0, Name);
  if (node < 0) {
    // Create the memory node
    node = fdt_add_subnode (Fdt, 0, Name);
    if (node < 0) {
      DEBUG((DEBUG_ERROR, "[%a]:[%dL] fdt add subnode error\n", __FUNCTION__, __LINE__));
      return node;
    }
  }

  //find the memory node property
  m_prop = fdt_get_property_w (Fdt, node, "reg", &m_oldlen);
  if (m_prop) {
    Error = fdt_delprop (Fdt, node, "reg");
    if (Error) {
      DEBUG ((DEBUG_ERROR, "ERROR: reg fdt_delprop (): %a\n", fdt_strerror (Error)));
      node = -1;
      return node;
    }
  }

  m_prop = fdt_get_property_w (Fdt, node, "numa-node-id", &m_oldlen);
  if (m_prop) {
    Error = fdt_delprop (Fdt, node, "numa-node-id");
    if (Error) {
      DEBUG ((DEBUG_ERROR, "ERROR:numa-node-id fdt_delprop (): %a\n", fdt_strerror (Error)));
      node = -1;
      return node;
    }
  }

  DeviceTypeFoundFlag = FALSE;
  m_prop = fdt_get_property_w (Fdt, node, "device_type", &m_oldlen);
  if (m_prop) {
    DeviceTypeFoundFlag = TRUE;
  }

  return node;
}


/**
Description:    Del Memory node infomation
Input:          fdt - fdt file
                Name - node name
Output:         NULL
Return:         INTN
**/
VOID
DeleteMemoryNode (
  VOID*  Fdt,
  CHAR8* Name)
{
  INTN                node;
  INTN                Error = 0;

  node = fdt_subnode_offset (Fdt, 0, Name);
  if (node < 0) {
    return;
  }else {
    Error = fdt_del_node (Fdt, node);
    if (Error) {
      DEBUG ((DEBUG_ERROR, "ERROR: reg fdt_del_node (): %a\n", fdt_strerror (Error)));
    }
  }

  return;
}

/**
Description:    For each Sccl allocated storage information about memory segment of
                the space, So that subsequent classification report
Input:          NULL
Output:         NULL
Return:         void
**/
VOID
AllocateNumaPage1616 (
  VOID
  )
{
  UINT8      i;

  for (i = 0; i < ScclCnt1616; i++) {
    if (Numa1616[i]) {
      MemPages1616[i] = EFI_SIZE_TO_PAGES (sizeof (MEM_REGION) *  Numa1616[i]);
      MemRegion1616[i] = (MEM_REGION*)AllocatePages (MemPages1616[i]);
    }
  }
}



STATIC
EFI_STATUS
GetNumaHi1616 (
  VOID
  )
{
  UINT8               Skt = 0;
  UINTN               Index = 0;
  VOID                *HobList;
  GBL_DATA            *Gbl_Data;
  UINTN               Base;
  UINTN               Size;
  UINT8               NodeId;
  UINT32              MemIndex0 = 0;
  UINT32              MemIndex1 = 0;
  UINT32              MemIndex2 = 0;
  UINT32              MemIndex3 = 0;
  HobList = GetHobList ();
  if (HobList == NULL) {
    return EFI_UNSUPPORTED;
  }
  Gbl_Data = (GBL_DATA*)GetNextGuidHob (&gHisiEfiMemoryMapGuid, HobList);
  if (Gbl_Data == NULL) {
    DEBUG ((DEBUG_ERROR, "Get next Guid HOb fail.\n"));
    return EFI_NOT_FOUND;
  }
  Gbl_Data = GET_GUID_HOB_DATA (Gbl_Data);
  for (Skt = 0; Skt < MAX_SOCKET; Skt++) {
    for (Index = 0; Index < MAX_NUM_PER_TYPE; Index++) {
      NodeId = Gbl_Data->NumaInfo[Skt][Index].NodeId;
      Size = Gbl_Data->NumaInfo[Skt][Index].Length;

      if ((Size > 0) && (NodeId == 0)) {
        Numa1616[0] = Numa1616[0] + 1;
      }
      if ((Size > 0) && (NodeId == 1)) {
        Numa1616[1] = Numa1616[1] + 1;
      }
      if (OemIsMpBoot ()) {
        if ((Size > 0) && (NodeId == 2)) {
          Numa1616[2] = Numa1616[2] + 1;
        }
        if ((Size > 0) && (NodeId == 3)) {
          Numa1616[3] = Numa1616[3] + 1;
        }
      }
    }
  }

  DEBUG ((DEBUG_INFO, "Numa[0] = %d, Numa[1] = %d, Numa[2] = %d, Numa[3] = %d \n", Numa1616[0], Numa1616[1], Numa1616[2], Numa1616[3]));

  AllocateNumaPage1616 ();

  for (Skt = 0; Skt < MAX_SOCKET; Skt++) {
    for (Index = 0; Index < MAX_NUM_PER_TYPE; Index++) {
      NodeId = Gbl_Data->NumaInfo[Skt][Index].NodeId;
      Base = Gbl_Data->NumaInfo[Skt][Index].Base;
      Size = Gbl_Data->NumaInfo[Skt][Index].Length;
      if ((NodeId == 0) && (Size> 0) && (MemIndex0 <= Numa1616[0])) {
        MemRegion1616[0][MemIndex0].Base = Base;
        MemRegion1616[0][MemIndex0].Size = Size;
        MemIndex0 += 1;
        DEBUG ((DEBUG_INFO, "0 Base = 0x%lx, Size = 0x%lx\n", Base, Size));
      }

      if ((NodeId == 1) && (Size> 0) && (MemIndex1 <= Numa1616[1])) {
        MemRegion1616[1][MemIndex1].Base = Base;
        MemRegion1616[1][MemIndex1].Size = Size;
        MemIndex1 += 1;
        DEBUG ((DEBUG_INFO, "1 Base = 0x%lx, Size = 0x%lx\n", Base, Size));
      }
    }
  }

  if (OemIsMpBoot ()) {
    for (Skt = 0; Skt < MAX_SOCKET; Skt++) {
      for (Index = 0; Index < MAX_NUM_PER_TYPE; Index++) {
        NodeId = Gbl_Data->NumaInfo[Skt][Index].NodeId;
        Base = Gbl_Data->NumaInfo[Skt][Index].Base;
        Size = Gbl_Data->NumaInfo[Skt][Index].Length;
        if ((NodeId == 2) && (Size> 0) && (MemIndex2 <= Numa1616[2])) {
          MemRegion1616[2][MemIndex2].Base = Base;
          MemRegion1616[2][MemIndex2].Size = Size;
          MemIndex2 += 1;
          DEBUG ((DEBUG_INFO, "2 Base = 0x%lx, Size = 0x%lx\n", Base, Size));
        }

        if ((NodeId == 3) && (Size> 0) && (MemIndex3 <= Numa1616[3])) {
          MemRegion1616[3][MemIndex3].Base = Base;
          MemRegion1616[3][MemIndex3].Size = Size;
          MemIndex3 += 1;
          DEBUG ((DEBUG_INFO, "3 Base = 0x%lx, Size = 0x%lx\n", Base, Size));
        }
      }
    }
  }

  return EFI_SUCCESS;
}

/**
Description:    Memory segment will be updated reports (No numa)
Input:          Fdt  - Fdt file pointer
Output:         NULL
Return:         EFI_STATUS
**/
EFI_STATUS
UpdateNodeNoNuma (
  VOID* Fdt
  )
{
  INTN              Error = 0;
  EFI_STATUS        Status = EFI_SUCCESS;
  INTN              node;
  PHY_MEM_REGION   *mRegion;
  UINTN             Pages0 = 0;
  UINTN             i, index = 0;
  UINTN             NumaId = 0;
  UINTN             MemoryMapLastEndAddress = 0;
  UINTN             MemoryMapcontinuousStartAddress = 0;
  UINTN             MemoryMapCurrentStartAddress = 0;
  UINT32            NumaVal = 0;
  UINTN             FirstFoundFlag = 0;

  //1,Find memory node
  node = GetMemoryNode (Fdt, MemName[0]);
  if (node < 0) {
    DEBUG ((DEBUG_ERROR, "UpdateNodeNoNuma Can not find memory node.\n"));
    return EFI_NOT_FOUND;
  }

  //2.Apply for memory
  mRegion = NULL;
  Pages0 = EFI_SIZE_TO_PAGES (sizeof (PHY_MEM_REGION) * (MemMapRegionIndex));
  mRegion = (PHY_MEM_REGION*)AllocatePages (Pages0);
  if (mRegion == NULL) {
    DEBUG((DEBUG_ERROR, "UpdateNodeNoNuma out of resources!! \n"));
    Status = EFI_OUT_OF_RESOURCES;
    return Status;
  }

  //3.Looking for matching the numa node memory segments, And integrate continuous memory segments reported together
  for (i = 0; i < MemMapRegionIndex; i++) {
    FirstFoundFlag++;
    MemoryMapCurrentStartAddress = MemMapRegion[i].Base;
    if (FirstFoundFlag == 1) {
      MemoryMapLastEndAddress = MemMapRegion[i].Base + MemMapRegion[i].Size;
      MemoryMapcontinuousStartAddress = MemoryMapCurrentStartAddress;
      continue;
    }

    if (MemoryMapCurrentStartAddress != MemoryMapLastEndAddress) {
      mRegion[index].BaseHigh = cpu_to_fdt32 (MemoryMapcontinuousStartAddress >> 32);
      mRegion[index].BaseLow = cpu_to_fdt32 (MemoryMapcontinuousStartAddress);
      mRegion[index].LengthHigh = cpu_to_fdt32 ((MemoryMapLastEndAddress - MemoryMapcontinuousStartAddress) >> 32);
      mRegion[index].LengthLow = cpu_to_fdt32 (MemoryMapLastEndAddress - MemoryMapcontinuousStartAddress);
      index++;
      MemoryMapcontinuousStartAddress = MemoryMapCurrentStartAddress;
    }
    MemoryMapLastEndAddress = MemMapRegion[i].Base + MemMapRegion[i].Size;
  }

  mRegion[index].BaseHigh = cpu_to_fdt32 (MemoryMapcontinuousStartAddress >> 32);
  mRegion[index].BaseLow = cpu_to_fdt32 (MemoryMapcontinuousStartAddress);
  mRegion[index].LengthHigh = cpu_to_fdt32 ((MemoryMapLastEndAddress - MemoryMapcontinuousStartAddress) >> 32);
  mRegion[index].LengthLow = cpu_to_fdt32 (MemoryMapLastEndAddress - MemoryMapcontinuousStartAddress);

  //4.Update the values of the Reg and Numa-node-id properties in the memory node
  Error = fdt_setprop (Fdt, node, "reg", mRegion, sizeof (PHY_MEM_REGION) * (index + 1));
  if (Error) {
    DEBUG ((DEBUG_ERROR, "ERROR: fdt_setprop (): %a\n", fdt_strerror (Error)));
    Status = EFI_INVALID_PARAMETER;
    goto Exit;
  }

  NumaVal = cpu_to_fdt32 (NumaId);

  Error = fdt_setprop (Fdt, node, "numa-node-id", &NumaVal, sizeof (UINT32));
  if (Error) {
    DEBUG ((DEBUG_ERROR, "ERROR: numa-node-id fdt_setprop (): %a\n", fdt_strerror (Error)));
    Status = EFI_INVALID_PARAMETER;
  }

Exit:
  FreePages (mRegion, Pages0);
  return Status;
}

/**
Description:    Traverse all memory segments and mark the NUMA node to which the memory segment belongs
Input:          Sccl - Affiliated Sccl
Output:         NULL
Return:         VOID
**/
VOID
GetScclIndex1616 (
  UINTN Sccl
  )
{
  UINTN MapIndex;
  UINTN NumaIndex;

  for (MapIndex = 0; MapIndex < MemMapRegionIndex; MapIndex++) {
    for (NumaIndex = 0; NumaIndex < Numa1616[Sccl]; NumaIndex++) {
      if (((MemMapRegion[MapIndex].Base + MemMapRegion[MapIndex].Size)  <= (MemRegion1616[Sccl][NumaIndex].Base + MemRegion1616[Sccl][NumaIndex].Size))
        && ((MemMapRegion[MapIndex].Base) >= (MemRegion1616[Sccl][NumaIndex].Base))) {
        MemMapRegion[MapIndex].ScclIndex = Sccl;
      }
    }
  }
}

/**
Description:    Complying with the numa node memory segment update report
Input:          Fdt  - Fdt file pointer
                ScclIndex - Affiliated Sccl
Output:         NULL
Return:         EFI_STATUS
**/
EFI_STATUS
LoUpdateNumaNode(
  VOID* Fdt,
  UINTN ScclIndex
  )
{
  INTN              Error = 0;
  EFI_STATUS        Status = EFI_SUCCESS;
  INTN        node;
  PHY_MEM_REGION   *mRegion = NULL;
  UINTN             Pages0 = 0;
  UINTN             i, index= 0;
  UINTN             ScclCnt = 0;
  UINTN             MemoryMapLastEndAddress = 0;
  UINTN             MemoryMapcontinuousStartAddress = 0;
  UINTN             MemoryMapCurrentStartAddress = 0;
  BOOLEAN           FindMemoryRegionFlag = FALSE;
  UINT32            NumaVal = 0;
  UINTN             FirstFoundFlag = 0;

  //1,Find memory node
  node = GetMemoryNode (Fdt, MemName[ScclIndex]);
  if (node < 0) {
    DEBUG ((DEBUG_ERROR, "UpdateNodeNoNuma Can not find memory node.\n"));
    return EFI_NOT_FOUND;
  }

  //2.Traverse summary belongs to the numa node memory segments, So that subsequent variables of the memory application
  for(i = 0; i < MemMapRegionIndex; i++) {
    if(ScclIndex == MemMapRegion[i].ScclIndex) {
      ScclCnt++;
    }
  }

  //3.Apply for memory
  Pages0 = EFI_SIZE_TO_PAGES (sizeof (PHY_MEM_REGION) * (ScclCnt));
  mRegion = (PHY_MEM_REGION*)AllocatePages (Pages0);
  if (mRegion == NULL) {
    DEBUG ((DEBUG_ERROR, "UpdateNodeNoNuma out of resources!! \n"));
    Status = EFI_OUT_OF_RESOURCES;
    return Status;
  }

  //4.Looking for matching the numa node memory segments, And integrate continuous memory segments reported together
  for (i = 0; i < MemMapRegionIndex; i++) {
    if (ScclIndex == MemMapRegion[i].ScclIndex) {
      FindMemoryRegionFlag = TRUE;
      FirstFoundFlag++;
      MemoryMapCurrentStartAddress = MemMapRegion[i].Base;
      if (FirstFoundFlag == 1) {
        MemoryMapLastEndAddress = MemMapRegion[i].Base + MemMapRegion[i].Size;
        MemoryMapcontinuousStartAddress = MemoryMapCurrentStartAddress;
        continue;
      }

      if (MemoryMapCurrentStartAddress != MemoryMapLastEndAddress) {
        mRegion[index].BaseHigh = cpu_to_fdt32 (MemoryMapcontinuousStartAddress >> 32);
        mRegion[index].BaseLow = cpu_to_fdt32 (MemoryMapcontinuousStartAddress);
        mRegion[index].LengthHigh = cpu_to_fdt32 ((MemoryMapLastEndAddress - MemoryMapcontinuousStartAddress) >> 32);
        mRegion[index].LengthLow = cpu_to_fdt32 (MemoryMapLastEndAddress - MemoryMapcontinuousStartAddress);
        index++;
        MemoryMapcontinuousStartAddress = MemoryMapCurrentStartAddress;
      }
      MemoryMapLastEndAddress = MemMapRegion[i].Base + MemMapRegion[i].Size;
    }
  }

  if (FindMemoryRegionFlag) {
    mRegion[index].BaseHigh = cpu_to_fdt32 (MemoryMapcontinuousStartAddress >> 32);
    mRegion[index].BaseLow = cpu_to_fdt32 (MemoryMapcontinuousStartAddress);
    mRegion[index].LengthHigh = cpu_to_fdt32 ((MemoryMapLastEndAddress - MemoryMapcontinuousStartAddress) >> 32);
    mRegion[index].LengthLow = cpu_to_fdt32 (MemoryMapLastEndAddress - MemoryMapcontinuousStartAddress);
  }

  //5.Update the values of the Reg and Numa-node-id properties in the memory node
  Error = fdt_setprop (Fdt, node, "reg", mRegion, sizeof (PHY_MEM_REGION) * (index + 1));
  if (Error) {
    DEBUG ((DEBUG_ERROR, "ERROR: reg fdt_setprop(): %a\n", fdt_strerror (Error)));
    Status = EFI_INVALID_PARAMETER;
    goto Exit;
  }

  NumaVal = cpu_to_fdt32 (ScclIndex);
  Error = fdt_setprop (Fdt, node, "numa-node-id", &NumaVal, sizeof (UINT32));
  if (Error) {
    DEBUG ((DEBUG_ERROR, "ERROR: numa-node-id fdt_setprop(): %a\n", fdt_strerror (Error)));
    Status = EFI_INVALID_PARAMETER;
  }

  if (!DeviceTypeFoundFlag) {
    Error = fdt_setprop (Fdt, node, "device_type", "memory", AsciiStrSize ("memory"));
    if (Error) {
      DEBUG ((DEBUG_ERROR, "ERROR: device_type fdt_setprop (): %a\n", fdt_strerror (Error)));
      Status = EFI_INVALID_PARAMETER;
    }
  }

Exit:
  FreePages (mRegion, Pages0);
  return Status;
}


/**
Description:    Of Memory Segment cross-Sccl border comparison
Input:          Base   --  Memory segment Base address
                Size   --  Size of a memory segment
                ScclIndex --  Sccl Serial Number
Output:         NULL
Return:         NULL
**/
BOOLEAN
CheckParam1616 (
  UINTN Base,
  UINTN Size,
  UINTN ScclIndex
  )
{
    //1.Ensure that the NUMA node in memory segment
    //2.The input Base + Size must be greater than the Sccl maximum boundary do not need to perform a Sccl segmentation, Otherwise, the memory segment to this Sccl can be ended, Do not need to split
    //3.Must be greater than the Sccl Base, Otherwise, belongs to a range of Sccl
    if ((0 < Numa1616[ScclIndex]) && ((Base + Size)  > (MemRegion1616[ScclIndex][Numa1616[ScclIndex] - 1].Base + MemRegion1616[ScclIndex][Numa1616[ScclIndex] - 1].Size))
      && (Base >= (MemRegion1616[ScclIndex][0].Base))) {
      return TRUE;
    }
    return FALSE;
}




/**
Description:    The input memory segment sequence number, Of the leaking memory cross-Sccl border comparison, And segmentation
Input:          MapIndex   --  Memory segment sequence number
Output:         NULL
Return:         NULL
**/
VOID
CompareMemMapAndNuma1616 (
  UINTN MapIndex
  )
{
  MEM_MAP_REGION  MemRegionLast;
  MEM_MAP_REGION *MemRegionAllocate = NULL;
  UINTN           Pages = 0;

  MemRegionLast.Base = MemMapRegion[MapIndex].Base;
  MemRegionLast.Size = MemMapRegion[MapIndex].Size;
  MemRegionLast.ScclIndex = MemMapRegion[MapIndex].ScclIndex;

  if (CheckParam1616 (MemMapRegion[MapIndex].Base, MemMapRegion[MapIndex].Size, 2) && (MemMapRegion[MapIndex].ScclIndex == 2)) {
    MemMapRegion[MapIndex].Size = MemRegion1616[2][Numa1616[2] - 1].Base + MemRegion1616[2][Numa1616[2] - 1].Size - MemMapRegion[MapIndex].Base;
    MemMapRegion[MapIndex].ScclIndex = 2;

    MemRegionLast.Base = (MemRegion1616[2][Numa1616[2] - 1].Base + MemRegion1616[2][Numa1616[2] - 1].Size);
    MemRegionLast.Size = MemRegionLast.Size - (MemRegion1616[2][Numa1616[2] - 1].Base + MemRegion1616[2][Numa1616[2] - 1].Size - MemMapRegion[MapIndex].Base);

    MemMapRegionIndex++;
    Pages = EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION) * (MemMapRegionIndex));
    MemRegionAllocate = (MEM_MAP_REGION*)AllocatePages (Pages);

    (VOID) CopyMem (MemRegionAllocate, MemMapRegion, sizeof (MEM_MAP_REGION) * (MemMapRegionIndex - 1));
    MemRegionAllocate[MemMapRegionIndex - 1].Base = MemRegionLast.Base;
    MemRegionAllocate[MemMapRegionIndex - 1].Size = MemRegionLast.Size;
    MemRegionAllocate[MemMapRegionIndex - 1].ScclIndex = 3;

    FreePages (MemMapRegion, Pages - EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION)));
    MemMapRegion = MemRegionAllocate;
  }
  else if (CheckParam1616 (MemMapRegion[MapIndex].Base, MemMapRegion[MapIndex].Size, 1) && (MemMapRegion[MapIndex].ScclIndex == 1)) {
    MemMapRegion[MapIndex].Size = MemRegion1616[1][Numa1616[0] - 1].Base + MemRegion1616[1][Numa1616[0] - 1].Size - MemMapRegion[MapIndex].Base;
    MemMapRegion[MapIndex].ScclIndex = 1;

    MemRegionLast.Base = (MemRegion1616[1][Numa1616[1] - 1].Base + MemRegion1616[1][Numa1616[1] - 1].Size);
    MemRegionLast.Size = MemRegionLast.Size - (MemRegion1616[1][Numa1616[1] - 1].Base + MemRegion1616[1][Numa1616[1] - 1].Size - MemMapRegion[MapIndex].Base);

    if (CheckParam1616 (MemRegionLast.Base, MemRegionLast.Size, 2)) {
      MemMapRegionIndex++;
      Pages = EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION) * (MemMapRegionIndex));
      MemRegionAllocate = (MEM_MAP_REGION*)AllocatePages (Pages);

      (VOID) CopyMem (MemRegionAllocate, MemMapRegion, sizeof (MEM_MAP_REGION) * (MemMapRegionIndex - 1));
      MemRegionAllocate[MemMapRegionIndex - 1].Base = MemRegionLast.Base;
      MemRegionAllocate[MemMapRegionIndex - 1].Size = (MemRegion1616[2][Numa1616[2] - 1].Base + MemRegion1616[2][Numa1616[2] - 1].Size) - (MemRegion1616[2][0].Base);
      MemRegionAllocate[MemMapRegionIndex - 1].ScclIndex = 2;

      FreePages (MemMapRegion, Pages - EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION)));
      MemMapRegion = MemRegionAllocate;

      MemRegionLast.Base = (MemRegion1616[2][Numa1616[2] - 1].Base + MemRegion1616[2][Numa1616[2] - 1].Size);
      MemRegionLast.Size = MemRegionLast.Size - (MemRegion1616[2][Numa1616[2] - 1].Base + MemRegion1616[2][Numa1616[2] - 1].Size - MemRegion1616[2][0].Base);

      MemMapRegionIndex++;

      Pages = EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION) * (MemMapRegionIndex));
      MemRegionAllocate = (MEM_MAP_REGION*)AllocatePages (Pages);

      (VOID) CopyMem (MemRegionAllocate, MemMapRegion, sizeof (MEM_MAP_REGION) * (MemMapRegionIndex - 1));
      MemRegionAllocate[MemMapRegionIndex - 1].Base = MemRegionLast.Base;
      MemRegionAllocate[MemMapRegionIndex - 1].Size = MemRegionLast.Size;
      MemRegionAllocate[MemMapRegionIndex - 1].ScclIndex = 3;

      FreePages (MemMapRegion, Pages - EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION)));
      MemMapRegion = MemRegionAllocate;
    }else {
      MemMapRegionIndex++;
      Pages = EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION) * (MemMapRegionIndex));
      MemRegionAllocate = (MEM_MAP_REGION*)AllocatePages (Pages);

      (VOID) CopyMem (MemRegionAllocate, MemMapRegion, sizeof (MEM_MAP_REGION) * (MemMapRegionIndex - 1));
      MemRegionAllocate[MemMapRegionIndex - 1].Base = MemRegionLast.Base;
      MemRegionAllocate[MemMapRegionIndex - 1].Size = MemRegionLast.Size;
      MemRegionAllocate[MemMapRegionIndex - 1].ScclIndex = 1;

      FreePages (MemMapRegion, Pages - EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION)));
      MemMapRegion = MemRegionAllocate;
    }
  }
  else if (CheckParam1616 (MemMapRegion[MapIndex].Base, MemMapRegion[MapIndex].Size, 0) && (MemMapRegion[MapIndex].ScclIndex == 0)) {
    MemMapRegion[MapIndex].Size = MemRegion1616[0][Numa1616[0] - 1].Base + MemRegion1616[0][Numa1616[0] - 1].Size - MemMapRegion[MapIndex].Base;
    MemMapRegion[MapIndex].ScclIndex = 0;

    MemRegionLast.Base = (MemRegion1616[0][Numa1616[0] - 1].Base + MemRegion1616[0][Numa1616[0] - 1].Size);
    MemRegionLast.Size = MemRegionLast.Size - (MemRegion1616[0][Numa1616[0] - 1].Base + MemRegion1616[0][Numa1616[0] - 1].Size - MemMapRegion[MapIndex].Base);

    if (CheckParam1616 (MemRegionLast.Base, MemRegionLast.Size, 1)) {
      MemMapRegionIndex++;
      Pages = EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION) * (MemMapRegionIndex));
      MemRegionAllocate = (MEM_MAP_REGION*)AllocatePages (Pages);

      (VOID) CopyMem (MemRegionAllocate, MemMapRegion, sizeof (MEM_MAP_REGION) * (MemMapRegionIndex - 1));
      MemRegionAllocate[MemMapRegionIndex - 1].Base = MemRegionLast.Base;
      MemRegionAllocate[MemMapRegionIndex - 1].Size = (MemRegion1616[1][Numa1616[1] - 1].Base + MemRegion1616[1][Numa1616[1] - 1].Size) - (MemRegion1616[1][0].Base);
      MemRegionAllocate[MemMapRegionIndex - 1].ScclIndex = 1;

      FreePages (MemMapRegion, Pages - EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION)));
      MemMapRegion = MemRegionAllocate;

      MemRegionLast.Base = (MemRegion1616[1][Numa1616[1] - 1].Base + MemRegion1616[1][Numa1616[1] - 1].Size);
      MemRegionLast.Size = MemRegionLast.Size - (MemRegion1616[1][Numa1616[1] - 1].Base + MemRegion1616[1][Numa1616[1] - 1].Size - MemRegion1616[1][0].Base);

      if (CheckParam1616 (MemRegionLast.Base, MemRegionLast.Size, 2)) {
        MemMapRegionIndex++;
        Pages = EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION) * (MemMapRegionIndex));
        MemRegionAllocate = (MEM_MAP_REGION*)AllocatePages (Pages);

        (VOID) CopyMem (MemRegionAllocate, MemMapRegion, sizeof (MEM_MAP_REGION) * (MemMapRegionIndex - 1));
        MemRegionAllocate[MemMapRegionIndex - 1].Base = MemRegionLast.Base;
        MemRegionAllocate[MemMapRegionIndex - 1].Size = (MemRegion1616[2][Numa1616[2] - 1].Base + MemRegion1616[2][Numa1616[2] - 1].Size) - (MemRegion1616[2][0].Base);
        MemRegionAllocate[MemMapRegionIndex - 1].ScclIndex = 2;

        FreePages (MemMapRegion, Pages - EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION)));
        MemMapRegion = MemRegionAllocate;

        MemRegionLast.Base = (MemRegion1616[2][Numa1616[2] - 1].Base + MemRegion1616[2][Numa1616[2] - 1].Size);
        MemRegionLast.Size = MemRegionLast.Size - (MemRegion1616[2][Numa1616[2] - 1].Base + MemRegion1616[2][Numa1616[2] - 1].Size - MemRegion1616[2][0].Base);

        MemMapRegionIndex++;

        Pages = EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION) * (MemMapRegionIndex));
        MemRegionAllocate = (MEM_MAP_REGION*)AllocatePages (Pages);

        (VOID) CopyMem (MemRegionAllocate, MemMapRegion, sizeof (MEM_MAP_REGION) * (MemMapRegionIndex - 1));
        MemRegionAllocate[MemMapRegionIndex - 1].Base = MemRegionLast.Base;
        MemRegionAllocate[MemMapRegionIndex - 1].Size = MemRegionLast.Size;
        MemRegionAllocate[MemMapRegionIndex - 1].ScclIndex = 3;

        FreePages (MemMapRegion, Pages - EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION)));
        MemMapRegion = MemRegionAllocate;
      }else
      {
        MemMapRegionIndex++;
        Pages = EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION) * (MemMapRegionIndex));
        MemRegionAllocate = (MEM_MAP_REGION*)AllocatePages (Pages);

        (VOID) CopyMem (MemRegionAllocate, MemMapRegion, sizeof (MEM_MAP_REGION) * (MemMapRegionIndex - 1));
        MemRegionAllocate[MemMapRegionIndex - 1].Base = MemRegionLast.Base;
        MemRegionAllocate[MemMapRegionIndex - 1].Size = MemRegionLast.Size;
        MemRegionAllocate[MemMapRegionIndex - 1].ScclIndex = 2;

        FreePages (MemMapRegion, Pages - EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION)));
        MemMapRegion = MemRegionAllocate;
      }
    }else
    {
      MemMapRegionIndex++;
      Pages = EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION) * (MemMapRegionIndex));
      MemRegionAllocate = (MEM_MAP_REGION*)AllocatePages (Pages);

      (VOID) CopyMem (MemRegionAllocate, MemMapRegion, sizeof (MEM_MAP_REGION) * (MemMapRegionIndex - 1));
      MemRegionAllocate[MemMapRegionIndex - 1].Base = MemRegionLast.Base;
      MemRegionAllocate[MemMapRegionIndex - 1].Size = MemRegionLast.Size;
      MemRegionAllocate[MemMapRegionIndex - 1].ScclIndex = 1;

      FreePages (MemMapRegion, Pages - EFI_SIZE_TO_PAGES (sizeof (MEM_MAP_REGION)));
      MemMapRegion = MemRegionAllocate;
    }
  }
}

/**
Description:    Traverse all memmap memory segment, Cross-Sccl handle
Input:          NULL
Output:         NULL
Return:         NULL
**/
VOID
ScclSpanOperation1616 (
  VOID
  )
{
  UINTN MapIndex;
  UINTN MemMapRegionCnt;
  MemMapRegionCnt = MemMapRegionIndex;
  for (MapIndex = 0; MapIndex < MemMapRegionCnt; MapIndex++) {
    CompareMemMapAndNuma1616 (MapIndex);
  }
}

/**
Description:    All the acquired Memmap memory segment Base and each Sccl minimum Base compared
Input:          NULL
Output:         NULL
Return:         NULL
**/
VOID
SetOriScclIndex1616 (
  VOID
  )
{
  UINTN MapIndex;
  UINTN ScclIndex;

  for (MapIndex = 0; MapIndex < MemMapRegionIndex; MapIndex++) {
    for (ScclIndex = 0 ; ScclIndex < ScclCnt1616; ScclIndex++) {
      if ((0 < Numa1616[ScclCnt1616 - ScclIndex - 1]) && ((MemMapRegion[MapIndex].Base) >= (MemRegion1616[ScclCnt1616 - ScclIndex - 1][0].Base))) {
        MemMapRegion[MapIndex].ScclIndex = ScclCnt1616 - ScclIndex - 1;
        break;
      }
    }
  }
}

/**
Description:    Will satisfy all numa node memory segment update report
Input:          Fdt  - Fdt file pointer
Output:         NULL
Return:         EFI_STATUS
**/
EFI_STATUS
UpdateHi1616NumaNode (
  VOID* Fdt
  )
{
  EFI_STATUS Status = EFI_SUCCESS;
  UINTN  ScclIndex;

  GetNumaHi1616 ();

  SetOriScclIndex1616 ();

  ScclSpanOperation1616 ();

  for (ScclIndex = 0; ScclIndex < ScclCnt1616; ScclIndex++) {
    if (Numa1616[ScclIndex] == 0) {
      DeleteMemoryNode (Fdt, MemName[ScclIndex]);
    }

    if (0 < Numa1616[ScclIndex]) {
      GetScclIndex1616 (ScclIndex);
      Status = LoUpdateNumaNode (Fdt, ScclIndex);
      if (EFI_ERROR (Status)) {
        DEBUG ((DEBUG_ERROR, "UpdateHi1616NumaNode fail\n"));
      }
    }
  }

  //Has been reporting task, Release all the information about memory segment
  for (ScclIndex = 0; ScclIndex < ScclCnt1616; ScclIndex++) {
    if (0 < Numa1616[ScclIndex]) {
      FreePages (MemRegion1616[ScclIndex], MemPages1616[ScclIndex]);
    }
  }

  return Status;
}


EFI_STATUS
FdtUpdateAtNumaEnable(
  VOID* Fdt
  )
{
  EFI_STATUS Status = EFI_SUCCESS;

  Status = UpdateHi1616NumaNode(Fdt);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "UpdateHi1616 NumaNode fail\n"));
  }
  return Status;
}




EFI_STATUS
UpdateNode(
  VOID* Fdt
  )
{
  UINTN              Size = sizeof (OEM_CONFIG_DATA);
  OEM_CONFIG_DATA    SetupData;
  EFI_STATUS Status = EFI_SUCCESS;

  Status = gRT->GetVariable (
                  OEM_CONFIG_NAME,
                  &gOemConfigGuid,
                  NULL,
                  &Size,
                  &SetupData
                  );

  if (!EFI_ERROR (Status)) {
    if (SetupData.NumaEn) {
      DEBUG ((EFI_D_INFO, "FdtUpdateAtNuma setup Enabled\n"));
      Status = FdtUpdateAtNumaEnable (Fdt);
      if (EFI_ERROR (Status)) {
        DEBUG ((DEBUG_ERROR, "FdtUpdateAtNumaEnable 0 fail\n"));
      }
      return Status;
    } else {
      DEBUG ((EFI_D_INFO, "FdtUpdateAtNuma no numa\n"));
      Status = UpdateNodeNoNuma (Fdt);
      if (EFI_ERROR (Status)) {
        DEBUG ((DEBUG_ERROR, "Update NO Numa Node 0 fail\n"));
      }
      return Status;
    }
  }

  return Status;
}

/**
Description:    Obtain system in all the memory segments that meet the reporting, And summary
Input:          NULL
Output:         NULL
Return:         EFI_STATUS
**/
EFI_STATUS
GetMemmapRegion ()
{
  EFI_STATUS          Status = EFI_SUCCESS;
  UINT32              Index = 0;
  EFI_MEMORY_DESCRIPTOR *MemoryMap;
  EFI_MEMORY_DESCRIPTOR *MemoryMapPtr;
  EFI_MEMORY_DESCRIPTOR *MemoryMapPtrCurrent;
  UINTN                 MemoryMapSize;
  UINTN                 Pages0 = 0;
  UINTN                 Pages1 = 0;
  UINTN                 MapKey;
  UINTN                 DescriptorSize;
  UINT32                DescriptorVersion;
  EFI_GENERIC_MEMORY_TEST_PROTOCOL*   MemoryTest = NULL;
  BOOLEAN                             RequireSoftECCInit = FALSE;

  //1, Obtain the current system memory layout
  MemoryMap = NULL;
  MemoryMapSize = 0;

  Status = gBS->LocateProtocol (&gEfiGenericMemTestProtocolGuid, NULL, (VOID**)&MemoryTest);
  if (!EFI_ERROR (Status)) {
    (VOID) MemoryTest->MemoryTestInit (MemoryTest, IGNORE, &RequireSoftECCInit);
  } else {
    DEBUG((DEBUG_ERROR,"LocateProtocol for gEfiGenericMemTestProtocolGuid fail\n"));
  }

  Status = gBS->GetMemoryMap (&MemoryMapSize, MemoryMap, &MapKey, &DescriptorSize, &DescriptorVersion);
  if (Status == EFI_BUFFER_TOO_SMALL) {
    // The UEFI specification advises to allocate more memory for the MemoryMap buffer between successive
    // calls to GetMemoryMap (), since allocation of the new buffer may potentially increase memory map size.
    Pages0 = EFI_SIZE_TO_PAGES (MemoryMapSize) + 1;
    MemoryMap = AllocatePages (Pages0);
    if (MemoryMap == NULL) {
      Status = EFI_OUT_OF_RESOURCES;
      return Status;
    }
    Status = gBS->GetMemoryMap (&MemoryMapSize, MemoryMap, &MapKey, &DescriptorSize, &DescriptorVersion);

    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "FdtUpdateLib GetMemoryMap Error\n"));
      FreePages (MemoryMap, Pages0);
      return Status;
    }
  } else {
    DEBUG ((DEBUG_ERROR, "FdtUpdateLib GetmemoryMap Status: %r\n", Status));
    return EFI_ABORTED;
  }

  MemMapRegion = NULL;
  Pages1 = EFI_SIZE_TO_PAGES (sizeof(MEM_MAP_REGION) *( MemoryMapSize / DescriptorSize));

  MemMapRegion = (MEM_MAP_REGION*)AllocatePages (Pages1);
  if (MemMapRegion == NULL) {
    Status = EFI_OUT_OF_RESOURCES;
    FreePages (MemoryMap, Pages0);
    return Status;
  }

  //2, Traversal of contiguous memory space, continuous memory space integration in one block
  MemoryMapPtr = MemoryMap;
  MemoryMapPtrCurrent = MemoryMapPtr;
  for (Index = 0; Index < (MemoryMapSize / DescriptorSize); Index++) {
    MemoryMapPtrCurrent = (EFI_MEMORY_DESCRIPTOR*)((UINTN) MemoryMapPtr + Index * DescriptorSize);
    if (!IsMemMapRegion ((EFI_MEMORY_TYPE)MemoryMapPtrCurrent->Type)) {
      continue;
    } else {
      MemMapRegion[MemMapRegionIndex].Base= (UINTN) MemoryMapPtrCurrent->PhysicalStart;
      MemMapRegion[MemMapRegionIndex].Size= (UINTN) (MemoryMapPtrCurrent->NumberOfPages * EFI_PAGE_SIZE);
      MemMapRegionIndex+=1;
    }
  }

  FreePages (MemoryMap, Pages0);
  return Status;
}


/**
Description:    Update memory node general entry
Input:          FDT  -- Fdt file
Output:         NULL
Return:         EFI_STATUS
**/
EFI_STATUS UpdateMemoryNode (
  VOID* Fdt
  )
{
  EFI_STATUS          Status = EFI_SUCCESS;

  Status = GetMemmapRegion ();
  if(EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "ERROR: Get Memmap Region fail!!!\n"));
  }
  Status = UpdateNode (Fdt);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "ERROR: Update Memory Node fail!!!\n"));
  }
  return Status;
}

/*
 * Entry point for fdtupdate lib.
 */

EFI_STATUS EFIFdtUpdate (
  UINTN FdtFileAddr
  )
{
  INTN                Error;
  VOID*               Fdt;
  UINT32              Size;
  UINTN               NewFdtBlobSize;
  UINTN               NewFdtBlobBase;
  EFI_STATUS          Status = EFI_SUCCESS;


  Error = fdt_check_header ((VOID*)(FdtFileAddr));
  if (Error != 0) {
    DEBUG ((DEBUG_ERROR, "ERROR: Device Tree header not valid (%a)\n", fdt_strerror (Error)));
    return EFI_INVALID_PARAMETER;
  }

  Size = (UINTN) fdt_totalsize ((VOID*)(UINTN) (FdtFileAddr));
  NewFdtBlobSize = Size + ADD_FILE_LENGTH;
  Fdt = (VOID*)(UINTN) FdtFileAddr;

  Status = gBS->AllocatePages (AllocateAnyPages, EfiBootServicesData, EFI_SIZE_TO_PAGES (NewFdtBlobSize), &NewFdtBlobBase);
  if (EFI_ERROR (Status)) {
    return EFI_OUT_OF_RESOURCES;
  }


  Error = fdt_open_into (Fdt,(VOID*)(UINTN) (NewFdtBlobBase), (NewFdtBlobSize));
  if (Error) {
    DEBUG ((DEBUG_ERROR, "ERROR: fdt_open_into (): %a\n", fdt_strerror (Error)));
    Status = EFI_INVALID_PARAMETER;
    goto EXIT;
  }

  Fdt = (VOID*)(UINTN) NewFdtBlobBase;

  Status = UpdateMemoryNode (Fdt);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "UpdateMemoryNode Error\n"));
    goto EXIT;
  }

  //The memory copy to the original position
  gBS->CopyMem (((VOID*)(UINTN) (FdtFileAddr)), ((VOID*)(UINTN) (NewFdtBlobBase)), NewFdtBlobSize);

EXIT:
  //Release memory
  gBS->FreePages (NewFdtBlobBase, EFI_SIZE_TO_PAGES (NewFdtBlobSize));

  return Status;

}
