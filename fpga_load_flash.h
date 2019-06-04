/***********************  I n c l u d e  -  F i l e  ***********************/
/*!
 *        \file  fpga_load_flash.h
 *
 *      \author  Christian.Schuster@men.de
 *
 *       \brief  Header file for FPGA_LOAD tool
 *               containing Flash specific functions
 *
 *    \switches
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 2004-2019, MEN Mikro Elektronik GmbH
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

#ifndef _FPGA_LOAD_FLASH_H
#define _FPGA_LOAD_FLASH_H

#ifdef __cplusplus
      extern "C" {
#endif

/*-----------------------------------------+
|  TYPEDEFS                                |
+-----------------------------------------*/
/* Flash specific functions */
typedef int32 (*FLASH_READ_BLOCKP)(FLASH_DEVS *, u_int32, u_int32, u_int8 *);
typedef int32 (*FLASH_INITP)(DEV_HDL *h);
typedef int32 (*FLASH_TRYP)(DEV_HDL *, FLASH_INITP *, u_int32);

/*-----------------------------------------+
|  DEFINES                                 |
+-----------------------------------------*/

/*-----------------------------------------+
|  PROTOTYPES                              |
+-----------------------------------------*/

extern int32 Z100_AM29LVXXX_TRY(DEV_HDL *devHdl,
									FLASH_INITP *flash_initP,
									u_int32 dbgLevel);
extern int32 Z100_AM29LVXXX_TRY_sw(DEV_HDL *devHdl,
									   FLASH_INITP *flash_initP,
									   u_int32 dbgLevel);
extern int32 Z100_AM29LVXXX_TRY_mmod(DEV_HDL *devHdl,
									   FLASH_INITP *flash_initP,
									   u_int32 dbgLevel);
extern int32 Z100_AM29LVXXX_TRY_mmod_sw(DEV_HDL *devHdl,
										  FLASH_INITP *flash_initP,
										  u_int32 dbgLevel);

extern int32 Z100_AM29LVXXX_SMB_TRY(DEV_HDL *devHdl,
									FLASH_INITP *flash_initP,
									u_int32 dbgLevel);
extern int32 Z100_AM29LVXXX_SMB_TRY_sw(DEV_HDL *devHdl,
									   FLASH_INITP *flash_initP,
									   u_int32 dbgLevel);

extern int32 Z100_FLASH_READ_BLOCK( FLASH_DEVS *fDev,
									u_int32 offs,
									u_int32 len,
									u_int8  *buf);

extern int32 Z100_ISTRATAPC28FXXXP30_TRY (DEV_HDL *devHdl,
										 	 FLASH_INITP *flash_initP,
										 	 u_int32 dbgLevel);
extern int32 Z100_ISTRATAPC28FXXXP30_TRY_sw(DEV_HDL *devHdl,
										 		FLASH_INITP *flash_initP,
										 		u_int32 dbgLevel);
extern int32 Z100_ISTRATAPC28FXXXP30_TRY_mmod(DEV_HDL *devHdl,
										 	 	FLASH_INITP *flash_initP,
										 	 	u_int32 dbgLevel);
extern int32 Z100_ISTRATAPC28FXXXP30_TRY_mmod_sw(DEV_HDL *devHdl,
										 		   FLASH_INITP *flash_initP,
										 		   u_int32 dbgLevel);

extern int32 Z100_STM25P32_TRY(DEV_HDL *devHdl,
					 		   FLASH_INITP *flash_initP,
					 		   u_int32 dbgLevel);
extern int32 Z100_STM25P32_TRY_sw(DEV_HDL *devHdl,
					 		      FLASH_INITP *flash_initP,
					 		      u_int32 dbgLevel);

#ifdef __cplusplus
      }
#endif

#endif /* _FPGA_LOAD_FLASH_H */


