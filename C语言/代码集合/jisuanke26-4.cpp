/*************************************************************************
	> File Name: jisuanke26-4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月29日 星期三 22时13分00秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int target[1000001] = {0};

int main() {
    int n, m;
    int flag = 1;
    scanf("%d%d", &n, &m);
    int num = 0;
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= m; j++) 
            target[i * i + j * j] = 1;
    }
    for(int b = 1; b <= m * m * 2 / (n - 1); b++) {
        for(int a = 0; a + (n - 1) * b <= 2 * m * m; a++) {
            int k;
            if(!target[a]) continue;
            for(k = 0; k < n; k++) {
                if(!target[a + k * b]) break;
            }
            if(k == n - 1) printf("%d %d\n", a, b), flag = 0;
        }
    }
    if(flag) printf("NONE\n");
}
