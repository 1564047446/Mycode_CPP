/*************************************************************************
	> File Name: jisuanke26-5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月29日 星期三 23时06分50秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int target[100001] = {0};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= m; i++) {
        for(int j = i; j <= m; j++) {
            target[i * i + j * j] = 1;
        }
    }
    for(int b = 1; b <= 2 * pow(m, 2) / (n - 1); b++) {
        for(int a = 0; a + (n - 1) * b <= pow(m, 2) * 2; a++) {
            if(!target[a]) continue;
            bool flag = 1;
            for(int k = 0; k < n; k++) {
                if(!target[a + k * b]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) printf("%d %d\n", a, b);
        }
    }
}
