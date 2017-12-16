#
#  Copyright (c) 2011-2012, ARM Limited. All rights reserved.
#  Copyright (c) 2017, Hisilicon Limited. All rights reserved.
#  Copyright (c) 2017, Linaro Limited. All rights reserved.
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

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = D06
  PLATFORM_GUID                  = D0D445F1-B2CA-4101-9986-1B23525CBEA6
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/$(PLATFORM_NAME)
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = OpenPlatformPkg/Platforms/Hisilicon/$(PLATFORM_NAME)/$(PLATFORM_NAME).fdf
  DEFINE EDK2_SKIP_PEICORE=0
  DEFINE INCLUDE_TFTP_COMMAND=1
  DEFINE NETWORK_IP6_ENABLE      = FALSE
  DEFINE HTTP_BOOT_ENABLE        = TRUE
  DEFINE GENERIC_BDS             = TRUE
  DEFINE SECURE_BOOT_ENABLE      = FALSE

!include OpenPlatformPkg/Chips/Hisilicon/Hisilicon.dsc.inc

[LibraryClasses.common]
  ArmLib|ArmPkg/Library/ArmLib/ArmBaseLib.inf
  ArmPlatformLib|OpenPlatformPkg/Chips/Hisilicon/Library/ArmPlatformLibHisilicon/ArmPlatformLib.inf
  ArmPlatformSysConfigLib|ArmPlatformPkg/ArmVExpressPkg/Library/ArmVExpressSysConfigLib/ArmVExpressSysConfigLib.inf
  NorFlashPlatformLib|ArmPlatformPkg/ArmVExpressPkg/Library/NorFlashArmVExpressLib/NorFlashArmVExpressLib.inf
  LcdPlatformLib|ArmPlatformPkg/ArmVExpressPkg/Library/PL111LcdArmVExpressLib/PL111LcdArmVExpressLib.inf


  I2CLib|OpenPlatformPkg/Chips/Hisilicon/Library/I2CLib/I2CLib.inf
  TimerLib|ArmPkg/Library/ArmArchTimerLib/ArmArchTimerLib.inf

  IpmiCmdLib|OpenPlatformPkg/Chips/Hisilicon/Binary/Hi1610/Library/IpmiCmdLib/IpmiCmdLib.inf

  NetLib|MdeModulePkg/Library/DxeNetLib/DxeNetLib.inf
  DpcLib|MdeModulePkg/Library/DxeDpcLib/DxeDpcLib.inf
  HiiLib|MdeModulePkg/Library/UefiHiiLib/UefiHiiLib.inf
  UefiHiiServicesLib|MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib.inf
  UdpIoLib|MdeModulePkg/Library/DxeUdpIoLib/DxeUdpIoLib.inf
  IpIoLib|MdeModulePkg/Library/DxeIpIoLib/DxeIpIoLib.inf
  OrderedCollectionLib|MdePkg/Library/BaseOrderedCollectionRedBlackTreeLib/BaseOrderedCollectionRedBlackTreeLib.inf
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
  DxeServicesLib|MdePkg/Library/DxeServicesLib/DxeServicesLib.inf
  FileExplorerLib|MdeModulePkg/Library/FileExplorerLib/FileExplorerLib.inf
  BootLogoLib|MdeModulePkg/Library/BootLogoLib/BootLogoLib.inf
  SortLib|MdeModulePkg/Library/UefiSortLib/UefiSortLib.inf
  OsBootLib|OpenPlatformPkg/Chips/Hisilicon/Library/OsBootLib/OsBootLib.inf

!if $(NETWORK_IP6_ENABLE) == TRUE
  TcpIoLib|MdeModulePkg/Library/DxeTcpIoLib/DxeTcpIoLib.inf
!endif

!if $(HTTP_BOOT_ENABLE) == TRUE
  HttpLib|MdeModulePkg/Library/DxeHttpLib/DxeHttpLib.inf
