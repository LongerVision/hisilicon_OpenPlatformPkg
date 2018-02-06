
#include "Pptt.h"

EFI_ACPI_TABLE_PROTOCOL       *mAcpiTableProtocol = NULL;
EFI_ACPI_SDT_PROTOCOL   *mAcpiSdtProtocol = NULL;

//PPTT_TABLE* mPptt;

EFI_ACPI_DESCRIPTION_HEADER mPpttHeader = 
  ARM_ACPI_HEADER (
    EFI_ACPI_6_2_PROCESSOR_PROPERTIES_TOPOLOGY_TABLE_SIGNATURE,
    EFI_ACPI_DESCRIPTION_HEADER,
    EFI_ACPI_6_2_PROCESSOR_PROPERTIES_TOPOLOGY_TABLE_REVISION
  );


EFI_ACPI_6_2_PPTT_TYPE2 mPpttSocketType2[PPTT_SOCKET_COMPONENT_NO] =
{
  {2, sizeof(EFI_ACPI_6_2_PPTT_TYPE2), 0, 0, 0, 0, 0, 0, 0}
};

EFI_ACPI_6_2_PPTT_TYPE1 mPpttCacheType1[PPTT_CACHE_NO] =
{
  {1, sizeof(EFI_ACPI_6_2_PPTT_TYPE1), 0, 0, 0, 0, 0, 0, 0, 0},   //L1I 48K 0xC000 CacheAssociativity8Way
  {1, sizeof(EFI_ACPI_6_2_PPTT_TYPE1), 0, 0, 0, 0, 0, 0, 0, 0},   //L1D 32k 0x8000 CacheAssociativity8Way
  {1, sizeof(EFI_ACPI_6_2_PPTT_TYPE1), 0, 0, 0, 0, 0, 0, 0, 0},  //L2 1M 0x100000 CacheAssociativity8Way
  {1, sizeof(EFI_ACPI_6_2_PPTT_TYPE1), 0, 0, 0, 0x1000000, 0x2000, 0x10, 0x0A, 0x80}  //L3 16M 0x1000000 CacheAssociativity16Way Linesize-128byte
};

EFI_STATUS
InitCacheInfo(
  )
{
  UINT8                                          Index;
  PPTT_TYPE1_ATTRIBUTES             Type1Attributes;
  CSSELR_DATA                             CsselrData;
  CCSIDR_DATA                             CcsidrData;
  

  for (Index = 0; Index < PPTT_CACHE_NO - 1; Index++) {
    CsselrData.Data = 0;
    CcsidrData.Data = 0;
    Type1Attributes.Data = 0;
    
    if (Index == 0) { //L1I
      CsselrData.Bits.InD = 1;
      CsselrData.Bits.Level = 0;
      Type1Attributes.Bits.CacheType  = 1;
    } else if (Index == 1) {
      Type1Attributes.Bits.CacheType  = 0;
      CsselrData.Bits.Level = Index -1;
    } else {
      Type1Attributes.Bits.CacheType  = 2;
      CsselrData.Bits.Level = Index -1;
    }
    
    CcsidrData.Data = ReadCCSIDR (CsselrData.Data);

    if (CcsidrData.Bits.Wa == 1) { 
      Type1Attributes.Bits.AllocateType  = 1;
      if (CcsidrData.Bits.Ra == 1) { 
        Type1Attributes.Bits.AllocateType++;
      }
    }

    if (CcsidrData.Bits.Wt == 1) {
      Type1Attributes.Bits.WritePolicy  = 1;
    }
                DEBUG((EFI_D_ERROR, "[Acpi PPTT] Level = %x!\n",CsselrData.Bits.Level ));
                DEBUG((EFI_D_ERROR, "[Acpi PPTT] CcsidrData = %x!\n",CcsidrData.Data));

    mPpttCacheType1[Index].NumberOfSets = (UINT16)CcsidrData.Bits.NumSets + 1;
    mPpttCacheType1[Index].Associativity = (UINT16)CcsidrData.Bits.Associativity + 1;
    mPpttCacheType1[Index].LineSize = (UINT16)( 1 << (CcsidrData.Bits.LineSize + 4));
    mPpttCacheType1[Index].Size = mPpttCacheType1[Index].LineSize *\
                                                       mPpttCacheType1[Index].Associativity *\
                                                       mPpttCacheType1[Index].NumberOfSets;
    mPpttCacheType1[Index].Attributes = Type1Attributes.Data;
    mPpttCacheType1[Index].Flags = PPTT_TYPE1_SIZE_VALID | PPTT_TYPE1_NUMBER_OF_SETS_VALID | PPTT_TYPE1_ASSOCIATIVITY_VALID |\
                                                        PPTT_TYPE1_ALLOCATION_TYPE_VALID | PPTT_TYPE1_CACHE_TYPE_VALID | PPTT_TYPE1_WRITE_POLICY_VALID |\
                                                        PPTT_TYPE1_LINE_SIZE_VALID;
    
  }   

    // L3
    mPpttCacheType1[3].Flags = PPTT_TYPE1_SIZE_VALID | PPTT_TYPE1_NUMBER_OF_SETS_VALID | PPTT_TYPE1_ASSOCIATIVITY_VALID |\
                                                        PPTT_TYPE1_ALLOCATION_TYPE_VALID | PPTT_TYPE1_CACHE_TYPE_VALID | PPTT_TYPE1_WRITE_POLICY_VALID |\
                                                        PPTT_TYPE1_LINE_SIZE_VALID;
      
  return EFI_SUCCESS;  
}


