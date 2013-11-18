/**
 * Copyright 2013 Dumi Loghin
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

#include <search.h>

/**
 * Find the index of an integer element using binary search.
 *
 * @return - the index of the first found occurence or -1 in case of no occurences
 */
int bin_search_int(int val, int* vals, int n0, int n1) {
	int m;
	while (n0 <= n1) {
		m = n0 + ((n1 - n0)>>1);
		if (val == vals[m])
			return m;
		else
			if (val < vals[m])
				n1 = m-1;
			else
				n0 = m+1;
	}
	return -1;
}

/**
 * Find the index of a generic element using binary search.
 *
 * @return - the index of the first found occurence or -1 in case of no occurences
 */
int bin_search(void* val, void** vals, int n0, int n1, int (*comp)(void* a, void* b)) {
	int m;
	while (n0 <= n1) {
		m = n0 + ((n1 - n0)>>1);
		if (comp(val, vals[m]) == 0)
			return m;
		else
			if (comp(val, vals[m]) < 0)
				n1 = m-1;
			else
				n0 = m+1;
	}
	return -1;
}