!endif

  #FDTUpdateLib
  FdtUpdateLib|OpenPlatformPkg/Platforms/Hisilicon/D06/Library/FdtUpdateLib/FdtUpdateLib.inf

  CpldIoLib|OpenPlatformPkg/Chips/Hisilicon/Library/CpldIoLib/CpldIoLib.inf

  SerdesLib|OpenPlatformPkg/Chips/Hisilicon/Binary/Hi1620/Library/Hi1620Serdes/Hi1620SerdesLib.inf

  EfiTimeBaseLib|OpenPlatformPkg/Library/EfiTimeBaseLib/EfiTimeBaseLib.inf
  RealTimeClockLib|OpenPlatformPkg/Platforms/Hisilicon/D03/Library/DS3231RealTimeClockLib/DS3231RealTimeClockLib.inf

  OemMiscLib|OpenPlatformPkg/Platforms/Hisilicon/D06/Library/OemMiscLibD06/OemMiscLibD06.inf
  OemAddressMapLib|OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Library/OemAddressMapD06/OemAddressMapD06.inf
  PlatformSysCtrlLib|OpenPlatformPkg/Chips/Hisilicon/Binary/Hi1620/Library/PlatformSysCtrlLibHi1620/PlatformSysCtrlLibHi1620.inf

  CapsuleLib|MdeModulePkg/Library/DxeCapsuleLibNull/DxeCapsuleLibNull.inf
  GenericBdsLib|IntelFrameworkModulePkg/Library/GenericBdsLib/GenericBdsLib.inf
  PlatformBdsLib|OpenPlatformPkg/Chips/Hisilicon/Library/PlatformIntelBdsLib/PlatformIntelBdsLib.inf
  BmcConfigBootLib|OpenPlatformPkg/Chips/Hisilicon/Library/BmcConfigBootLib/BmcConfigBootLib.inf
  UefiBootManagerLib|MdeModulePkg/Library/UefiBootManagerLib/UefiBootManagerLib.inf
!if $(GENERIC_BDS) == TRUE
  SortLib|MdeModulePkg/Library/UefiSortLib/UefiSortLib.inf
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
  DxeServicesLib|MdePkg/Library/DxeServicesLib/DxeServicesLib.inf
  PlatformBootManagerLib|OpenPlatformPkg/Chips/Hisilicon/Library/PlatformBootManagerLib/PlatformBootManagerLib.inf
  FileExplorerLib|MdeModulePkg/Library/FileExplorerLib/FileExplorerLib.inf
!endif
  CustomizedDisplayLib|MdeModulePkg/Library/CustomizedDisplayLib/CustomizedDisplayLib.inf

  # USB Requirements
  UefiUsbLib|MdePkg/Library/UefiUsbLib/UefiUsbLib.inf

  LpcLib|OpenPlatformPkg/Chips/Hisilicon/Binary/Hi1620/Library/LpcLibHi1620/LpcLibD06.inf
  SerialPortLib|ArmPlatformPkg/Library/PL011SerialPortLib/PL011SerialPortLib.inf

[LibraryClasses.common.SEC]
  ArmPlatformLib|OpenPlatformPkg/Chips/Hisilicon/Library/ArmPlatformLibHisilicon/ArmPlatformLibSec.inf


[LibraryClasses.common.DXE_RUNTIME_DRIVER]
  I2CLib|OpenPlatformPkg/Chips/Hisilicon/Library/I2CLib/I2CLibRuntime.inf
  SerialPortLib|ArmPlatformPkg/Library/PL011SerialPortLib/PL011SerialPortLib.inf

[BuildOptions]
  GCC:*_*_AARCH64_PLATFORM_FLAGS == -I$(WORKSPACE)/OpenPlatformPkg/Chips/Hisilicon/Hi1620/Include

################################################################################
#
# Pcd Section - list of all EDK II PCD Entries defined by this Platform
#
################################################################################

[PcdsFeatureFlag.common]

!if $(EDK2_SKIP_PEICORE) == 1
  gArmPlatformTokenSpaceGuid.PcdSystemMemoryInitializeInSec|TRUE
  gArmPlatformTokenSpaceGuid.PcdSendSgiToBringUpSecondaryCores|TRUE
!endif

  ## If TRUE, Graphics Output Protocol will be installed on virtual handle created by ConsplitterDxe.
  #  It could be set FALSE to save size.
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutGopSupport|TRUE
  gHisiTokenSpaceGuid.PcdIsItsSupported|TRUE
  gArmTokenSpaceGuid.PcdArmGicV3WithV2Legacy|FALSE
  gEfiMdeModulePkgTokenSpaceGuid.PcdHiiOsRuntimeSupport|FALSE

