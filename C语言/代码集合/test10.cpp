/*************************************************************************
	> File Name: test10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月16日 星期四 21时10分27秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;


#define maxn 9973
int a[10];

int main()
{
    for(int i = 0; i < 10; i++)
        a[i] = i;
    int mul = 1, times = 1;
    int n = maxn - 1;
    while(mul <= n && times < 10)
    {
        mul *= times;
        times ++;
    }
    //times --;
    for(int i = 0; i < 10 && n; i++)
    {
        --times;
        int j = i + 1, t;
        while(n >= mul && j < 10)
        {
            t = a[i], a[i] = a[j], a[j] = t;
            ++j;
            n -= mul;
        }
        mul /= times;
        
    }
    for(int i = 0; i < 10; i++)
        printf("%2d", a[i]);
    printf("\n");
}
