#include "asynctask.h"

int asynctask(void* (*task)(void* args), void* arg) {
	pthread_t th;
	pthread_attr_t attr;

	// set thread detachstate attribute to DETACHED 
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	return pthread_create(&th, &attr, task, arg);
}
