/*************************************************************************
	> File Name: test11.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 14时01分56秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;


#define maxn_RANGE 10000
int prime[maxn_RANGE + 5] = {0};

int main()
{
    for(int i = 2; i < maxn_RANGE; i++)
    {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++)
        {
            if(i * prime[j] > maxn_RANGE) break;
            prime[i * prime[j]] = 1;
            if(!i % prime[j])
            break;
        }

    }
    int n;
    while(~scanf("%d", &n))
    {
        printf("%d\n", prime[n]);
    }
}
