/*************************************************************************
	> File Name: problem31.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 22时53分11秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int w(int x)
{
    static int a[9] = {0, 1, 2, 5, 10, 20, 50, 100, 200};
    return a[x];
}

int f(int k, int n)
{
    if(n == 1)
    return 1;
    if(n == 0)
    return 1;
    if(n < 0)
    return 0;
    if(k == 1)
    return 1;
    return f(k - 1, n) +f(k, n - w(k)); 
}


int main()
{
    printf("%d\n", f(8, 200));
}
