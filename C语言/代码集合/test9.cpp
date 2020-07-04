/*************************************************************************
	> File Name: test9.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月16日 星期四 20时22分02秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

#define maxn 1000000
int a[10];

int get_multi(int n)
{
    int sum = 1;
    for(int i = 1; i <= n; i++)
        sum *= i;
    return sum;
}


void get_swap(int n, int num)
{
    int t;
    t = a[n];
    a[n] = a[num];
    a[num] = t;
}

int main()
{
    int k = 1;
    int num = -1;
    for(int i = 0; i < 10; i++)
        a[i] = i;
    for(int i = 9; i >= 0; i--)
    {
        int m = 9 - i + 1;
        while(k + get_multi(i) <= maxn && m < 10)
        {
            get_swap(9 - i, m);
            k += get_multi(i);
            m++;
        }
       // num = 9 - i;
    }
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
}
