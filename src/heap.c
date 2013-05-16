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
 * @file heap.c
 * @brief Heap Implementation
 */

#include "utils.h"
#include "heap.h"

/**
 * Get heap type.
 */
char* type2name(enum heap_type_t type)
{
	switch (type) {
	case MIN_HEAP:
		return "MinHeap";
	case MAX_HEAP:
		return "MaxHeap";
	default:
		return "None";
	}
}

/**
 * Alloc a new heap and space for data.
 * @param size - if size <= 0, alloc a default size, else alloc 2^(log2(n)+1)
 * @return 0 on success
 */
int alloc_int_heap(heap_int_t** heap, enum heap_type_t type, int size)
{
	int n;
	heap_int_t* h;

	if (*heap != NULL)
		return ENULL;

	h = (heap_int_t*)malloc(sizeof(heap_int_t));
	if (!h)
		return EALLOC;

	if (size <= 0)
		n = 1 << DEFAULT_LEVELS;
	else
		n = 1 << (mylog2(size) + 1);

	h->data = (typeof(h->data))malloc(n * sizeof(h->data));
	if (!(h->data)) {
		free(h);
		return EALLOC;
	}
	h->size = 0;
	h->nalloc = n;
	h->type = type;
	*heap = h;

	return SUCCESS;
}

/**
 * Reallocate space for heap data
 */
int realloc_int_heap(heap_int_t* heap)
{
	if (heap == NULL)
		return ENULL;

	typeof(heap->data) aux;
	int n = heap->nalloc << 1;
	aux = (typeof(heap->data))realloc(heap->data, n * sizeof(heap->data));
	if (!aux) {
		return EALLOC;
	}
	heap->data = aux;
	heap->nalloc = n;

	return SUCCESS;
}

/**
 * Destroy heap and heap data!
 */
void destroy_int_heap(heap_int_t** heap)
{
	if (heap == NULL)
		return;
	if (*heap == NULL)
		return;

	free((*heap)->data);
	free(*heap);
	*heap = NULL;
}

/**
 * Insert a value in heap.
 */
int insert_int_heap(heap_int_t* heap, int val)
{
	if (heap == NULL)
		return ENULL;

	if (heap->size == heap->nalloc)
		if (realloc_int_heap(heap) != SUCCESS)
			return EALLOC;

	int aux;
	int pos = heap->size;
	int parent = (pos-1)/2;
	heap->data[pos] = val;
	int cont = 1;

	switch (heap->type) {
	case MIN_HEAP:
		while (parent >= 0 && cont) {
			cont = 0;
			if (heap->data[pos] < heap->data[parent]) {
				aux = heap->data[parent];
				heap->data[parent] = heap->data[pos];
				heap->data[pos] = aux;

				pos = parent;
				parent = (parent-1)/2;
				cont = 1;
			}
		}
		break;
	case MAX_HEAP:
		while (parent >= 0 && cont) {
			cont = 0;
			if (heap->data[pos] > heap->data[parent]) {
				aux = heap->data[parent];
				heap->data[parent] = heap->data[pos];
				heap->data[pos] = aux;

				pos = parent;
				parent = (parent-1)/2;
				cont = 1;
			}
		}
		break;
	}

	return SUCCESS;
}

/**
 * Push the value on index 0 (root) into heap if it does not respect
 * heap property
 */
int push_root_int_heap(heap_int_t* heap)
{
	int aux;
	int parent = 0;
	int child = 2*parent+1;
	int index = parent;

	switch (heap->type) {
	case MIN_HEAP:
		while (child < heap->size) {
			if (heap->data[index] > heap->data[child])
				index = child;
			if (child+1 < heap->size && (heap->data[index] > heap->data[child+1]))
				index = child+1;
			if (index != parent) {
				aux = heap->data[parent];
				heap->data[parent] = heap->data[index];
				heap->data[index] = aux;
				parent = index;
				child = 2*parent+1;
			}
			else
				break;
		}
		break;
	case MAX_HEAP:
		while (child < heap->size) {
			if (heap->data[index] < heap->data[child])
				index = child;
			if (child+1 < heap->size && (heap->data[index] < heap->data[child+1]))
				index = child+1;
			if (index != parent) {
				aux = heap->data[parent];
				heap->data[parent] = heap->data[index];
				heap->data[index] = aux;
				parent = index;
				child = 2*parent+1;
			}
			else
				break;
		}
		break;
	}

	return SUCCESS;
}

