/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!
 *         \file  _amd_smb_sw_stub.c
 *
 *       \author  Christian.Kauntz@men.de
 *
 *        \brief  instance for AMD Flash with SMB swapped version
 *
 *
 *     Required: -
 *    \switches  (none)
 */
 /*---------------------------[ Public Functions ]----------------------------
 *
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 2007-2019, MEN Mikro Elektronik GmbH
 ****************************************************************************/
 /*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MAC_BYTESWAP
#define MAC_BYTESWAP
#endif

#define Z100_AM29LVXXX_SMB_TRY Z100_AM29LVXXX_SMB_TRY_sw

#undef PROG_FILE_NAME
#include "am29lvxxx_smb.c"
#undef MAC_BYTESWAP
