/**
 * Copyright 2019 Dumi Loghin
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

#include "fast_set.h"

/**
 * A data structure that holds integer values, 0 <= n <= MAX and supports these operations in O(1):
 * - add(n)
 * - delete(n)
 * - pop() - get the last value added (which was not deleted yet)
 * - clear() - this is not really O(1) if we want to avoid memry leaks.
 */

/* Maximum elements in the data structure */
#define MAX	1000000

typedef struct node {
	int val;
	struct node* next;
	struct node* prev;
} List;

List* head = NULL;
List* last = NULL;
List* ptr[MAX] = {NULL};

List* add_node(int n) {
	if (head == NULL) {
		head = (List*)malloc(sizeof(List));
		head->val = -1;
		head->next = NULL;
		head->prev = NULL;
		last = head;
	}
	List* new_node = (List*)malloc(sizeof(List));
	if (new_node == NULL)
		return NULL;
	new_node->val = n;
	new_node->next = NULL;
	new_node->prev = last;
	last->next = new_node;
	last = new_node;
	return last;
}

void delete_node(List* del_node) {
	if (del_node == NULL)
		return;
	if (del_node->prev == NULL)
		return;
	del_node->prev->next = del_node->next;
	if (del_node->next != NULL)
		del_node->next->prev = del_node->prev;
	if (last == del_node)
		last = del_node->prev;
	free(del_node);
}

void delete_list() {
	List* p = head->next;
	List* curr;
	while (p != NULL) {
		curr = p;
		p = p->next;
		free(curr);
	}
}

void print_list() {
	List* p = head->next;
	while (p != NULL) {
		printf("-> %d ", p->val);
		p = p->next;
	}
	printf("\n");
}

/**
 * Add int value to the set.
 * @return 0 - in case of success, < 0 - for failures.
 */
int add(int n) {
	if (ptr[n] != NULL)
		return EINVALARG;
	ptr[n] = add_node(n);
	if (ptr[n] != NULL)
		return SUCCESS;
	return EERROR;
}

/**
 * Delete int value from the set.
 * @return 0 - in case of success, EINVALARG - if n is not in the set.
 */
int delete(int n) {
	if (ptr[n] == NULL)
		return EINVALARG;
	delete_node(ptr[n]);
	ptr[n] = NULL;
	return SUCCESS;
}

/**
 * Get and delete the last value added to the set.
 * @return -1 - in case of failure, the value - in case of success.
 */
int pop() {
	if (last == NULL)
		return -1;
	int val = last->val;
	delete_node(last);
	return val;
}

/* This cannot be truly O(1) */
int clear() {
	delete_list(head);
	head->next = NULL;
	last = head;
	return SUCCESS;
}

