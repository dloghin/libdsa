#include "fast_set.h"

int main(int argc, char** argv) {
	int val;
	add(1);
	add(2);
	add(3);
	print_list();
	val = pop();
	printf("Pop: %d (expected 3)\n ", val);
	if (val != 3)
		return -1;
	print_list();
	val = pop();
	printf("Pop: %d (expected 2)\n", val);
	if (val != 2)
			return -1;
	print_list();
	delete(2);
	delete(1);
	print_list();
	val = pop();
	printf("Pop: %d (expected -1)\n", val);
	if (val != -1)
			return -1;
	add(4);
	print_list();
	printf("Fast Test End.\n");
	return 0;
}


