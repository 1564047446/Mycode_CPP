/*************************************************************************
	> File Name: p114-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 14时23分21秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

#define maxn_RANGE 10000
int a[maxn_RANGE + 5] = {0};
int sum[maxn_RANGE + 5] = {0};

int main() {
    sum[0] = 1;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        a[i] = 2;
        for(int j = 1; j <= i; j++) {
            sum[j] += a[j];
        }
        if(sum[0] < i) sum[0] = i;
        for(int j = 1; j <= sum[0]; j++) {
            if(sum[j] < 10) continue;
            sum[j + 1] += sum[j] / 10;
            sum[j] %= 10;
            if(j == sum[0]) sum[0] ++;
        }
    }
    for(int i = sum[0]; i >= 1; i--) {
        printf("%d", sum[i]);
    }
    printf("\n");
}
