/*************************************************************************
	> File Name: test17.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月19日 星期日 18时51分35秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int get_mul(int n)
{
    if(n == 1)
    return 1;
    return get_mul(n - 1) * n;
}


int main()
{
    int n = 10;
    printf("%d\n", get_mul(n));
}
