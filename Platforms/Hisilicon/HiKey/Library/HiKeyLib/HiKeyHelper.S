#
#  Copyright (c) 2014-2015, Linaro Limited. All rights reserved.
#  Copyright (c) 2014-2015, Hisilicon Limited. All rights reserved.
#
#  This program and the accompanying materials
#  are licensed and made available under the terms and conditions of the BSD License
#  which accompanies this distribution.  The full text of the license may be found at
#  http://opensource.org/licenses/bsd-license.php
#
#  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
#

#include <AsmMacroIoLibV8.h>
#include <Library/ArmLib.h>

PrimaryCoreMpid:  .word    0x0

ASM_FUNC(ArmPlatformPeiBootAction)
  // The trusted firmware passes the primary CPU MPID through x0 register.
  // Save it in a variable.
  adr  x1, PrimaryCoreMpid
  str  w0, [x1]
  ret

//UINTN
//ArmPlatformIsPrimaryCore (
//  IN UINTN MpId
//  );
ASM_FUNC(ArmPlatformIsPrimaryCore)
  MOV32 (w1, FixedPcdGet32 (PcdArmPrimaryCoreMask))
  and   x0, x0, x1

  ldr   w1, PrimaryCoreMpid

  cmp   w0, w1
  cset  x0, eq
  ret

//UINTN
//ArmPlatformGetPrimaryCoreMpId (
//  VOID
//  );
ASM_FUNC(ArmPlatformGetPrimaryCoreMpId)
  ldr   w0, PrimaryCoreMpid
  ret

//UINTN
//ArmPlatformGetCorePosition (
//  IN UINTN MpId
//  );
// With this function: CorePos = (ClusterId * 4) + CoreId
ASM_FUNC(ArmPlatformGetCorePosition)
  and   x1, x0, #ARM_CORE_MASK
  and   x0, x0, #ARM_CLUSTER_MASK
  add   x0, x1, x0, LSR #6
  ret