EFI_STATUS
AddCoreTable(
  IN        VOID *PpttTable, 
  IN OUT VOID *PpttTableLengthRemain, 
  IN UINT32 Flags,
  IN UINT32 Parent,
  IN UINT32 ResourceNo,
  IN UINT32 ProcessorId
  )
{
  EFI_ACPI_6_2_PPTT_TYPE0 *PpttType0;
  EFI_ACPI_6_2_PPTT_TYPE1 *PpttType1;
  UINT32         *PrivateResource;
  UINT8           Index;

  if (*(UINT32 *)PpttTableLengthRemain < sizeof(EFI_ACPI_6_2_PPTT_TYPE0) + ResourceNo * 4) {
    return EFI_OUT_OF_RESOURCES;  
  }
  PpttType0 = (EFI_ACPI_6_2_PPTT_TYPE0 *)(PpttTable + ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length);
  PpttType0->Type = 0;
  PpttType0->Flags = Flags;
  PpttType0->Parent= Parent;
  PpttType0->AcpiProcessorId = ProcessorId;
  PpttType0->PrivateResourceNo = ResourceNo;
  PpttType0->Length = sizeof(EFI_ACPI_6_2_PPTT_TYPE0) + ResourceNo * 4;

  *(UINT32 *)PpttTableLengthRemain  -= (UINTN)PpttType0->Length;
  ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length += PpttType0->Length;
  PrivateResource = (UINT32 *)((UINT8 *)PpttType0 + sizeof(EFI_ACPI_6_2_PPTT_TYPE0));
  
  // Add cache type structure
  for (Index = 0; Index < ResourceNo; Index++, PrivateResource++) {
    if (*(UINT32 *)PpttTableLengthRemain < sizeof(EFI_ACPI_6_2_PPTT_TYPE1)) {
      return EFI_OUT_OF_RESOURCES;  
    }  
    *PrivateResource = ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length;
    PpttType1 = (EFI_ACPI_6_2_PPTT_TYPE1 *)(PpttTable + ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length);
    gBS->CopyMem(PpttType1, &mPpttCacheType1[Index], sizeof(EFI_ACPI_6_2_PPTT_TYPE1));
    if (Index == 0) {
    //  PpttType1->NextLevelOfCache =  (UINT32)(*PrivateResource + sizeof(EFI_ACPI_6_2_PPTT_TYPE1));
    }
    *(UINT32 *)PpttTableLengthRemain -= PpttType1->Length;
    ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length += PpttType1->Length;
  }
        
  return EFI_SUCCESS;  
}

