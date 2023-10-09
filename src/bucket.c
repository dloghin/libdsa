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
 * @file bucket.c
 * @brief Buckets Implementation
 */

#include "bucket.h"

bool_bucket_t bb_init(int n) {
	n = n / (8 * sizeof(bool_bucket_unit_t)) + 1;
	bool_bucket_t bb = (bool_bucket_t)malloc(n * sizeof(bool_bucket_unit_t));
	if (!bb)
		return NULL;
	memset(bb, 0, n * sizeof(bool_bucket_unit_t));
	return bb;
}

void bb_destroy(bool_bucket_t* bb) {
	free(*bb);
}
