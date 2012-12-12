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

#include "list.h"

int ints[6] = {2, 4, 3, 6, 1, 5};

void print_int(void* data) {
	int* d = (int*)data;
	printf("%d ", *d);
}

int comp_int(const void* a, const void* b) {
	int xa = *(int*)a;
	int xb = *(int*)b;

	return xa-xb;
}

int main(int argc, char** argv) {
	t_list L = NULL;

	list_add_first(&L, ints);
	list_add_order(&L, ints+1, comp_int);
	list_add_order(&L, ints+2, comp_int);
	list_add_order(&L, ints+3, comp_int);
	list_add_order(&L, ints+5, comp_int);
	list_add_order(&L, ints+4, comp_int);

	list_del_data_all(&L, ints+4, comp_int);

	list_apply_func(L, print_int);

	list_destroy(L);

	return 0;
}
