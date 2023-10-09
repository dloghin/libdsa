/**
 * Copyright 2014 Dumi Loghin
 *
 * This file is part of libdsa.
 *
 * libdsa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libdsa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser Public License
 * along with libdsa.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file bucket.h
 * @brief Buckets Definitions
 */

# include "common.h"

typedef unsigned char 		bool_bucket_unit_t;
typedef bool_bucket_unit_t* 	bool_bucket_t;

typedef unsigned char 		bool_t;

bool_bucket_t bb_init(int n);

void bb_destroy(bool_bucket_t* bb);

// void bb_set(int index, bool_t val);
#define BB_SET(bb, i, v)	(bb)[(i)>>3] = ((v)==0) ? ((bb)[(i)>>3] & ~(1<<((i)%8))) : ((bb)[(i)>>3] | (1<<((i)%8)))

// bool_t bb_get(int index);
#define BB_GET_RAW(bb, i)		((bb)[(i)>>3] & (1<<((i)%8)))
#define BB_GET_BOOL(bb, i)               (((bb)[(i)>>3] & (1<<((i)%8))) > 0)

