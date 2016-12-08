#include <stdio.h>
#include <unistd.h>
#include "asynctask.h"

void* change(void *arg) {
	int* x = (int*)arg;
	*x = *x + 1;
	return NULL;
}
int main() {
	int x = 1;
	printf("Before task: %d\n", x);
	asynctask(change, (void*)&x);
	printf("After task: %d\n", x);
	sleep(2);
	printf("After sleep: %d\n", x);	
	if (x != 2)
		return -1;
	return 0;
}
