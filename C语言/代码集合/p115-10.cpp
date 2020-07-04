/*************************************************************************
	> File Name: p115-10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 14时32分19秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int a[10001] = {0};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i++) {
        a[i] = 1;
    }
    for(int i = m; i < n; i = (i += m) % n) {
        if((i) % n == 0) break;
        a[i] = 0;
    }
    int flag = 1;
    for(int i = 0; i < n; i++) {
        if(a[i]) printf("%d\n", i), flag = 0;
        
        continue;
    }
    if(flag) printf("no way \n");
}
