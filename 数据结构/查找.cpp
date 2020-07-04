#include <stdio.h>
#include <math.h>

#define Epslon 1e-7

int binary_search(int *num, int n, int x) {
	int head = 0, tail = n - 1, mid;
	while (head <= tail) {
		mid = (head + tail) >> 1;
		if (num[mid] == x) return mid;
		if (num[mid] < x) head = mid + 1;
		else tail = mid - 1;
	}
	return 0;
}

int binary_search2(int *num, int n) {
	int head = -1, tail = n - 1, mid;
	while (head < tail) {
		mid = (head + tail + 1) >> 1;
		if (num[mid] == 0) tail = mid - 1;
		else head = mid;
	}
	return head;
}

int binary_search3(int *num, int n) {
	int head = 0, tail = n, mid;
	while (head < tail) {
		mid = (head + tail) >> 1;
		if (num[mid] == 0) head = mid + 1;
		else tail = mid;
	}
	if (head == n) return 0;
	return head;
}



double f(double x) {
	double a = 3.0, b = 2.0, c = 1.0;
	return a * x * x + b * c + c; 
}

double ternary_search(double (*func)(double)) {
	double L = -1000.0, R = 1000.0, m1, m2;
	while (fabs(L - R) > Epslon) {
		m1 = (R - L) / 3.0 + L;
		m2 = 2.0 * (R - L) / 3.0 + L;
		if (func(m1) > func(m2)) L = m1;
		else R = m2;
	}
	#undef Epslon
	return L;
}

int main() {
	int num1[] = {1, 2, 3, 4, 5};
	printf("%d\n", binary_search(num1, 5, 4));
	int num2[] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
	printf("%d\n", binary_search2(num2, 12));
	int num3[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
	printf("%d\n", binary_search3(num3, 12));
	printf("%lf\n", ternary_search(f));
	return 0;
}