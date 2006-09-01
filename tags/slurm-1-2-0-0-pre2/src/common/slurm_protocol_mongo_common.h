/*****************************************************************************\
 *  slurm_protocol_mongo_common.h - alternative communications protocol to 
 *	TCP sockets. As of 11/18/2002 it is unclear that this communications
 * 	protocol will be fully developed.
 ****************************************************************************
 *  Copyright (C) 2002 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Kevin Tew <tew1@llnl.gov> 
 *  UCRL-CODE-217948.
 *  
 *  This file is part of SLURM, a resource management program.
 *  For details, see <http://www.llnl.gov/linux/slurm/>.
 *  
 *  SLURM is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *
 *  In addition, as a special exception, the copyright holders give permission 
 *  to link the code of portions of this program with the OpenSSL library under 
 *  certain conditions as described in each individual source file, and 
 *  distribute linked combinations including the two. You must obey the GNU 
 *  General Public License in all respects for all of the code used other than 
 *  OpenSSL. If you modify file(s) with this exception, you may extend this 
 *  exception to your version of the file(s), but you are not obligated to do 
 *  so. If you do not wish to do so, delete this exception statement from your
 *  version.  If you delete this exception statement from all source files in 
 *  the program, then also delete it here.
 *  
 *  SLURM is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with SLURM; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
\*****************************************************************************/

#ifndef _SLURM_PROTOCOL_MONGO_COMMON_H
#define _SLURM_PROTOCOL_MONGO_COMMON_H

#if HAVE_CONFIG_H
#  include "config.h"
#  if HAVE_INTTYPES_H
#    include <inttypes.h>
#  else
#    if HAVE_STDINT_H
#      include <stdint.h>
#    endif
#  endif  /* HAVE_INTTYPES_H */
#else   /* !HAVE_CONFIG_H */
#  include <inttypes.h>
#endif  /*  HAVE_CONFIG_H */

#include <netinet/in.h>

#define AF_SLURM AF_INET
#define SLURM_INADDR_ANY 0x00000000

/* LINUX SPECIFIC */
/* this is the slurm equivalent of the operating system file descriptor, 
 * which in linux is just an int */
typedef uint32_t slurm_fd ;

/* this is the slurm equivalent of the BSD sockets sockaddr */
typedef struct mongo_addr_t slurm_addr ; 
/* this is the slurm equivalent of the BSD sockets fd_set */
typedef fd_set slurm_fd_set ;
/*struct kevin {
	int16_t family ;
	uint16_t port ;
	uint32_t address ;
	char pad[16 - sizeof ( int16_t ) - 
		sizeof (uint16_t) - sizeof (uint32_t) ] ;
} ;
*/

/* SLURM datatypes */
/* this is a custom data type to describe the slurm msg type type 
 * that is placed in the slurm protocol header
 * while just an short now, it may change in the future */
/* Now defined in ../../src/common/slurm_protocol_defs.h
 * typedef uint16_t slurm_msg_type_t ;
 */

#endif
