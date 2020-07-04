#include <stdio.h>
#include <stdlib.h>

void conunt_sort(int *num, int n) {
	#define maxn_n 1000
	int *temp = (int *)calloc((1000), sizeof(int));
	for (int i = 0; i < n; i++) {
		temp[num[i]]++;
	}

	for (int i = 0; i <= 1000; i++) {
		if (temp[i] == 0) continue;
		while (temp[i]--) {
			printf("%d ", i);
		}
	}
	printf("\n");
	free(temp);
	#undef maxn_n
	return ;
}