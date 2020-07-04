/*************************************************************************
	> File Name: p187-16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月14日 星期四 15时37分03秒
 ************************************************************************/

#include <stdio.h>

int a[1000];

int get_coll(int n, int ok) {
    int left = 1, right = n;
    while (left < right) {
        int mid = (left + right) >> 1;
        int sum1 = 0, sum2 = 0, num = 0;
        for (int i = left; i < mid; i++) {
            sum1 += a[i];
            num++;
        }
        if (num * ok != sum1) {
            right = mid;
        }
        num = 0;
        for (int i = mid; i <= right; i++) {
            sum2 += a[i];
            num++;
        }
        if (num * ok != sum2) {
            left = mid;
        }
        if (right - left == 1) break;
    }
    return a[left] > a[right] ? a[right] :a[left];
}


int main() {
    int n;
    int ok;     //正确的硬币重量
    //printf("lslslsls\n");
    scanf("%d%d", &n, &ok);
    for (int i = 1; i <= n; i++) {    //假设我不知道这个硬币在哪
        scanf("%d", a + i);
    }
   /* for (int i = 1; i <= n; i++) {
        
        printf("%d", a[i]);
    }*/
    printf("%d\n", get_coll(n, ok));
    return 0;
}
