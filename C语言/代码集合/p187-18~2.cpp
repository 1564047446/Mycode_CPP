/*************************************************************************
	> File Name: p187-18~2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月15日 星期五 12时09分01秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

#define inf 0x3f3f3f3f

int dp[300][300];
char s[300];


int get_num(int x, int y) {
    int sum = 0;
    for (int i = x; i < y; i++) {
        sum = sum * 10 + s[i] - '0';
    }
    return sum;
}


int main() {
    scanf("%s", s);
    int n;
    int len = strlen(s);
    scanf("%d", &n);
    for (int i = 1; i <= len; i++) {
        dp[i][0] = get_num(0, i);
    }
    printf("%d\n", dp[len][0]);
    for (int i = len; i >= n; i--) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = inf;
            for (int k = len - 1; k >= n; k--)
                dp[i][j] = min(dp[i][j], dp[k - 1][j] + get_num(k, i));
        }
    }
    printf("%d\n", inf);
    printf("%d\n", dp[len][n]);
    return 0;
}
