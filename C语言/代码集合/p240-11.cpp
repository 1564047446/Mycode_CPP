/*************************************************************************
	> File Name: p240-11.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月20日 星期三 14时36分49秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;


int job[100][100];
int dp[100][100];
int used[100][100];

int dfs(int x, int n) {
    if (x == n) return ;

    for (int i = 0; i < n; i++) {
        dp[x][n] = min(dp[x][n], dfs(x - 1, n) + job[x][n]);
    }
    return dp[x][n];
}



int main() {
    memset(job, 0, sizeof(job));
    memset(dp, 0, sizeof(dp));
    memset(used, 0, sizeof(used));
    for (int i = 0; i < 5) {
        for (int j = 0; j < 5) {
            scanf("%d", &job[i][j]);
        }
    }
    printf("The answer is %d \n", dfs(5, 5));
}
