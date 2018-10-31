/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!
 *         \file  flash_com.c
 *
 *       \author  Christian.Schuster@men.de
 *        $Date: 2009/03/05 09:52:48 $
 *    $Revision: 1.9 $
 *
 *        \brief  common command set for all flash memory devices
 *
 *
 *     Required: -
 *     \switches (none)
 */
/*---------------------------[ Public Functions ]----------------------------
 *
 *  Z100_FLASH_READ_BLOCK       read specified number of bytes from device
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2004-2009 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
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

#undef PROG_FILE_NAME
#include "fpga_load.h"
#include "fpga_load_flash.h"
/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/
#if defined(_LITTLE_ENDIAN_)
# define SW16(dword) 	(dword)
#elif defined(_BIG_ENDIAN_)
# define SW16(dword) OSS_SWAP16(dword)
#else
# error "Define _BIG_ENDIAN_ or _LITTLE_ENDIAN_"
#endif /* _BIG/_LITTLE_ENDIAN_ */

/*--------------------------------------+
|   TYPDEFS                             |
+--------------------------------------*/

/*--------------------------------------+
|   EXTERNALS                           |
+--------------------------------------*/
/* none */

/*--------------------------------------+
|   GLOBALS                             |
+--------------------------------------*/

/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/

/********************************* Z100_ReadBlocks ****************************/
/** Standard Read routine for all flash devices
 *
 *---------------------------------------------------------------------------
 *  \param	fDev	\IN		FLASH_DEVS handle
 *  \param	offs	\IN		start offset within device
 *  \param	len		\IN		length (in bytes) to be read
 *  \param	buf		\IN		destination buffer
 *
 *  \return	success (0)
 ****************************************************************************/
extern int32 Z100_FLASH_READ_BLOCK(
    FLASH_DEVS *fDev,
	u_int32 offs,
    u_int32 len,
    u_int8  *buf)
{
	u_int32 retVal, offset = offs; /* offs always a multiple of 2 */
	u_int32 nAccess; /* number of accesses necessary */
	u_int8  *bufp8 = NULL;
	u_int16 *bufp16 = NULL;
	DEV_HDL *h = fDev->devHdl;

	DBGOUT(( "FLASH::COM::ReadBlock offs=0x%08x len=0x%08x\n",
			 (int)offs, (int)len ));

	if( fDev->devHdl->flash_acc_size )/* access 16 bit data bus */
	{
		nAccess = len / 2 + len%2;
		bufp16 = (u_int16*)buf;
	} else {
		nAccess = len;
		bufp8 = (u_int8*)buf;
	}

	while(nAccess>0){

		/*--- read word by word or byte by byte, extracting valid bytes ---*/
		retVal = Z100_FLASH_READ( fDev->devHdl, offset);
		/*printf( "%s(%d) naccess = %4d, offset: 0x%08x, read value: 0x%08x fl_acc_s: 0x%02x\n",
				__FUNCTION__, __LINE__, nAccess, offset, retVal,fDev->devHdl->flash_acc_size);
		*/
		if( fDev->devHdl->flash_acc_size )/* access 16 bit data bus */
		{
			if (fDev->devHdl->flashDev.devId == 0x227E){
			    retVal = SW16((u_int16)retVal);
			}
			*bufp16++ = (u_int16)retVal;
			nAccess--;
			offset+=2;
		} else {
			*bufp8++ = (u_int8)retVal;
			nAccess--;
			offset++;
		}
	}
	return 0;
}

