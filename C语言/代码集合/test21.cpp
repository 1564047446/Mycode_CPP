/*************************************************************************
	> File Name: test21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月25日 星期六 15时35分42秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int a[1001] = {0};

int main() {
    int n = 7, num = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            a[num ++] = pow(i, 2) + pow(j, 2);
        }
    }
    sort(a, a + num);
    for(int i = 0; i < num; i++) printf("%d\n", a[i]);
}
