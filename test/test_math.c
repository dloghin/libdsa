#include "maths.c"

int main() {
	long long int xi = 2;
	long long int xir;
	double xd = 2.0;
	double xdr;

	printf("Ptr xir %p\n", &xir);

	power_int(xi, 0, &xir);
	if (xir != 1) {
		printf("Result %lld, expected 1\n", xir);
		return -1;
	}
	power_int(xi, 1, &xir);
        if (xir != 2) {
		printf("Result %lld, expected 2\n", xir);
                return -1;
	}
	power_int(xi, 10, &xir);
        if (xir != 1024) {
		printf("Result %lld, expected 1024\n", xir);
                return -1;
	}

	power_fp(xd, 0, &xdr);
	if (xdr != 1.0) {
		printf("Result %lf, expected 1.0\n", xdr);
                return -1;
	}
	power_fp(xd, 1, &xdr);
        if (xdr != 2.0) {
		printf("Result %lf, expected 2.0\n", xdr);
                return -1;
	}
	power_fp(xd, 10, &xdr);
        if (xdr != 1024.0) {
		printf("Result %lf, expected 1024.0\n", xdr);
                return -1;
	}
	power_fp(xd, -1, &xdr);
        if (xdr != 0.5) {
		printf("Result %lf, expected 0.5\n", xdr);
                return -1;
	}

	return 0;
}

