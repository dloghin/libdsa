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

#ifndef LIBDSA_LIST_H
#define LIBDSA_LIST_H

/**
 * @file list.h
 * @brief List Declarations
 */

#include "common.h"

typedef struct _t_list_item {
	void* data;
	struct _t_list_item* next;
} t_list_item, *t_list;

int list_add_first(t_list* list, void* data);

int list_add_last(t_list* list, void* data);

int list_add_order(t_list* list, void* data, int (*comp)(const void* a, const void* b));

int list_len(t_list list);

void list_apply_func(t_list list, void (*func)(void* data));

int list_del_data_all(t_list* list, void* data, int (*comp)(const void* a, const void* b));

void list_destroy(t_list list);

void list_destroy_data(t_list list);

typedef struct _t_dlinked_list_item {
	void* data;
	struct _t_dlinked_list_item* next;
	struct _t_dlinked_list_item* prev;
} t_dlinked_list_item, *t_dlinked_list;

#endif
