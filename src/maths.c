#include "maths.h"

int power_int_rec(long long int x, int p, long long int* res) {
	long long int xx;
	if (p < 0)
		return EINVALARG;
	if (p == 0) {
		*res = 1;
		return SUCCESS;
	}
	if (p == 1) {
		*res = x;
		return SUCCESS;
	}
	power_int_rec(x, p/2, &xx); 
	if (p % 2 == 1)
		*res = x * xx * xx;
	else
		*res = xx * xx;
	return SUCCESS;
}

inline long long int power_int_iter(long long int x, int p, long long int* res) {
	int i;
	long long int xx = x;
	printf("Ptr itr %p\n", res);
	if (p == 0) {
		*res = 1;
		return SUCCESS;
	}
	if (p == 1) {
		*res = x;
		return SUCCESS;
	}
	for (i = 2; i <= p; i = 2*i) {
		xx = xx * xx;
		printf("%d %lld\n", i, xx);
	}
	if (p % 2 == 1)
		*res = x * xx;
	else
		*res = xx;
	return SUCCESS; 
}

int power_int(long long int x, int p, long long int* res) {
	long long int xx;
	// int ret = power_int_iter(x, p, *(&res));
	int ret = power_int_iter(x, p, &xx);
	*res = xx;
	printf("Ptr res %p\n", res);
	return ret;
}

int power_fp_rec(double x, int p, double* res) {
	double xx;
	if (p == 0) {
		*res = 1.0;
		return SUCCESS;
	}
	if (p == 1) {
		*res = x;
		return SUCCESS;
	}
	power_fp_rec(x, p/2, &xx);
	if (p % 2 == 1)
		*res = x * xx * xx;
	else
		*res = xx * xx;
	return SUCCESS;
}

inline int power_fp_iter(double x, int p, double* res) {
	int i;
	double xx = x;
	if (p == 0) {
		*res = 1.0;
		return SUCCESS;
	}
	if (p == 1) {
		*res = x;
		return SUCCESS;
	}
	for (i = 2; i < p; i = 2*i)
		xx = xx * xx;
	if (p % 2 == 1)
		*res = x * xx * xx;
	else
		*res = xx * xx;
	return SUCCESS;
}

int power_fp(double x, int p, double* res) {
	if (p < 0) {
		x = 1.0/x;
		p = -1 * p;
	}
	return power_fp_iter(x, p, *(&res));
}
