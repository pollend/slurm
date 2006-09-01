/****************************************************************************\
 *  sbcast.h - definitions used for sbcast data functions
 *
 *  $Id: sbcast.h 6965 2006-01-04 23:31:07Z jette $
 *****************************************************************************
 *  Copyright (C) 2006 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Morris Jette <jette1@llnl.gov>
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
\****************************************************************************/

#ifndef _SBCAST_H
#define _SBCAST_H

#if HAVE_CONFIG_H
#  include "config.h"
#endif

#include <slurm/slurm.h>
#include <src/common/macros.h>
#include <src/common/slurm_protocol_defs.h>

struct sbcast_parameters {
	uint32_t block_size;
	bool compress;
	int  fanout;
	bool force;
	bool preserve;
	int  verbose;
	char *src_fname;
	char *dst_fname;
};

extern struct sbcast_parameters params;

extern void parse_command_line(int argc, char *argv[]);
extern void send_rpc(file_bcast_msg_t *bcast_msg,
		     job_alloc_info_response_msg_t *alloc_resp);

#endif
