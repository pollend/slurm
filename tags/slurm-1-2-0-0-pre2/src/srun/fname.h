/*****************************************************************************\
 * src/srun/fname.c - IO filename type implementation (srun specific)
 *****************************************************************************
 *  Copyright (C) 2002 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Mark Grondona <mgrondona@llnl.gov>.
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

#ifndef _FNAME_H
#define _FNAME_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif 

#include "src/common/global_srun.h"

enum io_t {
	IO_ALL          = 0, /* multiplex output from all/bcast stdin to all */
	IO_ONE          = 1, /* output from only one task/stdin to one task  */
	IO_PER_TASK     = 2, /* separate output/input file per task          */
	IO_NONE         = 3, /* close output/close stdin                     */
};

#define format_io_t(t) (t == IO_ONE) ? "one" : (t == IO_ALL) ? \
                                                     "all" : "per task"

struct io_filename {
	char      *name;
	enum io_t  type;
	int        taskid;  /* taskid for IO if IO_ONE */
};

/*
 * Create an filename from a (probably user supplied) filename format.
 * fname_create() will expand the format as much as possible for srun,
 * leaving node or task specific format specifiers for the remote 
 * slurmd to handle.
 */
typedef struct srun_job fname_job_t;

io_filename_t *fname_create(fname_job_t *job, char *format);
void fname_destroy(io_filename_t *fname);

char * fname_remote_string (io_filename_t *fname);

#endif /* !_FNAME_H */

