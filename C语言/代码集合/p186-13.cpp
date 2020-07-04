/*************************************************************************
	> File Name: p186-13.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月14日 星期四 13时43分40秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int inf = -1000;

int ans[100][100];
int dp[100][100];

void init() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            ans[i][j] = inf;
            dp[i][j] = inf;
        }
    }
}


int main() {
    int n, m;
    init();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &ans[i][j]);
        }
    }

    int l = (m - 5) / 2, r = (m + 5) / 2;
    for (int j = l; j < r; j++)
        dp[n - 1][j] = ans[n - 1][j];
    for (int j = l; j < r; j++) {
        printf("%d ", dp[n - 1][j]);
    }
    printf("\n");
    for (int i = n - 2; i >= 0; i--) {
        if (l - 2 > 0) l -= 2, r += 2;
        else l = 0, r = m;
        for (int j = l; j < r; j++) {
            if (dp[i + 1][j] == inf) {
                if (dp[i + 1][j - 1] == inf) {
                    dp[i][j] = max(dp[i + 1][j + 1], dp[i + 1][j + 2]) + ans[i][j];
                } else {
                    dp[i][j] = max(dp[i + 1][j - 1], dp[i + 1][j - 2]) + ans[i][j];
                }
            } else {
                int maxn = -100000;
                if (dp[i + 1][j - 2] != inf) {
                    maxn = maxn > dp[i + 1][j - 2] ? maxn : dp[i + 1][j - 2];
                }
                if (dp[i + 1][j - 1] != inf) {
                    maxn = maxn > dp[i + 1][j - 1] ? maxn : dp[i + 1][j - 1];
                }
                if (dp[i + 1][j] != inf) {
                    maxn = maxn > dp[i + 1][j] ? maxn : dp[i + 1][j];
                }
                if (dp[i + 1][j + 1] != inf) {
                    maxn = maxn > dp[i + 1][j + 1] ? maxn : dp[i + 1][j + 1];
                }
                if (dp[i + 1][j + 2] != inf) {
                    maxn = maxn > dp[i + 1][j + 2] ? maxn :dp[i + 2][j + 2];
                }
                dp[i][j] = maxn + ans[i][j];
            }
            //printf("%d ", dp[i][j]);
        } 
    }
    int maxn = 0;
    for (int j = l; j < r; j++)
        maxn = maxn > dp[0][j] ? maxn : dp[0][j];
    printf("max = %d\n", maxn);
    
    return 0;
}
