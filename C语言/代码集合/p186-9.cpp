/*************************************************************************
	> File Name: p186-9.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月13日 星期三 19时47分33秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;


int ans[1001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", ans + i);
    sort(ans, ans + n);
    printf("max1 = %d, max2 = %d,min1 = %d, min2 = %d\n ", ans[n - 1], ans[n - 2], a[0], a[1]);
}