[PcdsFixedAtBuild.common]
  gEmbeddedTokenSpaceGuid.PcdEmbeddedPrompt|"D06"

  gArmPlatformTokenSpaceGuid.PcdCoreCount|8
  gEmbeddedTokenSpaceGuid.PcdPrePiCpuMemorySize|48

  gEfiMdeModulePkgTokenSpaceGuid.PcdMaxVariableSize|0x2000

  # Stacks for MPCores in Secure World
  gArmPlatformTokenSpaceGuid.PcdCPUCoresSecStackBase|0xA0000000
  gArmPlatformTokenSpaceGuid.PcdCPUCoreSecPrimaryStackSize|0x10000

  # Stacks for MPCores in Monitor Mode
  gArmPlatformTokenSpaceGuid.PcdCPUCoresSecMonStackBase|0xA000FF00
  gArmPlatformTokenSpaceGuid.PcdCPUCoreSecMonStackSize|0x100

  # Stacks for MPCores in Normal World
  gArmPlatformTokenSpaceGuid.PcdCPUCoresStackBase|0xA0000000
  gArmPlatformTokenSpaceGuid.PcdCPUCorePrimaryStackSize|0xFF00

  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x00000000


  gArmTokenSpaceGuid.PcdSystemMemorySize|0x3FC00000


  # Size of the region used by UEFI in permanent memory (Reserved 64MB)
  gArmPlatformTokenSpaceGuid.PcdSystemMemoryUefiRegionSize|0x10000000

  gHisiTokenSpaceGuid.PcdSerDesFlowCtrlFlag|1


  #
  # ARM Pcds
  #
  gArmTokenSpaceGuid.PcdArmUncachedMemoryMask|0x0000000040000000

  gHisiTokenSpaceGuid.PcdSlotPerChannelNum|0x2


  gHisiTokenSpaceGuid.PcdPcieRootBridgeMask|0x94 # bit0:HB0RB0,bit1:HB0RB1,bit2:HB0RB2,bit3:HB0RB3,bit4:HB0RB4,bit5:HB0RB5,bit6:HB0RB6,bit7:HB0RB7
                                                # bit8:HB1RB0,bit9:HB1RB1,bit10:HB1RB2,bit11:HB1RB3,bit12:HB1RB4,bit13:HB1RB5,bit14:HB1RB6,bit14:HB1RB15

  ## SP805 Watchdog - Motherboard Watchdog
  gArmPlatformTokenSpaceGuid.PcdSP805WatchdogBase|0x601e0000

  ## Serial Terminal
  gEfiMdeModulePkgTokenSpaceGuid.PcdSerialRegisterBase|0x94080000
  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultBaudRate|115200

  gArmPlatformTokenSpaceGuid.PL011UartClkInHz|200000000

  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultDataBits|8
  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultParity|1
  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultStopBits|1
  # use the TTY terminal type (which has a working backspace)
  gEfiMdePkgTokenSpaceGuid.PcdDefaultTerminalType|4

  ## Serial Debug UART
  gArmPlatformTokenSpaceGuid.PcdSerialDbgRegisterBase|0x94090000

  gHisiTokenSpaceGuid.PcdM3SmmuBaseAddress|0xa0040000
  gHisiTokenSpaceGuid.PcdPcieSmmuBaseAddress|0xb0040000
  gHisiTokenSpaceGuid.PcdDsaSmmuBaseAddress|0xc0040000
  gHisiTokenSpaceGuid.PcdAlgSmmuBaseAddress|0xd0040000


  gHisiTokenSpaceGuid.PcdIsMPBoot|1
  gHisiTokenSpaceGuid.PcdSocketMask|0x3
  !ifdef $(FIRMWARE_VER)
    gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareVersionString|L"$(FIRMWARE_VER)"
  !else
    gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareVersionString|L"Hisilicon D06 UEFI Nemo 1.7 RC1"
  !endif

  gHisiTokenSpaceGuid.PcdBiosVersionString|L"10.01.01T18"

  gHisiTokenSpaceGuid.PcdBiosVersionForBmc|L"1.12"

  gHisiTokenSpaceGuid.PcdSystemProductName|L"D06"
  gHisiTokenSpaceGuid.PcdSystemVersion|L"VER.A"
  gHisiTokenSpaceGuid.PcdBaseBoardProductName|L"D06"
  gHisiTokenSpaceGuid.PcdBaseBoardVersion|L"Estuary"

  gHisiTokenSpaceGuid.PcdCPUInfo|L"Hi1620"

  gArmTokenSpaceGuid.PcdGicDistributorBase|0xAA000000
  gArmTokenSpaceGuid.PcdGicRedistributorsBase|0xAA100000

  gArmTokenSpaceGuid.PcdGicInterruptInterfaceBase|0xFE000000

  #
  # ARM OS Loader
  #
  # Versatile Express machine type (ARM VERSATILE EXPRESS = 2272) required for ARM Linux:
  gArmPlatformTokenSpaceGuid.PcdDefaultBootDescription|L"Linux from SATA"
  gArmPlatformTokenSpaceGuid.PcdDefaultBootDevicePath|L"EFI\GRUB2\grubaa64.efi"
  gArmPlatformTokenSpaceGuid.PcdDefaultBootArgument|""

  # Use the serial console (ConIn & ConOut) and the Graphic driver (ConOut)
  gArmPlatformTokenSpaceGuid.PcdDefaultConOutPaths|L"VenHw(D3987D4B-971A-435F-8CAF-4967EB627241)/Uart(115200,8,N,1)/VenPcAnsi();VenHw(407B4008-BF5B-11DF-9547-CF16E0D72085)"
  gArmPlatformTokenSpaceGuid.PcdDefaultConInPaths|L"VenHw(D3987D4B-971A-435F-8CAF-4967EB627241)/Uart(115200,8,N,1)/VenPcAnsi()"

  #
  # ARM Architectual Timer Frequency
  #
  gArmTokenSpaceGuid.PcdArmArchTimerFreqInHz|100000000


  gEfiMdeModulePkgTokenSpaceGuid.PcdResetOnMemoryTypeInformationChange|FALSE
  gEfiIntelFrameworkModulePkgTokenSpaceGuid.PcdShellFile|{ 0x83, 0xA5, 0x04, 0x7C, 0x3E, 0x9E, 0x1C, 0x4F, 0xAD, 0x65, 0xE0, 0x52, 0x68, 0xD0, 0xB4, 0xD1 }