/**
 * Restore heap property on the sub-heap starting on index.
 * @param index - the starting index of sub-heap
 */
int heapify_int_heap(heap_int_t* heap, int index)
{
	if (heap == NULL)
		return ENULL;

	if (heap->size <= index)
		return EBOUNDS;

	int aux;
	int idx_left;
	int idx_right;
	int pos = index;
	switch (heap->type) {
	case MIN_HEAP:
		while (pos >= 0) {
			idx_left = 2*index+1;
			idx_right = 2*index+2;
			if (idx_left < heap->size && heap->data[idx_left] < heap->data[pos])
				pos = idx_left;
			if (idx_right < heap->size && heap->data[idx_right] < heap->data[pos])
				pos = idx_right;
			if (pos != index) {
				aux = heap->data[index];
				heap->data[index] = heap->data[pos];
				heap->data[pos] = aux;
				index = pos;
			}
			else
				pos = -1;
		}
		break;
	case MAX_HEAP:
		while (pos >= 0) {
			idx_left = 2*index+1;
			idx_right = 2*index+2;
			if (idx_left < heap->size && heap->data[idx_left] > heap->data[pos])
				pos = idx_left;
			if (idx_right < heap->size && heap->data[idx_right] > heap->data[pos])
				pos = idx_right;
			if (pos != index) {
				aux = heap->data[index];
				heap->data[index] = heap->data[pos];
				heap->data[pos] = aux;
				index = pos;
			}
			else
				pos = -1;
		}
		break;
	}
	return SUCCESS;
}

/**
 * Print heap on levels.
 */
void print_tree_int_heap(heap_int_t* heap)
{
	int h, i, j;

	printf("Heap: size=%d, allocated=%d, type=%s\n", heap->size, heap->nalloc, type2name(heap->type));

	i = 0;
	for (h=0; h<=mylog2(heap->size); h++) {
		for (j=0; j<(1<<h) && i<heap->size; j++, i++)
			printf("%d ", heap->data[i]);
		printf("\n");
	}
	printf("Heap end.\n");
}

/**
 * Print heap as array.
 */
void print_array_int_heap(heap_int_t* heap)
{
	int i;
	printf("Heap: size=%d, allocated=%d, type=%s\n", heap->size, heap->nalloc, type2name(heap->type));
	for (i=0; i<heap->size; i++)
		printf("%d ", heap->data[i]);
	printf("\nHeap end.\n");
}

/**
 * Build a heap from an array of integers by copying the values.
 */
int build_int_heap_copy(heap_int_t** heap, enum heap_type_t type, int n, int* values)
{
	int i;

	alloc_int_heap(heap, type, n);

	if (*heap == NULL)
		return ENULL;

	for (i=0; i<n; i++)
		(*heap)->data[i] = values[i];
	(*heap)->size = n;

	for (i = n/2; i >= 0; i--)
		heapify_int_heap(*heap, i);

	return SUCCESS;
}

/**
 * Build a heap from an array of integers by assigning heap data pointer to array pointer.
 */
int build_int_heap_attach(heap_int_t** heap, enum heap_type_t type, int n, int* values)
{
	int i;
	heap_int_t* h;

	if (*heap == NULL) {
		h = (heap_int_t*)malloc(sizeof(heap_int_t));
		if (!h)
			return EALLOC;
		*heap = h;
	}
	else
		h = *heap;

	h->size = n;
	h->nalloc = n;
	h->type = type;
	h->data = values;

	for (i = n/2; i >= 0; i--)
		heapify_int_heap(*heap, i);

	return SUCCESS;
}