EFI_STATUS
AddClusterTable(
  IN        VOID *PpttTable, 
  IN OUT VOID *PpttTableLengthRemain, 
  IN UINT32 Flags,
  IN UINT32 Parent,
  IN UINT32 ResourceNo
  )
{
  EFI_ACPI_6_2_PPTT_TYPE0 *PpttType0;
  EFI_ACPI_6_2_PPTT_TYPE1 *PpttType1;
  UINT32         *PrivateResource;

  if (*(UINT32 *)PpttTableLengthRemain < sizeof(EFI_ACPI_6_2_PPTT_TYPE0) + ResourceNo * 4) {
    return EFI_OUT_OF_RESOURCES;  
  }
  PpttType0 = (EFI_ACPI_6_2_PPTT_TYPE0 *)(PpttTable + ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length);
  PpttType0->Type = 0;
  PpttType0->Flags = Flags;
  PpttType0->Parent= Parent;
  PpttType0->PrivateResourceNo = ResourceNo;
  PpttType0->Length = sizeof(EFI_ACPI_6_2_PPTT_TYPE0) + ResourceNo * 4;

  *(UINT32 *)PpttTableLengthRemain -= PpttType0->Length;
  ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length += PpttType0->Length;
  PrivateResource = (UINT32 *)((UINT8 *)PpttType0 + sizeof(EFI_ACPI_6_2_PPTT_TYPE0));
  
  // Add cache type structure
  if (*(UINT32 *)PpttTableLengthRemain < sizeof(EFI_ACPI_6_2_PPTT_TYPE1)) {
    return EFI_OUT_OF_RESOURCES;  
  }  
  *PrivateResource = ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length;
  PpttType1 = (EFI_ACPI_6_2_PPTT_TYPE1 *)(PpttTable + ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length);
  gBS->CopyMem(PpttType1, &mPpttCacheType1[2], sizeof(EFI_ACPI_6_2_PPTT_TYPE1));
  *(UINT32 *)PpttTableLengthRemain -= PpttType1->Length;
  ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length += PpttType1->Length;
      
  return EFI_SUCCESS;  
}

EFI_STATUS
AddDieTable(
  IN        VOID *PpttTable, 
  IN OUT VOID *PpttTableLengthRemain, 
  IN UINT32 Flags,
  IN UINT32 Parent,
  IN UINT32 ResourceNo
  )
{
  EFI_ACPI_6_2_PPTT_TYPE0 *PpttType0;
  EFI_ACPI_6_2_PPTT_TYPE1 *PpttType1;
  UINT32         *PrivateResource;

  if (*(UINT32 *)PpttTableLengthRemain < sizeof(EFI_ACPI_6_2_PPTT_TYPE0) + ResourceNo * 4) {
    return EFI_OUT_OF_RESOURCES;  
  }
  PpttType0 = (EFI_ACPI_6_2_PPTT_TYPE0 *)(PpttTable + ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length);
  PpttType0->Type = 0;
  PpttType0->Flags = Flags;
  PpttType0->Parent= Parent;
  PpttType0->PrivateResourceNo = ResourceNo;
  PpttType0->Length = sizeof(EFI_ACPI_6_2_PPTT_TYPE0) + ResourceNo * 4;

  *(UINT32 *)PpttTableLengthRemain -= PpttType0->Length;
  ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length += PpttType0->Length;
  PrivateResource = (UINT32 *)((UINT8 *)PpttType0 + sizeof(EFI_ACPI_6_2_PPTT_TYPE0));
  
  // Add cache type structure
    if (*(UINT32 *)PpttTableLengthRemain < sizeof(EFI_ACPI_6_2_PPTT_TYPE1)) {
      return EFI_OUT_OF_RESOURCES;  
    }  
    *PrivateResource = ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length;
    PpttType1 = (EFI_ACPI_6_2_PPTT_TYPE1 *)(PpttTable + ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length);
    gBS->CopyMem(PpttType1, &mPpttCacheType1[3], sizeof(EFI_ACPI_6_2_PPTT_TYPE1));
    *(UINT32 *)PpttTableLengthRemain -= PpttType1->Length;
    ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length += PpttType1->Length;
  
  return EFI_SUCCESS;  
}


