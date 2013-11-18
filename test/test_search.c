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

#define NARRAY 5

int comp_int(void* a, void* b) {
	int xa = *(int*)a;
	int xb = *(int*)b;
	return xb-xa;
}

int main() {
	int a[NARRAY] = {1, 3, 5, 6, 7};

	int p = -1;
	int pc = 3;

	p = bin_search_int(a[pc], a, 0, 4);
	printf("Found at %d (should be %d)\n", p, pc);
	if (p != pc)
		return -1;

	pc = -1;
	p = bin_search_int(10, a, 0, 4);
	printf("Found at %d (should be %d)\n", p, pc);
	if (p != pc)
		return -1;

	void** b = (void**)malloc(NARRAY * sizeof(void*));
	if (!b)
		return EALLOC;
	for (p=0; p<NARRAY; p++)
		b[p] = (void*)(a+p);

	pc = 2;
	void* px = (void*)(a+pc);
	p = bin_search(px, b, 0, 4, comp_int);
	printf("Found at %d (should be %d)\n", p, pc);
        if (p != pc)
                return -1;

	pc = -1;
	px = (void *)(&pc);
        p = bin_search(px, b, 0, 4, comp_int);
	printf("Found at %d (should be %d)\n", p, pc);
        if (p != pc)
                return -1;

	free(b);

	printf("Search Test End.\n");

	return 0;
}
