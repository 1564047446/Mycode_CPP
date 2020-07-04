#include <stdio.h>

//数组中每个数会出现3次，只有1个例外的数仅出现1次。

int get_solution(int *arr, int n) {
	int sum = 0, ans = 0;
	for (int i = 0; i < 32; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += ((arr[j] >> i) & 1);

		}
		printf("%d\n", sum);
		if (sum % 3 == 1) {
			ans = ans | (1 << i);
		}
	}
	printf("%d\n", ans);
	return 0;
}


int main() {
	int arr[1000], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	int ones = 0, twos = 0;
	for (int i = 0; i < n; i++) {  // solution 2
		ones = (~twos) & (ones ^ arr[i]);
		twos = (~ones) & (twos ^ arr[i]);
	}
	get_solution(arr, n);
	return 0;
}