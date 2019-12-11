#***************************  M a k e f i l e  *******************************
#
#         Author: Christian.Schuster@men.de
#
#    Description: linux makefile descriptor file for fpga_load
#
#-----------------------------------------------------------------------------
#   Copyright 2004-2019, MEN Mikro Elektronik GmbH
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

# The swapped FPGA_LOAD is identically to the normal FPGA_LOAD
# During init and scanning for flash type also the swapped functions are used
# so if the flash will be found with a swapped function, then automatically
# all swapped function will be used. For fpga_load.c _BIG_ENDIAN_ and _LITTLE_ENDIAN_
# are used to select swap function. 
include $(MEN_MOD_DIR)/program.mak

MAK_NAME=fpga_load_sw
# the next line is updated during the MDIS installation
STAMPED_REVISION="mdis_tools_fpga_load_01_22-16-g4f1b677-dirty_2019-05-29"

DEF_REVISION=MAK_REVISION=$(STAMPED_REVISION)
MAK_SWITCH=$(SW_PREFIX)$(DEF_REVISION)
