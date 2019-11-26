/************************  F P G A _ L O A D  *********************************/
/*!
 *
 *        \file  hw_acc_mmod.c
 *
 *      \author  andreas.geissler@men.de
 *
 *       \brief  HW access functions for M-Modules, \n
 *        To be included by each stub and set switches for the swapped versions
 *
 *    \switches FL_SWAP_SW       - for swapped Version\n
 *
 *
 *
 *----------------------------------------------------------------------------
 * Copyright 2019, MEN Mikro Elektronik GmbH
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
/*-----------------------------------------+
 |  GLOBALS                                |
 +-----------------------------------------*/

/*-----------------------------------------+
 |  DEFINES                                |
 +-----------------------------------------*/
#ifndef MAC_MEM_MAPPED
#  define MAC_MEM_MAPPED
#endif

#ifdef MAC_IO_MAPPED
#  undef MAC_IO_MAPPED
#endif

#include <MEN/men_typs.h>
#include <MEN/maccess.h>
#include <fpga_load.h>
/*-----------------------------------------+
 |  TYPEDEFS                               |
 +-----------------------------------------*/
/* None */

/*-----------------------------------------+
 |  PROTOTYPES                             |
 +-----------------------------------------*/

#if (  defined FL_SWAP_SW )
#define MMOD_SWAP_VALUE(temp) { temp = OSS_SWAP16(temp); }
#define MMOD_SWAP_OFFS(temp) { temp = OSS_SWAP32(temp); }
#else
#define MMOD_SWAP_OFFS(temp) { temp = temp; }
#define MMOD_SWAP_VALUE(temp) { temp = temp; }
#endif /* FL_SWAP_SW|FL_SWAP_MMOD_SW */

static u_int8  MMOD_Mread_Mem_D8(
   void *ma,
   u_int32 offs
)
{
   u_int8 temp;
   offs *= 2;
   temp = MREAD_D8( (MACCESS)ma, offs );
   DBGOUT(("%s off: 0x%x read: 0x%x\n", __func__, (int)offs, (int)temp));
   return( temp );
}

static u_int16 MMOD_Mread_Mem_D16(
   void *ma,
   u_int32 offs
)
{
   u_int16 temp;
   offs *= 2;
   temp = MREAD_D16( (MACCESS)ma, offs );
   MMOD_SWAP_VALUE(temp);
   DBGOUT(("%s off: 0x%x read: 0x%x\n", __func__, (int)offs, (int)temp));
   return( temp );
}

static u_int32 MMOD_Mread_Mem_D32(
   void *ma,
   u_int32 offs
)
{
   u_int32 temp;
   offs *= 2;
   temp = 0;
   temp |= (MREAD_D8( (MACCESS)ma, offs));
   temp |= (MREAD_D8( (MACCESS)ma, offs+2 ) <<  8);
   temp |= (MREAD_D8( (MACCESS)ma, offs+4 ) << 16);
   temp |= (MREAD_D8( (MACCESS)ma, offs+6 ) << 24);
   MMOD_SWAP_OFFS(temp);
   DBGOUT(("%s off: 0x%x read: 0x%x\n", __func__, (int)offs, (int)temp));
   return( temp );
}

static void MMOD_Mwrite_Mem_D8(
   void *ma,
   u_int32 offs,
   u_int8 val
)
{
   offs *= 2;
   DBGOUT(("%s off: 0x%x write: 0x%x\n", __func__, (int)offs, (int)val));
   MWRITE_D8( (MACCESS)ma, offs, val );
   return;
}

static void MMOD_Mwrite_Mem_D16(
   void *ma,
   u_int32 offs,
   u_int16 val
)
{
   u_int16 temp;
   offs *= 2;
   temp = val;
   MMOD_SWAP_VALUE(temp);
   DBGOUT(("%s off: 0x%x write: 0x%x\n", __func__, (int)offs, (int)temp));
   MWRITE_D8( (MACCESS)ma, offs+2, temp>>8  );
   MWRITE_D8( (MACCESS)ma, offs,   temp     );
   return;
}

static void MMOD_Mwrite_Mem_D32(
   void *ma,
   u_int32 offs,
   u_int32 val
)
{
   u_int32 temp;
   offs *= 2;
   temp = val;
   MMOD_SWAP_OFFS(temp);
   DBGOUT(("%s off: 0x%x write: 0x%x\n", __func__, (int)offs, (int)temp));
   MWRITE_D8( (MACCESS)ma, offs+6, temp>>24 );
   MWRITE_D8( (MACCESS)ma, offs+4, temp>>16 );
   MWRITE_D8( (MACCESS)ma, offs+2, temp>>8  );
   MWRITE_D8( (MACCESS)ma, offs,   temp     );
   return;
}

static void MMOD_Flash_Write( DEV_HDL *h, u_int32 offs, u_int32 val )
{
   DBGOUT(("%s: offs 0x%08x val 0x%08x\n", __func__, (int)offs, (int)val));
   if( !h->smbLocHdl.smbHdl )
   {
      Z100_MWRITE_D32( h->mappedAddr,
                   Z045_FLASH_ADDR_REG_OFFSET,
                   offs);
      if(h->flash_acc_size) /* access 16 bit data bus */
         Z100_MWRITE_D16( h->mappedAddr,
                      Z045_FLASH_DATA_REG_OFFSET,
                      (u_int16)val);
      else           /* access 8 bit data bus */
         Z100_MWRITE_D8( h->mappedAddr,
                     Z045_FLASH_DATA_REG_OFFSET,
                     (u_int8)val);
   } else { /* access over smb */
      printf( "MMOD_FLASH_WRITE: SMB access not implemented here\n");
   }
}

static u_int32 MMOD_Flash_Read( DEV_HDL *h, u_int32 offs )
{
   u_int32 retVal = 0;
   DBGOUT(("%s: offs 0x%08x\n", __func__, (int)offs));
   if( !h->smbLocHdl.smbHdl )
   {
      Z100_MWRITE_D32( h->mappedAddr,
                   Z045_FLASH_ADDR_REG_OFFSET,
                   offs);
      if(h->flash_acc_size) /* access 16 bit data bus */
         retVal = Z100_MREAD_D16( h->mappedAddr,
                            Z045_FLASH_DATA_REG_OFFSET);
      else           /* access 8 bit data bus */
         retVal = Z100_MREAD_D8( h->mappedAddr,
                           Z045_FLASH_DATA_REG_OFFSET);
      /* printf("FLASH_READ MEM addr=0x%08x; offs=0x%08x; val = 0x%08x\n",
             (unsigned int)h->mappedAddr, (unsigned int)offs, (unsigned int)retVal); */
   } else
   {
      printf( "MMOD_FLASH_READ: SMB access not implemented here\n");
      retVal = -1;
   }
   return retVal;
}
