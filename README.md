# FPGA_LOAD - FPGA update tool

Note: This repo contains OS independent FPGA_LOAD sources and a Linux makefile for compilation.

FPGA_LOAD binaries are available in the following software packages:

- Linux  : 13MD05-90 - MDIS5 System Package for Linux
- QNX    : 13Z100-40 - QNX FPGA update tool
- VxWorks: 13MD05-60 - MDIS5 System Package for VxWorks
- Windows: 13Y018-70 - Windows FPGA update tool

The packages can be downloaded from the MEN website www.men.de.

## Description

FPGA_LOAD is a command-line tool for Linux, QNX, VxWorks and Windows that can be used to:

- List PCI devices
- Show Chameleon table of MEN FPGAs
- Read/write FPGA configuration from/to flash memory

For further information see document 21APPN021 *Updating the FPGA in MEN Products using fpga_load*:
https://www.men.de/downloads/search/dl/sk/application%20note%20updating%20fpga/

## Command Line Interface

```
Usage   : fpga_load [options]
Function: Manage FPGA configurations
Options :
 
 _____ flash Location _____
 The flash interface address can be specified directly with
 options -b/-o (PCI), -a (VME), -d (ISA/LPC).
 Without option -b/-o (PCI) or with option -k (ISA/LPC), the
 flash interface address will be taken from the Chameleon table
 of the specified FPGA device (PCI) or the specified Chameleonn
 table address (ISA/LPC).
 
 ----- PCIbus -----
 <vendor-id>         PCI vendor ID (e.g. 0x1172)
 <device-id>         PCI device ID (e.g. 0x4D45 for chameleon_2 dev)
 <sub-vendor-id>     PCI subsystem vendor ID (e.g. 0x0007 for 15P018)
 <instance-nbr>      instance number of PCI Chameleon FPGA (see -s)
 [-b <bar>           PCI BAR number 0..5
  -o <offset>]       offset from specified BAR to flash interface
 -s                  only show all PCI device instances that match to
                      <vendor-id>, <device-id>, <sub-vendor-id>

----- MMODbus -----
 -q                  change the access type to work with MMOD A8D16 mode
 
----- VMEbus -----
 -a <VME-addr>       directly specify VME address of flash interface
 
----- ISA/LPC -----
 -d <addr>           directly specify address of flash interface,
		              !!!ATTENTION: No flash type validation, please specify -z or -j.
                     set LSB to 1 for i/o access, e.g. 0xe281
 -k <tbl-addr>       use Chameleon table at specified address,
                     set LSB to 1 for i/o access, e.g. 0xe001

 _____ flash Type _____
 -z                  use only SPI Flashes with 16Z126 flash Interface
 -j		      use only Parallel Flashes

 _____ Safe Actions _____
 -u <file> <nr>      update FPGA config Nr. <0-3> in flash
                      Offset in flash will be read from flash fpga header
                      and header info will be validated before update.
                      If this option is selected, all others are ignored.
 -r <start> <len>    read <len> bytes from the flash at offset <start>
    [<file>]          If <file> is specified, the data is written
                      to the file, otherwise data is printed to stdout
 -l                  load new FPGA config at end                          [FALSE]

 _____ Force Mode Actions _____
 -f <force-cmd>       switch to force moden, (use one of the cmds below)
                       !!! please pay attention what you are doing !!!!
                       - no header validation will be performed
                       - all options must be passed by command line
                       - full access to flash commands is granted
                       - more than one command can be passed
  	                      (they will be executed from first to last)
   -c                  erase chip
   -e <start> <len>    erase complete blocks, starting with the block
                        where offset <start> resides, ending with 
                        the block that is reached by <len> bytes          [0]
   -w <file> <start>   write <file> to the flash, starting at offset
                        <start>

 _____ HW Specifics _____
 -x <z>              set bus switches of A500 ESM carrier
                      z = 1: PCI64 enable;  IO disable;
                      z = 2: PCI64 disable; IO enable;
                      z = 3: PCI64 disable; IO disable;

 _____ Misc _____
    -t                shows the chameleon table                           [no]
    -n                version information                                 [no]
    -v                verbose mode                                        [no]
    -h / -?           print this help                                     [no]

Examples:
	LPC FPGA (SC24): 
		Dump Chameleon Table: fpga_load -k 0xe000e000 -t
		Program FPGA File:    fpga_load -k 0xe000e000 -z -f -w <filename> 80000
	PCI FPGA (F75P): 
		Dump Chameleon Table: fpga_load 1a88 4d45 b3 0 -t
		Program FPGA File:	  fpga_load 1a88 4d45 b3 0 -z -f -w <filename.rbf> 0

 WARNING: Please be aware that you do FPGA configuration updates at your own risk.
          After an incorrect update your hardware may no longer be accessible.

Copyright (c) 2004-2019, MEN Mikro Elektronik GmbH
mdis_tools_fpga_load_01_22-24-g0482a16_2019-10-18

Built: Dec  9 2019 11:09:32
```
## Use Cases

