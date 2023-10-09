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

#include <utils.h>
#include <select.h>

#define NARRAY 5

int comp_int(void* a, void* b) {
	int xa = *(int*)a;
	int xb = *(int*)b;
	return xb-xa;
}

int main() {
	int a[NARRAY] = {5, 2, -1, 3, -7};
	
	printf("Select kth element from: ");
	print_array_int(a, 5);

	int p, v, exp;

	v = quick_select_int(a, 5, 3);
	exp = 2;
	printf("Test - k=%d, result=%d, expected=%d\n", 3, v, exp);
        if (v != exp)
                return -1;

	v = quick_select_int(a, 5, 6);
        exp = 0;
        printf("Test - k=%d, result=%d, expected=%d\n", 3, v, exp);
        if (v != exp)
                return -1;

	

	void** b = (void**)malloc(NARRAY * sizeof(void*));
	if (!b)
		return EALLOC;
	for (p=0; p<NARRAY; p++)
		b[p] = (void*)(a+p);

	free(b);

	printf("Select Test End.\n");

	return 0;
}
