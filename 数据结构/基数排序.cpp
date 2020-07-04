#include <stdio.h>
#include <stdlib.h>

void radix_sort(int *num, int n) {
	#define maxn_n 65535
	int *cnt = (int *)calloc((maxn_n + 1), sizeof(int));
	int *temp = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		cnt[(num[i] & 65535) + 1] += 1;
	}
	for (int i = 1; i <= 65535; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = 0; i < n; i++) {  // very important
		temp[cnt[num[i] & 65535]++] = num[i];
	}
	memset(cnt, 0, sizeof(int) * maxn_n + 1);
	int *p = temp;
	temp = num;
	num = p;
	for (int i = 0; i < n; i++) {
		cnt[((num[i] >> 16) & 65535) + 1] += 1;
	}
	for (int i = 1; i <= 65535; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = 0; i < n; i++) {  // very important
		temp[cnt[(num[i] >> 16) & 65535]++] = num[i];
	}
	#undef maxn_n
	return ;
}