/*************************************************************************
	> File Name: job3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月28日 星期二 18时52分53秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int a[105][105][1001] = {0};
int b[105][105];

int main() {
    a[0][0][1] = 1;
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) 
            b[i][j] = 1;
    }
    for(int i = 1; i <= 100; i++) {
        for(int j = 0; j <= i; j++) {
            if (j == 0) a[i][j][b[i][j]] = 1;
            else if (j == i) a[i][j][b[i][j]] = 1;
            else {
                int maxn = max(b[i - 1][j - 1], b[i - 1][j]);
                for(int k = 1; k <= maxn; k++) {
                    a[i][j][k] = a[i - 1][j - 1][k] + a[i - 1][j][k];
                }
                b[i][j] = maxn;
                for(int k = 1; k <= b[i][j]; k++) {
                    if(a[i][j][k] < 10) continue;
                    a[i][j][k + 1] += a[i][j][k] / 10;
                    a[i][j][k] /= 10;
                    if(k == b[i][j]) b[i][j]++;
                }
            }
            //cout << b[i][j] << endl;
        }
    }
    int n;
    while(cin >> n) {
        for(int j = 0; j <= n; j++) {
            for(int k = b[n][j]; k >= 1; k--) {
                printf("%d", a[n][j][k]);
            }
            if(j != n) printf(" ");
            else printf("\n");
        }
        //printf("\n");
    }
    return 0;
}

