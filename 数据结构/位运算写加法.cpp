#include <stdio.h>

int get_sum(int a, int b) {
	int p = a ^ b;
	int q = (a & b) << 1;
	while (q != 0) {
		a = p;
		b = q;
		p = a ^ b;
		q = (a & b) << 1;
	}
	return p | q;
}


int main() {
	int a, b;
	while (~scanf("%d%d", &a, &b)) {
		int sum = get_sum(a, b);
		printf("%d\n", sum);
	}
	return 0;
}