!if $(GENERIC_BDS) == TRUE
  gEfiMdeModulePkgTokenSpaceGuid.PcdBootManagerMenuFile|{ 0x21, 0xaa, 0x2c, 0x46, 0x14, 0x76, 0x03, 0x45, 0x83, 0x6e, 0x8a, 0xb6, 0xf4, 0x66, 0x23, 0x31 }|VOID*|0x0001006b
!endif
  gHisiTokenSpaceGuid.PcdSysControlBaseAddress|0x40010000
  gHisiTokenSpaceGuid.PcdMailBoxAddress|0x0000FFF8

  gHisiTokenSpaceGuid.PcdCpldBaseAddress|0x78000000

  gHisiTokenSpaceGuid.PcdSFCCFGBaseAddress|0x206200000
  gHisiTokenSpaceGuid.PcdSFCMEM0BaseAddress|0x204000000


  gOpenPlatformTokenSpaceGuid.PcdRamDiskMaxSize|128


  gHisiTokenSpaceGuid.PcdPeriSubctrlAddress|0x40000000


  gHisiTokenSpaceGuid.PcdMdioSubctrlAddress|0x60000000

  ## DTB address at spi flash
  gHisiTokenSpaceGuid.FdtFileAddress|0xA47A0000

  ## 2+1
  gHisiTokenSpaceGuid.PcdPlatformDefaultPackageType|0x1

  gHisiTokenSpaceGuid.PcdArmPrimaryCoreTemp|0x80030000

  gHisiTokenSpaceGuid.PcdTopOfLowMemory|0x40000000

  gHisiTokenSpaceGuid.PcdBottomOfHighMemory|0x1000000000

  gHisiTokenSpaceGuid.PcdNORFlashBase|0x80000000
  gHisiTokenSpaceGuid.PcdNORFlashCachableSize|0x8000000

  gHisiTokenSpaceGuid.PcdTrustedFirmwareEnable|0x1
  gHisiTokenSpaceGuid.PcdNumaEnable|1
  gHisiTokenSpaceGuid.PcdMacAddress|0xA47E0000

  # PCIe ECAM Access BaseAddress
  gEfiMdePkgTokenSpaceGuid.PcdPciExpressBaseAddress|0xD0000000

  gHisiTokenSpaceGuid.PciTotalEcam|0xD0000000

  gHisiTokenSpaceGuid.PciHb0IoBase|0
  gHisiTokenSpaceGuid.PciHb0IoSize|0x10000 #64K
  gHisiTokenSpaceGuid.PciHb0Mem32Base|0xE0000000
  gHisiTokenSpaceGuid.PciHb0Mem32Size|0x7FF0000  #(128M-64K)

  gHisiTokenSpaceGuid.PciHb0Mem64Base|0x80000000000
  gHisiTokenSpaceGuid.PciHb0Mem64Size|0x4000000000

  # Chip1 Config
  gHisiTokenSpaceGuid.PciHb1IoBase|0
  gHisiTokenSpaceGuid.PciHb1IoSize|0x10000 #64K
  gHisiTokenSpaceGuid.PciHb1Mem32Base|0xE8000000
  gHisiTokenSpaceGuid.PciHb1Mem32Size|0x7FF0000  #(128M-64K)

  gHisiTokenSpaceGuid.PciHb1Mem64Base|0x480000000000
  gHisiTokenSpaceGuid.PciHb1Mem64Size|0x4000000000
  #1620 PCIe Upload+ <<<

  gHisiTokenSpaceGuid.Pcdsoctype|0x1620
  ## SP804 DualTimer
  gArmPlatformTokenSpaceGuid.PcdSP804TimerFrequencyInMHz|200
  gArmPlatformTokenSpaceGuid.PcdSP804TimerPeriodicInterruptNum|0xb0
  gArmPlatformTokenSpaceGuid.PcdSP804TimerPeriodicBase|0x40060000
  ## TODO: need to confirm the base for Performance and Metronome base for PV660
  gArmPlatformTokenSpaceGuid.PcdSP804TimerPerformanceBase|0x40060000
  gArmPlatformTokenSpaceGuid.PcdSP804TimerMetronomeBase|0x40060000
  # SMBIOS 3.0 only
  #  BIT0 set indicates 32-bit entry point and table are produced.<BR>
  #  BIT1 set indicates 64-bit entry point and table are produced.<BR>
  gEfiMdeModulePkgTokenSpaceGuid.PcdSmbiosEntryPointProvideMethod|0x2

  #
  # ACPI Table Version
  #
  #   BIT 1 - EFI_ACPI_TABLE_VERSION_1_0B.<BR>
  #   BIT 2 - EFI_ACPI_TABLE_VERSION_2_0.<BR>
  #   BIT 3 - EFI_ACPI_TABLE_VERSION_3_0.<BR>
  #   BIT 4 - EFI_ACPI_TABLE_VERSION_4_0.<BR>
  #   BIT 5 - EFI_ACPI_TABLE_VERSION_5_0.<BR>
  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiExposedTableVersions|0x20

  # Sbsa watchdog
  gArmTokenSpaceGuid.PcdGenericWatchdogControlBase|0x40500000
  gArmTokenSpaceGuid.PcdGenericWatchdogRefreshBase|0x40600000

