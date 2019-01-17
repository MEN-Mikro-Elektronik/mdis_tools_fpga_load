#***************************  M a k e f i l e  *******************************
#
#         Author: Christian.Schuster@men.de
#          $Date: 2013/04/17 19:00:56 $
#
#    Description: linux makefile descriptor file for fpga_load
#
#-----------------------------------------------------------------------------
# (c) Copyright 2004 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
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
