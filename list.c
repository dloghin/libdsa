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
 * @file list.c
 * @brief List Implementation
 */

#include "list.h"

/**
 * Add an item at the beginning of the list.
 */
int list_add_first(t_list* list, void* data) {
	if (list == NULL)
		return ENULL;

	t_list item = (t_list)malloc(sizeof(item));
	if (!item)
		return EALLOC;

	item->data = data;
	item->next = *list;
	*list = item;

	return SUCCESS;
}

/**
 * Add item to the end of list.
 */
int list_add_last(t_list* list, void* data) {
	if (list == NULL)
			return ENULL;

	t_list item = (t_list)malloc(sizeof(item));
	if (!item)
			return EALLOC;

	item->data = data;
	item->next = NULL;

	t_list end = *list;
	if (end == NULL) {
		*list = item;
		return SUCCESS;
	}

	for (;end->next != NULL; end = end->next);
	end->next = item;

	return SUCCESS;
}

/**
 * Add item according to defined order.
 */
int list_add_order(t_list* list, void* data, int (*comp)(const void* a, const void* b)) {
	if (list == NULL)
		return ENULL;

	t_list item = (t_list)malloc(sizeof(item));
	if (!item)
		return EALLOC;

	item->data = data;

	t_list pos = *list;
	if (pos == NULL) {
		*list = item;
		return SUCCESS;
	}

	if (comp(pos->data, data) >= 0) {
		item->next = pos;
		*list = item;
		return SUCCESS;
	}

	for (;pos->next != NULL && comp(pos->next->data, data) < 0; pos = pos->next);
	item->next = pos->next;
	pos->next = item;

	return SUCCESS;
}

/**
 * Get list length.
 */
int list_len(t_list list) {
	int n = 0;
	for(;list != NULL; list = list->next)  n++;
	return n;
}

/**
 * Apply function to every list item.
 */
void list_apply_func(t_list list, void (*func)(void* data)) {
	for(;list != NULL; list = list->next)
		func(list->data);
}

/**
 * Delete items with the same value as data.
 */
int list_del_data_all(t_list* list, void* data, int (*comp)(const void* a, const void* b)) {
	if (list == NULL)
		return ENULL;

	t_list sentinel = (t_list)malloc(sizeof(sentinel));
	if (sentinel == NULL)
		return EALLOC;
	sentinel->next = *list;

	t_list item = sentinel;
	t_list aux;
	int n = 0;

	while (item->next != NULL) {
		if (comp(item->next->data, data) == 0) {
			aux = item->next;
			item->next = item->next->next;
			free(aux);
			n++;
		}
		item = item->next;
	}
	free(sentinel);

	return n;
}

/**
 * Destroy list.
 */
void list_destroy(t_list list) {
	t_list item;
	while ( list != NULL) {
		item = list;
		list = list->next;
		free(item);
	}
}

/**
 * Destroy list and data.
 */
void list_destroy_data(t_list list) {
	t_list item;
	while (list != NULL) {
		item = list;
		list = list->next;
		free(item->data);
		free(item);
	}
}
