/************************  F P G A _ L O A D  *********************************/
/*!
 *
 *        \file  hw_acc_io.c
 *
 *      \author  Christian.Schuster@men.de
 *
 *       \brief  HW access functions for I/O mapped HW
 *
 *
 *     Required:
 *
 *
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2005-2019, MEN Mikro Elektronik GmbH
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

#ifdef Z100_IO_ACCESS_ENABLE

#if defined X86
# include <sys/io.h>
#endif

#ifndef VXWORKS
# ifdef MAC_MEM_MAPPED
#	undef MAC_MEM_MAPPED
# endif
# ifndef MAC_IO_MAPPED
#	define MAC_IO_MAPPED
# endif
#else
# if CPU_FAMILY==PPC
#   ifndef MAC_MEM_MAPPED
#	  define MAC_MEM_MAPPED
#   endif
#   ifdef MAC_IO_MAPPED
#	  undef MAC_IO_MAPPED
#   endif
# endif
#endif

#undef PROG_FILE_NAME
#include "fpga_load.h"
#include <MEN/maccess.h>
#if defined(WINNT) && defined(_WIN64)
 #include <MEN/genacc.h>
#endif

extern u_int8 Z100_Mread_Io_D8(
	void *ma,
	u_int32 offs
)
{
#if defined(WINNT) && defined(_WIN64)
	return GENACC_IO_READ_D8((*G_pHga), (ma), (offs));
#else
	return MREAD_D8((MACCESS)ma, offs );
#endif
}


extern u_int16 Z100_Mread_Io_D16(
	void *ma,
	u_int32 offs
)
{
#if defined(WINNT) && defined(_WIN64)
	return GENACC_IO_READ_D16((*G_pHga), (ma), (offs));
#else
	return MREAD_D16((MACCESS)ma, offs );
#endif
}


extern u_int32 Z100_Mread_Io_D32(
	void *ma,
	u_int32 offs
)
{
#if defined(WINNT) && defined(_WIN64)
	return GENACC_IO_READ_D32((*G_pHga), (ma), (offs));
#else
	return MREAD_D32((MACCESS)ma, offs );
#endif
}


extern void Z100_Mwrite_Io_D8(
	void *ma,
	u_int32 offs,
	u_int8 val
)
{
#if defined(WINNT) && defined(_WIN64)
	GENACC_IO_WRITE_D8((*G_pHga), (ma), (offs), (val));
#else
	MWRITE_D8((MACCESS)ma, offs, val );
#endif
	return;
}


extern void Z100_Mwrite_Io_D16(
	void *ma,
	u_int32 offs,
	u_int16 val
)
{
#if defined(WINNT) && defined(_WIN64)
	GENACC_IO_WRITE_D16((*G_pHga), (ma), (offs), (val));
#else
	MWRITE_D16((MACCESS)ma, offs, val );
#endif
	return;
}


extern void Z100_Mwrite_Io_D32(
	void *ma,
	u_int32 offs,
	u_int32 val
)
{
#if defined(WINNT) && defined(_WIN64)
	GENACC_IO_WRITE_D32((*G_pHga), (ma), (offs), (val));
#else
	MWRITE_D32((MACCESS)ma, offs, val );
#endif
	return;
}


/* Swapped versions of the IO functions */


extern u_int8 Z100_Mread_Io_D8_SW(
	void *ma,
	u_int32 offs
)
{
#if defined(WINNT) && defined(_WIN64)
	return GENACC_IO_READ_D8((*G_pHga), (ma), (offs));
#else
	return (u_int8)MREAD_D8( (MACCESS)ma, offs );
#endif
}


extern u_int16 Z100_Mread_Io_D16_SW(
	void *ma,
	u_int32 offs
)
{
	u_int16 temp;
#if defined(WINNT) && defined(_WIN64)
	temp = GENACC_IO_READ_D16((*G_pHga), (ma), (offs));
#else
	temp = MREAD_D16((MACCESS)ma, offs );
#endif
	temp = OSS_SWAP16(temp);
	return (temp);
}


extern u_int32 Z100_Mread_Io_D32_SW(
	void *ma,
	u_int32 offs
)
{
	u_int32 temp;
#if defined(WINNT) && defined(_WIN64)
	temp = GENACC_IO_READ_D32((*G_pHga), (ma), (offs));
#else
	temp = MREAD_D32((MACCESS)ma, offs );
#endif
	temp = OSS_SWAP32(temp);
	return (temp);
}


extern void Z100_Mwrite_Io_D8_SW(
	void *ma,
	u_int32 offs,
	u_int8 val
)
{
#if defined(WINNT) && defined(_WIN64)
	GENACC_IO_WRITE_D8((*G_pHga), (ma), (offs), (val));
#else
	MWRITE_D8((MACCESS)ma, offs, val );
#endif
	return;
}


extern void Z100_Mwrite_Io_D16_SW(
	void *ma,
	u_int32 offs,
	u_int16 val
)
{
	u_int16 temp;

	temp = OSS_SWAP16(val);
#if defined(WINNT) && defined(_WIN64)
	GENACC_IO_WRITE_D16((*G_pHga), (ma), (offs), (val));
#else
	MWRITE_D16((MACCESS)ma, offs, temp );
#endif
	return;
}


extern void Z100_Mwrite_Io_D32_SW(
	void *ma,
	u_int32 offs,
	u_int32 val
)
{
	u_int32 temp;
	temp = OSS_SWAP32(val);
#if defined(WINNT) && defined(_WIN64)
	GENACC_IO_WRITE_D32((*G_pHga), (ma), (offs), (val));
#else
	MWRITE_D32((MACCESS)ma, offs, temp );
#endif
	return;
}


#endif /* Z100_IO_ACCESS_ENABLE */


