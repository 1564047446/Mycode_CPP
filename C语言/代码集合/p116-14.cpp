/*************************************************************************
	> File Name: p116-14.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 15时01分28秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>

using namespace std;

int is_double(int x) {
    int a[10] = {0};
    while(x) {
        ++ a[x % 10];
        //x /= 10;
        if(a[x % 10] == 2)
        return 1;
        x /= 10;
    }
    return 0;
}

int is_value(int x) {
    for(int i =10; i * i<= x; i++) {
        if(i * i == x)
        return 1;
    }
    return 0;
}

int main() {
    for(int i = 100; i <= 999; i++) {
        if(is_double(i) && is_value(i))
        printf("%d\n", i);
    }
}
