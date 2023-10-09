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

#include "bucket.h"

int main() {
	bool_bucket_t bb;
	int i, v, n = 1024;
	bb = bb_init(n);
	printf("Bucket logic size: %d\nBucket memory size: %d B\n", n, n / (8 * sizeof(bool_bucket_unit_t)) + 1);

	BB_SET(bb, 5, 1);
	BB_SET(bb, n-1, 1);
	v = BB_GET_BOOL(bb, 5);
	printf("Bucket 5 is %d (should be 1)\n", v);

	v = 0;
	for (i=0; i<n; i++)
		v += BB_GET_BOOL(bb, i);
	printf("Bucket has %d 1s (should have 2)\n", v);

	return 0;
}
