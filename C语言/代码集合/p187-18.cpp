/*************************************************************************
	> File Name: p187-18.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月14日 星期四 18时22分48秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define inf 0x3f3f3f3f

using namespace std;

char string1[1001];
int dp[1001][1001];
int num[1001][1001];

int get_num(int x, int y) {
    if (num[x][y] != -1) {
        return num[x][y];
    }
    int sum = 0;
    for (int i = x; i < y; i++) {
        sum = sum * 10 + string1[i] - '0';
    }
    num[x][y] = sum;
    return sum;
}


int get_dp(int len, int n) {
    if (dp[len][n] != -1) return dp[len][n];

    if (n == 0) {
        dp[len][0] = get_num(0, len);
        return dp[len][0];
    }
    dp[len][n] = inf;
    for (int k = len - 1; k >= n; k--) {
        dp[len][n] = min(dp[len][n], get_dp(k, n - 1) + get_num(k, len));
    }
    return dp[len][n];
}



int main() {
    
    memset(dp, -1, sizeof(dp));
    memset(num, -1, sizeof(num));
    scanf("%s", string1);
    int len = strlen(string1);
    int n;
    scanf("%d", &n);
    printf("%d\n", get_dp(len, n));
    
    return 0;
}