EFI_STATUS
AddSocketTable(
  IN        VOID *PpttTable, 
  IN OUT VOID *PpttTableLengthRemain, 
  IN UINT32 Flags,
  IN UINT32 Parent,
  IN UINT32 ResourceNo
  )
{
  EFI_ACPI_6_2_PPTT_TYPE0 *PpttType0;
  EFI_ACPI_6_2_PPTT_TYPE2 *PpttType2;
  UINT32         *PrivateResource;
  UINT8           Index;

  if (*(UINT32 *)PpttTableLengthRemain < sizeof(EFI_ACPI_6_2_PPTT_TYPE0)) {
    return EFI_OUT_OF_RESOURCES;  
  }
  PpttType0 = (EFI_ACPI_6_2_PPTT_TYPE0 *)(PpttTable + ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length);
  PpttType0->Type = 0;
  PpttType0->Flags = Flags;
  PpttType0->Parent= Parent;
  PpttType0->PrivateResourceNo = ResourceNo;
  PpttType0->Length = sizeof(EFI_ACPI_6_2_PPTT_TYPE0) + ResourceNo * 4;
  ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length += PpttType0->Length;
    
  *(UINT32 *)PpttTableLengthRemain -= PpttType0->Length;
  if (*(UINT32 *)PpttTableLengthRemain < ResourceNo * 4) {
    return EFI_OUT_OF_RESOURCES;  
  }  
//  PpttTypePtr += PpttType0->Length;
  PrivateResource = (UINT32 *)((UINT8 *)PpttType0 + sizeof(EFI_ACPI_6_2_PPTT_TYPE0));
                DEBUG((EFI_D_ERROR, "[Acpi PPTT]  sizeof(EFI_ACPI_6_2_PPTT_TYPE2) = %x!\n", sizeof(EFI_ACPI_6_2_PPTT_TYPE2)));
    
  for (Index = 0; Index < ResourceNo; Index++, PrivateResource++) {
    if (*(UINT32 *)PpttTableLengthRemain < sizeof(EFI_ACPI_6_2_PPTT_TYPE2)) {
      return EFI_OUT_OF_RESOURCES;  
    }  
    *PrivateResource = ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length;
    PpttType2 = (EFI_ACPI_6_2_PPTT_TYPE2 *)(PpttTable + ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length);
    gBS->CopyMem(PpttType2, &mPpttSocketType2[Index], sizeof(EFI_ACPI_6_2_PPTT_TYPE2));
    *(UINT32 *)PpttTableLengthRemain -= PpttType2->Length;
    ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length += PpttType2->Length;
  }
  
  return EFI_SUCCESS;  
}

