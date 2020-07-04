/*************************************************************************
	> File Name: test5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月16日 星期四 14时58分19秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

#define max_Range 10000
int prime[max_Range + 5] = {0};
int num_Many[max_Range + 5] = {0};
int min_Num[max_Range + 5] = {0};

int main()
{
    for(int i = 2; i < max_Range; i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]] = i;
            num_Many[i] = 2;
            min_Num[i] = 1;
        }
        for(int j = 1; j <= prime[0]; j++)
        {
            if(i * prime[j] > max_Range)  break;
            prime[i * prime[j]] = 1;
            if(i % prime[j])
            {
                num_Many[i * prime[j]] = num_Many[i] * num_Many[prime[j]];
                min_Num[i * prime[j]] = min_Num[prime[j]];
            }
            else
            {
                min_Num[i * prime[j]] = min_Num[i] + 1;
                num_Many[i * prime[j]] = num_Many[i] / (min_Num[i] + 1) * (min_Num[i] + 2);
                break;
            }
        }
    }

    int n;
    while(~scanf("%d", &n))
    {
        printf("%4d%4d\n", min_Num[n], num_Many[n]);
    }
}
