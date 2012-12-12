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

#ifndef LIBDSA_HEAP_H
#define LIBDSA_HEAP_H

/**
 * @file heap.h
 * @brief Heap Declarations
 */

#include "common.h"

#define DEFAULT_LEVELS	3

enum heap_type_t {
	MIN_HEAP = 1,
	MAX_HEAP
};

char* type2name(enum heap_type_t type);

typedef struct _heap_int_t {
	enum heap_type_t type;
	size_t size;
	size_t nalloc;
	int* data;
} heap_int_t;

int alloc_int_heap(heap_int_t** heap, enum heap_type_t type, int size);

void destroy_int_heap(heap_int_t** heap);

int insert_int_heap(heap_int_t* heap, int val);

int heapify_int_heap(heap_int_t* heap, int index);

int push_root_int_heap(heap_int_t* heap);

int build_int_heap_attach(heap_int_t** heap, enum heap_type_t type, int n, int* values);

int build_int_heap_copy(heap_int_t** heap, enum heap_type_t type, int n, int* values);

void heap_sort_int(int n, int* array);

void print_tree_int_heap(heap_int_t* heap);

void print_array_int_heap(heap_int_t* heap);

typedef struct _heap_void_t {
        int (*compare)(const void* a, const void* b);
	size_t size;
        size_t nalloc;
        void** data;
} heap_void_t;

int heapify_void_heap(heap_void_t* heap, int index);

int push_root_void_heap(heap_void_t* heap);

int build_void_heap_attach(heap_void_t** heap, int (*comp)(const void* a, const void* b), int n, void** values);

void heap_sort_void(int n, void** array, int (*comp)(const void* a, const void* b));

#endif
