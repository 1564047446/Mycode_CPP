/*************************************************************************
	> File Name: test3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月15日 星期三 19时09分20秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
#define max_range 10000
using namespace std;

int prime[max_range + 5] = {0};
int num_SUM[max_range + 5] = {0};
int min_SUM[max_range + 5] = {0};

int main()
{
    for(int i = 2; i <= max_range; i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]] = i;
            min_SUM[i] = i * i;
            num_SUM[i] = 1 + i;
        }
        for(int j = 1; j <= prime[0]; j++)
        {
            if(i * prime[j] > max_range)
            break;
            prime[i * prime[j]] = 1;
            if(i % prime[j])
            {
                min_SUM[i * prime[j]] = min_SUM[prime[j]];
                num_SUM[i * prime[j]] = num_SUM[i] * num_SUM[prime[j]];
            }
            else
            {
                min_SUM[i * prime[j]] = min_SUM[i] * prime[j];
                num_SUM[i * prime[j]] = num_SUM[i] * (1 - min_SUM[i] * prime[j]) / (1 - min_SUM[i]);
            }
        }
    }


    int n;
    while(~scanf("%d", &n))
    {
        printf("%4d%4d\n", min_SUM[n], num_SUM[n]);
    }
}

