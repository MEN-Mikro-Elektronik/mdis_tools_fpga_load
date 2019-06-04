#***************************  M a k e f i l e  *******************************
#
#         Author: Christian.Schuster@men.de
#
#    Description: linux makefile descriptor file for fpga_load
#
#-----------------------------------------------------------------------------
#   Copyright (c) 2004-2019, MEN Mikro Elektronik GmbH
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#*****************************************************************************

MAK_NAME=fpga_load
# the next line is updated during the MDIS installation
STAMPED_REVISION="mdis_tools_fpga_load_01_22-16-g4f1b677-dirty_2019-05-29"

DEF_REVISION=MAK_REVISION=$(STAMPED_REVISION)

MAK_SWITCH= \
		$(SW_PREFIX)$(DEF_REVISION) \

#            $(SW_PREFIX)Z100_CONFIG_VME \
#            $(SW_PREFIX)MAC_USERSPACE\
#            $(SW_PREFIX)Z100_IO_ACCESS_ENABLE \
#            $(SW_PREFIX)Z100_CONFIG_SMB \
#            $(SW_PREFIX)DBG\
#            $(SW_PREFIX)NO_IDPROM_CHECK

MAK_LIBS= 	$(LIB_PREFIX)$(MEN_LIB_DIR)/usr_oss$(LIB_SUFFIX)			\
			$(LIB_PREFIX)$(MEN_LIB_DIR)/usr_utl$(LIB_SUFFIX)			\
        	$(LIB_PREFIX)$(MEN_LIB_DIR)/chameleon_usr$(LIB_SUFFIX)		\
        	$(LIB_PREFIX)$(MEN_LIB_DIR)/chameleon_usr_io$(LIB_SUFFIX)	\
        	$(LIB_PREFIX)$(MEN_LIB_DIR)/chameleon_usr_sw$(LIB_SUFFIX)	\
        	$(LIB_PREFIX)$(MEN_LIB_DIR)/chameleon_usr_io_sw$(LIB_SUFFIX)\
        	$(LIB_PREFIX)$(MEN_LIB_DIR)/oss_usr$(LIB_SUFFIX)			\
        	$(LIB_PREFIX)$(MEN_LIB_DIR)/dbg_usr$(LIB_SUFFIX)			\

# for VXWORKS, in case BSP does not include the SMB2 library:
#MAK_LIBS+=	$(LIB_PREFIX)$(MEN_LIB_DIR)/smb2_all_usr$(LIB_SUFFIX) \

# for LINUX:
#MAK_LIBS+=	$(LIB_PREFIX)$(ELINOS_PROJECT)/src/pciutils/lib/libpci$(LIB_SUFFIX)\
#			$(LIB_PREFIX)$(MEN_LIB_DIR)/vme4l_api$(LIB_SUFFIX) \

# check for QNX:
#ifdef MEN_QNX_DIR
#	MAK_LIBS +=	$(LIB_PREFIX)$(MEN_LIB_DIR)/../men-oss$(DBGSUFFIX)$(LIB_SUFFIX)
#	ifeq ($(USE_VME_SERVER),yes)
#		MAK_LIBS +=	$(LIB_PREFIX)$(MEN_LIB_DIR)/../men-libc$(LIB_SUFFIX)
#	endif
#endif

MAK_INCL=$(MEN_INC_DIR)/men_typs.h \
		$(MEN_INC_DIR)/smb2.h \
		$(MEN_INC_DIR)/usr_oss.h \
		$(MEN_INC_DIR)/usr_err.h \
		$(MEN_INC_DIR)/usr_utl.h \
		$(MEN_INC_DIR)/fpga_header.h \
		$(MEN_MOD_DIR)/../COM/fpga_load.h \
		$(MEN_MOD_DIR)/../COM/hw_acc.c \
		$(MEN_MOD_DIR)/../COM/hw_acc_mmod.c \
		$(MEN_MOD_DIR)/../COM/istratapc28fxxxp30.c \
		$(MEN_MOD_DIR)/../COM/am29lvxxx.c \
		$(MEN_MOD_DIR)/../COM/am29lvxxx_smb.c \
		$(MEN_MOD_DIR)/../COM/stm25p32.c \

MAK_INP1=_amd_stub$(INP_SUFFIX)
MAK_INP2=_amd_sw_stub$(INP_SUFFIX)
MAK_INP3=_amd_smb_stub$(INP_SUFFIX)
MAK_INP4=_amd_smb_sw_stub$(INP_SUFFIX)
MAK_INP5=_istrata_stub$(INP_SUFFIX)
MAK_INP6=_istrata_sw_stub$(INP_SUFFIX)
MAK_INP7=_istrata_mmod_stub$(INP_SUFFIX)
MAK_INP8=_istrata_mmod_sw_stub$(INP_SUFFIX)
MAK_INP9=fpga_load$(INP_SUFFIX)
MAK_INP10=flash_com$(INP_SUFFIX)
MAK_INP11=hw_acc_io$(INP_SUFFIX)
MAK_INP12=_st_stub$(INP_SUFFIX)
MAK_INP13=_st_sw_stub$(INP_SUFFIX)

MAK_INP=$(MAK_INP1)\
		$(MAK_INP2)\
		$(MAK_INP3)\
		$(MAK_INP4)\
		$(MAK_INP5)\
		$(MAK_INP6)\
		$(MAK_INP7)\
		$(MAK_INP8)\
		$(MAK_INP9)\
		$(MAK_INP10)\
		$(MAK_INP11)\
		$(MAK_INP12)\
		$(MAK_INP13)\

