/*************************************************************************
	> File Name: qq.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月09日 星期四 11时39分11秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

long long a[1005];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        int num = 0;
        for(int j = 1; j <= i; j++)
        {
            if(a[j] < a[i])
            num++;
        }
        printf("%d ", num);
    }
}