### List all PCI devices with PCI vendor, device and subvendor IDs

```
# fpga_load -s

Nr.| dom|bus|dev|fun| Ven ID | Dev ID | SubVen ID |
  0|  0   0   0   0   0x8086   0x0c04    0x8086
  1|  0   0   1   0   0x8086   0x0c01    0x0000
  2|  0   0   2   0   0x8086   0x0406    0x8086
...
 13|  0   2   0   0   0x8086   0x1539    0x8086
 14|  0   3   0   0   0x12d8   0xe110    0x0000
 15|  0   4  14   0   0x1a88   0x4d45    0x006a
 16|  0   5   0   0   0x1a88   0x4d45    0x00a2
```

### Show Chameleon table of MEN FPGA

```
# fpga_load 0x1a88 0x4d45 0x006a 0 -t

BARs of FPGA PCI device 04:14.0:
  BAR0: 0xb0500000; size: 0x00000000, mapType: MEM;
  BAR1: 0x00004001; size: 0x00000000, mapType: IO;
  BAR2: 0x00000000; size: 0x00000000, mapType: unused;
  BAR3: 0x00000000; size: 0x00000000, mapType: unused;
  BAR4: 0x00000000; size: 0x00000000, mapType: unused;
  BAR5: 0x00000000; size: 0x00000000, mapType: unused;

Information about the Chameleon FPGA:
FPGA File='215-00IC001A' table model=0x41('A') Revision 1.0 Magic 0xABCE
List of the Chameleon units:
Idx DevId  Module                   Grp Inst Var Rev IRQ BAR Offset     Address
--- ------ ------------------------ --- ---- --- --- --- --- ---------- ----------
  0 0x0018 16Z024_SRAM                0    0   1  12  63   0 0x00000000 0xb0500000
  1 0x007d 16Z125_UART                0    0   0  12   2   0 0x00000100 0xb0500100
  2 0x007d 16Z125_UART                0    1   0  12   3   0 0x00000110 0xb0500110
  3 0x0045 16Z069_RST                 0    0   0  10  63   0 0x00000140 0xb0500140
  4 0x0034 16Z052_GIRQ                0    0   0   6  63   0 0x00000160 0xb0500160
  5 0x0022 16Z034_GPIO                0    0   0  10  63   0 0x00000180 0xb0500180
  6 0x0025 16Z037_GPIO                0    0   1   1   4   0 0x000001a0 0xb05001a0
  7 0x007e 16Z126_SERFLASH            0    0   0   3  63   0 0x000001c0 0xb05001c0
  8 0x001d 16Z029_CAN                 0    0   1  16   0   0 0x00000200 0xb0500200
  9 0x001d 16Z029_CAN                 0    1   1  16   1   0 0x00000300 0xb0500300

 Current FPGA file/usage status: fallback image active, no configuration error occurred.
```

### Program FPGA

- Read current FPGA configuration from flash, e.g.:

  ``# fpga_load 1a88 4d45 6a 0 -z -r 0x0 0x400000 F215-01IC001A4.rbf``

- Programm new FPGA configuration into flash, e.g.:

  ``# fpga_load 1a88 4d45 6a 0 -z -f -w F215-01IC001A4.rbf 0``

## FPGA_LOAD for Linux

### Using fpga_load

fpga_load must be called with root privileges.

### Compiling fpga_load

To compile fpga_load for Linux, you have to:

- Install the MDIS System Package for Linux 13MD05-90
- Use the command line to navigate to the FPGA_LOAD location
- Call make

Example:
```
$ cd /opt/menlinux/TOOLS/FPGA_LOAD/
$ make
```

The fpga_load binary will be created in the current work directory.
