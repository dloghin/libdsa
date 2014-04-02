#include "select.h"

/**
 * 
 * @return 
 */
int partition_int(int* a, int n0, int n1)
{
	// TODO - better way of selecting pivot
	int pivot = a[n0];

	while (n0 < n1) {
		while (a[n0] < pivot)
			n0++;

		while (a[n1] > pivot)
			n1--;
        
		if (a[n0] == a[n1])
			n0++;
		else 
			if (n0 < n1) {
				int aux = a[n0];
				a[n0] = a[n1];
				a[n1] = aux;
			}
	}

	return n1;
}

int quick_select_int_recursive(int* a, int n0, int n1, int k)
{
	if (n0 == n1) 
		return a[n0];

	int m = partition_int(a, n0, n1);
	m = m - n0 + 1;
	if (m == k) 
		return a[m];
	else
		if (k < m) 
			return quick_select_int_recursive(a, n0, m-1, k);
		else
			return quick_select_int_recursive(a, m+1, n1, k-m);
}

/**
 * Iterative code to get the element at kth zero-based index if array a[n0..n1] would be sorted.
 * @param n0, n1 - array indexes of array bounds (e.g if array has size 10, then n0 is 0 and n1 is 9)
 * @param k - the zero-based index of the kth element in sorted array 
 * @return - the value of kth element or 0 in case of an exception. Note that 0 can also be a valid value!
 */
int quick_select_bounds_int(int* a, int n0, int n1, int k)
{
	int m;
	
	if (k < 0 || k>n1)
		return 0;

	while (n0 < n1) {
		m = partition_int(a, n0, n1);
		if (m == k)
                	return a[m];
		else
			if (m > k)
                        	n1 = m-1;
			else
				n0 =  m+1;
	}

	return 0;
}

/**
 * Wrapper function. It returns the kth element in the array a[0..n-1].
 */
int quick_select_int(int* a, int n, int k)
{
	return quick_select_bounds_int(a, 0, n-1, k-1);
}

