/** @file
*
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
**/

#ifndef _OS_BOOT_LIB_H_
#define _OS_BOOT_LIB_H_


/**
    Remove invalid OS boot options, and then add new ones.

*/
EFI_STATUS
AdjustOsBootOrder (
  VOID
  );

/**
  Try to find UEFI OSs and create the boot options which haven't been listed in BootOrder.

*/
EFI_STATUS
CreateOsBootOptions (
  VOID
  );

/**
    Remove UEFI OS boot options when it is disappeared in system.

*/
EFI_STATUS
RemoveInvalidOsBootOptions (
  VOID
  );

#endif