[PcdsDynamicDefault]
  gEfiMdeModulePkgTokenSpaceGuid.PcdSrIovSupport|TRUE
  gEfiMdeModulePkgTokenSpaceGuid.PcdAriSupport|TRUE
################################################################################
#
# Components Section - list of all EDK II Modules needed by this Platform
#
################################################################################
[Components.common]

  #
  # SEC
  #

  #
  # PEI Phase modules
  #
  ArmPlatformPkg/PrePeiCore/PrePeiCoreMPCore.inf
  MdeModulePkg/Core/Pei/PeiMain.inf
  MdeModulePkg/Universal/PCD/Pei/Pcd.inf
  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Drivers/Ipmi/IpmiInterfacePei/IpmiInterfacePei.inf

  ArmPlatformPkg/PlatformPei/PlatformPeim.inf

  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/MemoryInitPei/MemoryInitPeim.inf
  ArmPkg/Drivers/CpuPei/CpuPei.inf
  IntelFrameworkModulePkg/Universal/StatusCode/Pei/StatusCodePei.inf
  MdeModulePkg/Universal/FaultTolerantWritePei/FaultTolerantWritePei.inf
  MdeModulePkg/Universal/Variable/Pei/VariablePei.inf

  OpenPlatformPkg/Platforms/Hisilicon/D06/EarlyConfigPeim/EarlyConfigPeimD06.inf
  OpenPlatformPkg/Chips/Hisilicon/Drivers/VersionInfoPeim/VersionInfoPeim.inf

  MdeModulePkg/Core/DxeIplPeim/DxeIpl.inf {
    <LibraryClasses>
      NULL|IntelFrameworkModulePkg/Library/LzmaCustomDecompressLib/LzmaCustomDecompressLib.inf
  }

  #
  # DXE
  #
  MdeModulePkg/Core/Dxe/DxeMain.inf {
    <LibraryClasses>
      NULL|MdeModulePkg/Library/DxeCrc32GuidedSectionExtractLib/DxeCrc32GuidedSectionExtractLib.inf
  }
  MdeModulePkg/Universal/PCD/Dxe/Pcd.inf

  OpenPlatformPkg/Chips/Hisilicon/Hi1610/Drivers/IoInitDxe/IoInitDxe.inf

  #
  # Architectural Protocols
  #
  ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf

  OpenPlatformPkg/Platforms/Hisilicon/D03/Drivers/OemNicConfig2PHi1610/OemNicConfig2P.inf
  #OpenPlatformPkg/Platforms/Hisilicon/D03/Drivers/OemSasConfig/OemSasConfig.inf

  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Drivers/SFC/SfcDxeDriver.inf

  MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf
  # Sometimes we can use EmuVariableRuntimeDxe instead of real flash variable store for debug.
  #MdeModulePkg/Universal/Variable/EmuRuntimeDxe/EmuVariableRuntimeDxe.inf
  OpenPlatformPkg/Chips/Hisilicon/Drivers/FlashFvbDxe/FlashFvbDxe.inf
  MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf {
    <LibraryClasses>
      NULL|MdeModulePkg/Library/VarCheckUefiLib/VarCheckUefiLib.inf
      BaseMemoryLib|MdePkg/Library/BaseMemoryLib/BaseMemoryLib.inf
  }
  MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  MdeModulePkg/Universal/FaultTolerantWriteDxe/FaultTolerantWriteDxe.inf

  MdeModulePkg/Universal/MonotonicCounterRuntimeDxe/MonotonicCounterRuntimeDxe.inf
  EmbeddedPkg/ResetRuntimeDxe/ResetRuntimeDxe.inf
  EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf {
    <LibraryClasses>
      CpldIoLib|OpenPlatformPkg/Chips/Hisilicon/Library/CpldIoLib/CpldIoLibRuntime.inf
  }
  EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf

  MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf
  MdeModulePkg/Universal/Console/TerminalDxe/TerminalDxe.inf
  MdeModulePkg/Universal/SerialDxe/SerialDxe.inf

  # Simple TextIn/TextOut for UEFI Terminal
  EmbeddedPkg/SimpleTextInOutSerial/SimpleTextInOutSerial.inf

  MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf

  ArmPkg/Drivers/ArmGic/ArmGicDxe.inf

  ArmPkg/Drivers/TimerDxe/TimerDxe.inf

  MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  IntelFrameworkModulePkg/Universal/StatusCode/RuntimeDxe/StatusCodeRuntimeDxe.inf
  #
  #ACPI
  #
  MdeModulePkg/Universal/Acpi/AcpiTableDxe/AcpiTableDxe.inf
  OpenPlatformPkg/Chips/Hisilicon/Drivers/HisiAcpiPlatformDxe/AcpiPlatformDxe.inf

  OpenPlatformPkg/Chips/Hisilicon/Hi1620/Hi1620AcpiTables/AcpiTablesHi1620.inf
  OpenPlatformPkg/Chips/Hisilicon/Drivers/AcpiPlatformDxe/AcpiPlatformDxe.inf

  #
  # Usb Support
  #
  #OpenPlatformPkg/Chips/Hisilicon/Drivers/VirtualEhciPciIo/VirtualEhciPciIo.inf
  MdeModulePkg/Bus/Pci/EhciDxe/EhciDxe.inf
  MdeModulePkg/Bus/Pci/XhciDxe/XhciDxe.inf
  MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
  MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  #MdeModulePkg/Bus/Usb/UsbMouseDxe/UsbMouseDxe.inf
  MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Drivers/Ipmi/IpmiInterfaceDxe/IpmiInterfaceDxe.inf

  #
  #network
  #
  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Drivers/Net/SnpHi1620NewDxe/SnpDxe.inf

  MdeModulePkg/Universal/Network/ArpDxe/ArpDxe.inf
  MdeModulePkg/Universal/Network/Dhcp4Dxe/Dhcp4Dxe.inf
  MdeModulePkg/Universal/Network/DpcDxe/DpcDxe.inf
  MdeModulePkg/Universal/Network/Ip4Dxe/Ip4Dxe.inf
  MdeModulePkg/Universal/Network/MnpDxe/MnpDxe.inf
  MdeModulePkg/Universal/Network/Mtftp4Dxe/Mtftp4Dxe.inf
  MdeModulePkg/Universal/Network/Udp4Dxe/Udp4Dxe.inf