/**
 * Sort an integer array using Heap Sort
 * @param n - size of array
 * @param array - array of integers
 */
void heap_sort_int(int n, int* array)
{
	int aux;
	int end_idx;

	heap_int_t* heap = NULL;
	build_int_heap_attach(&heap, MAX_HEAP, n, array);

	for (end_idx=n-1; end_idx>=0; end_idx--) {
		aux = heap->data[0];
		heap->data[0] = heap->data[end_idx];
		heap->data[end_idx] = aux;
		heap->size--;
		push_root_int_heap(heap);
	}
	free(heap);
}

/* ============================================================== */

/**
 * Restore heap property on the sub-heap starting on index.
 * @param index - the starting index of sub-heap
 */
int heapify_void_heap(heap_void_t* heap, int index)
{
	if (heap == NULL)
		return EALLOC;

	if (heap->size <= index)
		return EBOUNDS;

	void* aux;
	int idx_left;
	int idx_right;
	int pos = index;

	while (pos >= 0) {
		idx_left = 2*index+1;
		idx_right = 2*index+2;
		if (idx_left < heap->size &&
				heap->compare(heap->data[idx_left], heap->data[pos]) > 0)
			pos = idx_left;
		if (idx_right < heap->size &&
				heap->compare(heap->data[idx_right], heap->data[pos]) > 0)
			pos = idx_right;
		if (pos != index) {
			aux = heap->data[index];
			heap->data[index] = heap->data[pos];
			heap->data[pos] = aux;
			index = pos;
		}
		else
			pos = -1;
	}

	return SUCCESS;
}

/**
 * Push the value on index 0 (root) into heap if it does not respect
 * heap property
 */
int push_root_void_heap(heap_void_t* heap)
{
	void* aux;
	int parent = 0;
	int child = 2*parent+1;
	int index = parent;

	while (child < heap->size) {
		if (heap->compare(heap->data[index], heap->data[child]) < 0)
			index = child;
		if (child+1 < heap->size &&
				heap->compare(heap->data[index], heap->data[child+1]) < 0)
			index = child+1;
		if (index != parent) {
			aux = heap->data[parent];
			heap->data[parent] = heap->data[index];
			heap->data[index] = aux;
			parent = index;
			child = 2*parent+1;
		}
		else
			break;
	}

	return SUCCESS;
}

/**
 * Build a heap from an array of data by assigning heap data pointer to array pointer.
 */
int build_void_heap_attach(heap_void_t** heap, int (*comp)(const void* a, const void* b), int n, void** values)
{
	int i;
	heap_void_t* h;

	if (comp == NULL)
		return ENULL;

	if (*heap == NULL) {
		h = (heap_void_t*)malloc(sizeof(heap_void_t));
		if (!h)
			return EALLOC;
			*heap = h;
	}
	else
		h = *heap;

	h->size = n;
	h->nalloc = n;
	h->compare = comp;
	h->data = values;

	for (i = n/2; i >= 0; i--)
		heapify_void_heap(*heap, i);

	return SUCCESS;
}

/**
 * Sort an abstract array using Heap Sort
 * @param n - size of array
 * @param array - data
 * @param comp - function to compare data
 */
void heap_sort_void(int n, void** array, int (*comp)(const void* a, const void* b))
{
	void* aux;
	int end_idx;

	heap_void_t* heap = NULL;
	build_void_heap_attach(&heap, comp, n, array);

	for (end_idx=n-1; end_idx>=0; end_idx--) {
		aux = heap->data[0];
		heap->data[0] = heap->data[end_idx];
		heap->data[end_idx] = aux;
		heap->size--;
		push_root_void_heap(heap);
	}
	free(heap);
}
