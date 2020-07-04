/*************************************************************************
	> File Name: p125.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 11时00分34秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int f(int a, int b) {
    if(b == 0) return a;
   // a += (f(a, b - 1) + 1) * 2;
    a = (a + 1) * 2;
     f(a, b - 1);
}


int g(int a, int b) {
    if(b == 0) return a;
    a += (f(a, b - 1) + 1) * 2;
}


int main() {
    int a = 1;
    for(int i = 10; i >= 1; i--) {
        a = (a + 1) * 2;
    }
    int b = 1, i = 10;
    printf("%d\n", a);
    //
    //printf("%d\n", f(b, i));
    printf("%d\n", g(b, i));
}
