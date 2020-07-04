/*************************************************************************
	> File Name: p240-5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月20日 星期三 12时59分03秒
 ************************************************************************/

#include <stdio.h>


int dfs(int n, int m) {
    if (n == 1 || m  == 1) return 1;
    if (n < m) return dfs(n, n);
    if (n == m) return 1 + dfs(n, n - 1);
    if (n > m) return dfs(n, m - 1) + dfs(n - m, m);
}


int main() {
    int n;
    scanf("%d", &n);
    printf("total = %d\n", dfs(n, n));
}
