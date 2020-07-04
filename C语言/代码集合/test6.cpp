/*************************************************************************
	> File Name: test6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月16日 星期四 15时09分10秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;


#define max_Range 10000
int prime[max_Range + 5] = {0};
int num_Sum[max_Range + 5] = {0};
int min_Multi[max_Range + 5] = {0};

int main()
{
    for(int i = 2; i <= max_Range; i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]] = i;
            num_Sum[i] = 1 + i;
            min_Multi[i] = i * i;
        }
        for(int j = 1; j <= prime[0]; j++)
        {
            if(i * prime[j] > max_Range)   break;
            prime[i * prime[j]] = 1;
            if(i % prime[j])
            {
                num_Sum[i * prime[j]] = num_Sum[i] * num_Sum[prime[j]];
                min_Multi[i * prime[j]] = min_Multi[prime[j]];
            }
            else
            {
                num_Sum[i * prime[j]] = num_Sum[i] * (1 - min_Multi[i] * prime[j]) / (1 - min_Multi[i]);
                min_Multi[i * prime[j]] = min_Multi[i] * prime[j];
            }
        }
    }

    int n;
    while(~scanf("%d", &n))
    {
        printf("%4d%4d\n", min_Multi[n], num_Sum[n]);
    }
}
