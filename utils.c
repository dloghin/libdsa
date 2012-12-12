/**
 * Copyright 2012 Dumi Loghin
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
 * @file utils.c
 * @brief Utilities Implementations
 */

#include "utils.h"

/**
 * Compute log 2 using bit shifts.
 */
int mylog2(int n)
{
	int i;
	int log = 0;
	for (i=0; i<8*sizeof(n); i++) {
		if ((0x1 & n) == 0x1)
			log = i;
		n = n>>1;
	}
	return log;
}
