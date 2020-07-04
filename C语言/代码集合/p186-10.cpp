/*************************************************************************
	> File Name: p186-10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月13日 星期三 19时58分45秒
 ************************************************************************/

#include <stdio.h>

int a[100];
int sum = 0;

int get_value(int a[], int l, int r) {
    //int sum = 0;
    if (l == r) return sum;
    else {
        sum += a[l];
        return get_value(a, l + 1, r);
    }

}


int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    printf("%d\n", get_value(a, 0, n));

}
