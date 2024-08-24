#ifndef AD_CHFS_COMMON_H_INCLUDED
#define AD_CHFS_COMMON_H_INCLUDED

#include <limits.h>
#include "adio.h"

MPI_Offset ADIOI_CHFS_get_size_coll(ADIO_File fd, int* error_code);
#endif
