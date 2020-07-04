/*************************************************************************
	> File Name: lianxi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月10日 星期五 10时34分28秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>

#define maxn  4000005
long long sum = 2;

using namespace std;

long long f[3] = {0, 1, 2};

int main()
{
    for(int i = 0; ; i++)
    {
        f[i % 3] = f[(i + 1) % 3] + f[(i + 2) % 3];
        if(f[i % 3] > maxn)
        break;
        if(f[i % 3] % 2 == 0)
        sum += f[i % 3];
    }
    printf("%lld\n", sum);
}