!if $(NETWORK_IP6_ENABLE) == TRUE
  NetworkPkg/Ip6Dxe/Ip6Dxe.inf
  NetworkPkg/TcpDxe/TcpDxe.inf
  NetworkPkg/Udp6Dxe/Udp6Dxe.inf
  NetworkPkg/Dhcp6Dxe/Dhcp6Dxe.inf
  NetworkPkg/Mtftp6Dxe/Mtftp6Dxe.inf
  NetworkPkg/UefiPxeBcDxe/UefiPxeBcDxe.inf
!else
  MdeModulePkg/Universal/Network/Tcp4Dxe/Tcp4Dxe.inf
  MdeModulePkg/Universal/Network/UefiPxeBcDxe/UefiPxeBcDxe.inf
!endif
  MdeModulePkg/Universal/Network/IScsiDxe/IScsiDxe.inf
!if $(HTTP_BOOT_ENABLE) == TRUE
  NetworkPkg/DnsDxe/DnsDxe.inf
  NetworkPkg/HttpUtilitiesDxe/HttpUtilitiesDxe.inf
  NetworkPkg/HttpDxe/HttpDxe.inf
  NetworkPkg/HttpBootDxe/HttpBootDxe.inf
!endif

  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Drivers/Sas/SasDxeDriver.inf

  #
  # FAT filesystem + GPT/MBR partitioning
  #

  OpenPlatformPkg/Drivers/Block/ramdisk/ramdisk.inf
  MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf

  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Ebl/Ebl.inf
