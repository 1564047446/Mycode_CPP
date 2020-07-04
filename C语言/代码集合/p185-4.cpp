/*************************************************************************
	> File Name: p185-4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月13日 星期三 18时58分59秒
 ************************************************************************/

#include <stdio.h>

int a[100] = {0};

int get_value(int n, int d, int i) {
    if (i == 1) return a[1];
    if (i == n) return a[n];
    a[i + 1] = get_value(n, d, i - 1) - 2 * get_value(n, d, i) + 2 * d;
    
}



int main() {

    int N, d, n;
    while (scanf("%d%d%d", &N, &d, &n)) {

        scanf("%d%d", a + 1, a + n);
        get_value(n, d, 1);
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}
