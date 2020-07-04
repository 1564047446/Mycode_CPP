#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ans[100];
int used[4][100];

void print(int row) {
	for (int i = 0; i < row; i++) {
		if (i == 0) {
			printf("%d", ans[i] + 1);
		} else {
			printf(" %d", ans[i] + 1);
		}
	}
	printf("\n");
}

/*void dfs(int row, int n, int *map, int *cnt) {
	if (row == n) {
		if (*(cnt) < 3) {
			++(*cnt);
			print(row);
			return ;
		} else {
			++(*cnt);
			return ;
		}
	} else {
		for (int i = 0; i < n; i++) {
			map[row] = i;
			int ok = 1;
			for (int j = 0; j < row; j++) {
				if (map[row] == map[j] || row - map[row] == j - map[j] || row + map[row] == j + map[j]) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				ans[row] = i;
				dfs(row + 1, n, map, cnt);
			}
		}
	}
	return ;
}*/

void dfs(int row, int n, int *map, int *cnt) {
	if (row == n) {
		if ((*cnt) < 3) {
			++(*cnt);
			print(row);
			return ;
		} else {
			++(*cnt);
			return ;
		}
	} else {
		for (int i = 0; i < n; i++) {
			if (!used[1][i + row] && !used[2][row - i + n] && !used[0][i]) {
				used[1][i + row] = used[2][row - i + n] = used[0][i] = 1;
				ans[row] = i;
				dfs(row + 1, n, map, cnt);
				used[1][i + row] = used[2][row - i + n] = used[0][i] = 0;
			}
		}
	}
	return ;
}

int main() {
	int n;
	memset(used, 0, sizeof(used));
	scanf("%d", &n);
	int map[1000];
	int cnt = 0;
	dfs(0, n, map, &cnt);
	printf("%d\n", cnt);
	return 0;
}