!if $(GENERIC_BDS) == TRUE
  MdeModulePkg/Application/UiApp/UiApp.inf {
    <LibraryClasses>
      NULL|MdeModulePkg/Library/BootManagerUiLib/BootManagerUiLib.inf
      NULL|MdeModulePkg/Library/DeviceManagerUiLib/DeviceManagerUiLib.inf
      NULL|MdeModulePkg/Library/BootMaintenanceManagerUiLib/BootMaintenanceManagerUiLib.inf
  }
!endif
  #
  # Bds
  #
  MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf

  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Drivers/GetInfoFromBmc/GetInfoFromBmc.inf
  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Drivers/TransferSmbiosInfo/TransSmbiosInfo.inf
  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Drivers/IpmiMiscOpDxe/IpmiMiscOpDxe.inf

  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Drivers/IpmiWatchdogDxe/IpmiWatchdogDxe.inf

  MdeModulePkg/Universal/SmbiosDxe/SmbiosDxe.inf
  OpenPlatformPkg/Chips/Hisilicon/Drivers/Smbios/SmbiosMiscDxe/SmbiosMiscDxe.inf

  OpenPlatformPkg/Chips/Hisilicon/Drivers/UpdateFdtDxe/UpdateFdtDxe.inf {
    <LibraryClasses>
      BaseMemoryLib|MdePkg/Library/BaseMemoryLib/BaseMemoryLib.inf
  }

  #PCIe Support
  OpenPlatformPkg/Chips/Hisilicon/Hi1620/Drivers/PcieInit1620/PcieInitDxe.inf
  OpenPlatformPkg/Platforms/Hisilicon/D03/Drivers/PciPlatform/PciPlatform.inf
  OpenPlatformPkg/Chips/Hisilicon/Hi1620/Drivers/PciHostBridgeDxe/PciHostBridgeDxe.inf {
    <LibraryClasses>
      NULL|OpenPlatformPkg/Platforms/Hisilicon/D06/Library/PlatformPciLib/PlatformPciLib.inf
      DmaLib|EmbeddedPkg/Library/NullDmaLib/NullDmaLib.inf
  }

  MdeModulePkg/Bus/Pci/PciBusDxe/PciBusDxe.inf
  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Drivers/PcieRasInitDxe/PcieRasInitDxe.inf

  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Drivers/ReportPciePlugDidVidToBmc/ReportPciePlugDidVidToBmc.inf
  OpenPlatformPkg/Chips/Hisilicon/Drivers/Smbios/AddSmbiosType9/AddSmbiosType9.inf
  OpenPlatformPkg/Platforms/Hisilicon/Binary/D06/Drivers/Sm750Dxe/UefiSmi.inf
  MdeModulePkg/Bus/Pci/NvmExpressDxe/NvmExpressDxe.inf
  OpenPlatformPkg/Chips/Hisilicon/Drivers/Smbios/MemorySubClassDxe/MemorySubClassDxe.inf


  OpenPlatformPkg/Chips/Hisilicon/Drivers/Smbios/ProcessorSubClassDxe/ProcessorSubClassDxe.inf

  #
  # Memory test
  #
  MdeModulePkg/Universal/MemoryTest/NullMemoryTestDxe/NullMemoryTestDxe.inf
  MdeModulePkg/Universal/DisplayEngineDxe/DisplayEngineDxe.inf
  MdeModulePkg/Universal/SetupBrowserDxe/SetupBrowserDxe.inf
