/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!
 *         \file  _amd_smb_stub.c
 *
 *       \author  Christian.Kauntz@men.de
 *        $Date: 2009/03/05 09:52:50 $
 *    $Revision: 2.2 $
 *
 *        \brief  instance for AMD Flash with SMB normal version
 *
 *
 *     Required: -
 *    \switches  (none)
 */
 /*---------------------------[ Public Functions ]----------------------------
 *
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2007 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
 *
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
 ****************************************************************************/
#if defined MAC_BYTESWAP
#undef MAC_BYTESWAP
#endif /* MAC_BYTESWAP */

#undef PROG_FILE_NAME
#define Z100_AM29LVXXX_SMB_TRY Z100_AM29LVXXX_SMB_TRY
#include "am29lvxxx_smb.c"

