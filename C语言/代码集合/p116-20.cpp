/*************************************************************************
	> File Name: p116-20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 15时41分19秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;


//int a[10] = {0};

int is_value(int x, int y, int z, int a[]) {
    while(x) {
        if(!a[x % 10]) a[x % 10] = 1;
        else
        return 0;
        x /= 10;
    }
    while(y) {
        if(!a[y % 10]) a[y % 10] = 1;
        else return 0;
        y /= 10;
    }
    while(z) {
        if(!a[z % 10]) a[z % 10] = 1;
        else return 0;
        z /= 10;
    }
    return 1;
}


int main() {
    for(int i = 10; i <= 99; i++) {
        for(int j = 100; j <= 999; j++) {
           int a[10] = {0};
            a[0] = 1;
            if(is_value(i, j, i * j, a)) {
                printf("%d * %d = %d\n", i, j, i * j);
            }
        }
    }
}