!if $(GENERIC_BDS) == TRUE
  MdeModulePkg/Universal/BdsDxe/BdsDxe.inf
!else
  IntelFrameworkModulePkg/Universal/BdsDxe/BdsDxe.inf
!endif

  #
  # UEFI application (Shell Embedded Boot Loader)
  #
  ShellPkg/Application/Shell/Shell.inf {
    <LibraryClasses>
      ShellCommandLib|ShellPkg/Library/UefiShellCommandLib/UefiShellCommandLib.inf
      NULL|ShellPkg/Library/UefiShellLevel2CommandsLib/UefiShellLevel2CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel1CommandsLib/UefiShellLevel1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel3CommandsLib/UefiShellLevel3CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDriver1CommandsLib/UefiShellDriver1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDebug1CommandsLib/UefiShellDebug1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellInstall1CommandsLib/UefiShellInstall1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellNetwork1CommandsLib/UefiShellNetwork1CommandsLib.inf
      HandleParsingLib|ShellPkg/Library/UefiHandleParsingLib/UefiHandleParsingLib.inf
      PrintLib|MdePkg/Library/BasePrintLib/BasePrintLib.inf
      BcfgCommandLib|ShellPkg/Library/UefiShellBcfgCommandLib/UefiShellBcfgCommandLib.inf
!if $(NETWORK_IP6_ENABLE) == TRUE
      NULL|ShellPkg/Library/UefiShellNetwork2CommandsLib/UefiShellNetwork2CommandsLib.inf
!endif

!ifdef $(INCLUDE_DP)
      NULL|ShellPkg/Library/UefiDpLib/UefiDpLib.inf
!endif #$(INCLUDE_DP)
!ifdef $(INCLUDE_TFTP_COMMAND)
      NULL|ShellPkg/Library/UefiShellTftpCommandLib/UefiShellTftpCommandLib.inf
!endif #$(INCLUDE_TFTP_COMMAND)

    <PcdsFixedAtBuild>
      gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0xFF
      gEfiShellPkgTokenSpaceGuid.PcdShellLibAutoInitialize|FALSE
      gEfiMdePkgTokenSpaceGuid.PcdUefiLibMaxPrintBufferSize|8000
  }
