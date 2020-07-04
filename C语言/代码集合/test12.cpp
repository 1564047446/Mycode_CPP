/*************************************************************************
	> File Name: test12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 14时08分53秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

#define max_RANGE 10000
int prime[max_RANGE + 5] = {0};
int num_SUM[max_RANGE + 5] = {0};
int min_MANY[max_RANGE + 5] = {0};


int main()
{
    for(int i = 2; i < max_RANGE; i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]] = i;
            min_MANY[i] = 1;
            num_SUM[i] = 2;
        }
        for(int j = 1; j <= prime[0]; j++)
        {
            if(i * prime[j] > max_RANGE) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j])
            {
                num_SUM[i * prime[j]] = num_SUM[i] * num_SUM[prime[j]];
                min_MANY[i * prime[j]] = min_MANY[prime[j]];
            }
            else
            {
                num_SUM[i * prime[j]] = num_SUM[i] / (min_MANY[i] + 1) * (min_MANY[i] + 2);
                min_MANY[i * prime[j]] = min_MANY[i] + 1;
            }
        }
    }
    int n;
    while(~scanf("%d", &n))
    {
        printf("%4d%4d\n", min_MANY[n], num_SUM[n]);
    }
}