VOID
PpttSetAcpiTable(
  IN EFI_EVENT    Event,
  IN VOID         *Context
  )
{
  UINTN                         AcpiTableHandle;
  EFI_STATUS                Status;
  UINT8                               Checksum;
  EFI_ACPI_SDT_HEADER     *Table;
  EFI_ACPI_1_0_MULTIPLE_APIC_DESCRIPTION_TABLE  *ApicTable;
  EFI_ACPI_TABLE_VERSION  TableVersion;
  VOID                    *PpttTable;
//  VOID                    *PpttTypePtr;
  UINTN                   TableKey;
  UINT32                    Index0, Index1, IndexSocket, IndexDie, IndexCulster, IndexCore;
  UINT32                   SocketOffset, DieOffset, ClusterOffset;
//  OFFSET_STRUCTURE *OffsetStruct;
//  MADT_INFO           MadtInfo[HI1616_GIC_STRUCTURE_COUNT];
  UINT32                   PpttTableLengthRemain = 0;
  UINT32                   Parent = 0;
  UINT32                   Flags = 0;
  UINT32                   ResourceNo = 0;
  
  gBS->CloseEvent (Event);

  InitCacheInfo ();
  //PpttPrivateResourceTable = AllocateReservedZeroPool(PPTT_PRIVATE_RESOURCE_MAX_LEN); 
//  ResourceLengthRemain = PPTT_PRIVATE_RESOURCE_MAX_LEN;
  
  PpttTable = AllocateZeroPool (PPTT_TABLE_MAX_LEN); 
  gBS->CopyMem (PpttTable, &mPpttHeader, sizeof(EFI_ACPI_DESCRIPTION_HEADER));
//  PpttTypePtr = (UINT8 *)PpttTable + sizeof(EFI_ACPI_DESCRIPTION_HEADER);
  PpttTableLengthRemain = PPTT_TABLE_MAX_LEN - sizeof(EFI_ACPI_DESCRIPTION_HEADER);
//  OffsetStruct = AllocateZeroPool(sizeof(OFFSET_STRUCTURE)); 
    
  for (Index0 = 0; Index0 < EFI_ACPI_MAX_NUM_TABLES; Index0++) {
    Status = mAcpiSdtProtocol->GetAcpiTable (Index0, &Table, &TableVersion, &TableKey);
    if (EFI_ERROR(Status)) {
      break;
    }
    //Find APIC table
    if (Table->Signature != EFI_ACPI_6_1_MULTIPLE_APIC_DESCRIPTION_TABLE_SIGNATURE) {
      continue;
    }

    ApicTable = (EFI_ACPI_1_0_MULTIPLE_APIC_DESCRIPTION_TABLE *)Table;
    Index1 = 0;

    //Get APIC data 
      for (IndexSocket = 0; IndexSocket < PPTT_SOCKET_NO; IndexSocket++) {
        SocketOffset = 0;
        for (IndexDie = 0; IndexDie < PPTT_DIE_NO; IndexDie++) {
          DieOffset = 0;         
          for (IndexCulster = 0; IndexCulster < PPTT_CULSTER_NO; IndexCulster++) {
            ClusterOffset = 0;            
            for (IndexCore = 0; IndexCore < PPTT_CORE_NO; IndexCore++) {

             DEBUG((EFI_D_ERROR, "[Acpi PPTT] IndexSocket:%x, IndexDie:%x, IndexCulster:%x, IndexCore:%x!\n",IndexSocket,IndexDie ,IndexCulster,IndexCore));

              if (ApicTable->GicInterfaces[Index1].AcpiProcessorUid != Index1) {
                //This processor is unusable
                DEBUG((EFI_D_ERROR, "[Acpi PPTT] Please check MADT table for UID!\n"));
                return;
              }           
              if ((ApicTable->GicInterfaces[Index1].Flags & BIT0) ==0 ) {
                //This processor is unusable
                Index1++;
                continue;
              }
              
                if (SocketOffset == 0) { //Add socket0 for type0 table
                  ResourceNo = PPTT_SOCKET_COMPONENT_NO;
                  SocketOffset = ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length;
                  Parent = 0;
                  Flags = PPTT_TYPE0_SOCKET_FLAG;
             DEBUG((EFI_D_ERROR, "[AddSocketTable 0] PpttTable:%x,  PpttTableLengthRemain:%x!\n",PpttTable,PpttTableLengthRemain));
                  AddSocketTable (PpttTable, &PpttTableLengthRemain, Flags, Parent, ResourceNo);
             DEBUG((EFI_D_ERROR, "[AddSocketTable 1] PpttTable:%x, PpttTableLengthRemain:%x!\n",PpttTable,PpttTableLengthRemain));
                }        
                if (DieOffset == 0) { //Add socket0die0 for type0 table
                  ResourceNo = 1;
                  DieOffset =  ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length ;
                  Parent = SocketOffset;
                  Flags = PPTT_TYPE0_DIE_FLAG;
             DEBUG((EFI_D_ERROR, "[AddDieTable 0] PpttTable:%x, PpttTableLengthRemain:%x!\n",PpttTable,PpttTableLengthRemain));
                  AddDieTable (PpttTable, &PpttTableLengthRemain, Flags, Parent, ResourceNo);
             DEBUG((EFI_D_ERROR, "[AddDieTable 1] PpttTable:%x, PpttTableLengthRemain:%x!\n",PpttTable,PpttTableLengthRemain));
                }
              //  ClusterId = (ApicTable->GicInterfaces[Index1].MPIDR & 0x0FF00) >> 8;
                if (ClusterOffset == 0) { //Add socket0die0ClusterId for type0 table
                  ResourceNo = 1;
                  ClusterOffset =  ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length ;
                  Parent = DieOffset;
                  Flags = PPTT_TYPE0_CLUSTER_FLAG;
             DEBUG((EFI_D_ERROR, "[AddClusterTable 0] PpttTable:%x,  PpttTableLengthRemain:%x!\n",PpttTable,PpttTableLengthRemain));
                  AddClusterTable (PpttTable, &PpttTableLengthRemain, Flags, Parent, ResourceNo);
             DEBUG((EFI_D_ERROR, "[AddClusterTable 1] PpttTable:%x, PpttTableLengthRemain:%x!\n",PpttTable,PpttTableLengthRemain));
                }

                //Add socket0die0ClusterIdCoreId for type0 table
                ResourceNo = 2;
                Parent = ClusterOffset;
                Flags = PPTT_TYPE0_CORE_FLAG;
             DEBUG((EFI_D_ERROR, "[AddCoreTable 0] PpttTable:%x,  PpttTableLengthRemain:%x!\n",PpttTable,PpttTableLengthRemain));
                AddCoreTable (PpttTable, &PpttTableLengthRemain, Flags, Parent, ResourceNo, Index1);
             DEBUG((EFI_D_ERROR, "[AddCoreTable 1] PpttTable:%x, PpttTableLengthRemain:%x!\n",PpttTable,PpttTableLengthRemain));
        
               Index1++;
            }
          }
        }
      }
      break;
  }

  ASSERT_EFI_ERROR( Status ) ;

 // ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length = PPTT_TABLE_MAX_LEN - PpttTableLengthRemain;
  Checksum = CalculateCheckSum8 ((UINT8 *)(PpttTable), ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length);
   ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Checksum= Checksum;
  
  AcpiTableHandle = 0;
  Status = mAcpiTableProtocol->InstallAcpiTable (mAcpiTableProtocol, PpttTable, ((EFI_ACPI_DESCRIPTION_HEADER *)PpttTable)->Length, &AcpiTableHandle);

//  FreePool (OffsetStruct);
  FreePool (PpttTable);

}

EFI_STATUS
InitPpttTable(
  )
{
  EFI_STATUS                Status;
  EFI_EVENT   ReadyToBootEvent;
  
  Status = EfiCreateEventReadyToBootEx (
            TPL_NOTIFY,
            PpttSetAcpiTable,
            NULL,
            &ReadyToBootEvent
            );
  ASSERT_EFI_ERROR (Status);

  return Status;  
}


EFI_STATUS
EFIAPI
PpttEntryPoint(
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  EFI_STATUS              Status;

  Status = gBS->LocateProtocol (&gEfiAcpiTableProtocolGuid, NULL,  (VOID**)&mAcpiTableProtocol);
  if (EFI_ERROR (Status)) {
    return EFI_ABORTED;
  }
  
  Status = gBS->LocateProtocol (&gEfiAcpiSdtProtocolGuid, NULL, (VOID**) &mAcpiSdtProtocol);
  if (EFI_ERROR(Status)) {
    return EFI_ABORTED;
  }


  InitPpttTable ();

  DEBUG((EFI_D_ERROR, "Acpi Pptt init done.\n"));
  
  return EFI_SUCCESS;
}


