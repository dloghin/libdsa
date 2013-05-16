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

#include "heap.h"

int comp_int(const void* a, const void* b)
{
	int xa = *(int*)a;
	int xb = *(int*)b;
	return xb - xa;
}

int main() {
	int i;
	int n = 8;
	int vals[8] = {9, 4, 5, 3, 1, 2, 10, 3};

	heap_int_t* heap = NULL;

	build_int_heap_copy(&heap, MAX_HEAP, n, vals);

	print_tree_int_heap(heap);

	destroy_int_heap(&heap);

	// heap_sort_int(n, vals);
	// for (i=0; i<n; i++) printf("%d ", vals[i]);
	void** avals = (void**)malloc(n*sizeof(void*));
	for (i=0; i<n; i++) avals[i] = vals+i;

	heap_sort_void(n, avals, comp_int);

	for (i=0; i<n; i++) printf("%d ", *(int*)(avals[i]));

	printf("\nHeap Test End.\n");

	free(avals);

	return 0;
}
