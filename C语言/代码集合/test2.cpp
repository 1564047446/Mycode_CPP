/*************************************************************************
	> File Name: test2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月15日 星期三 18时30分59秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>


#define max_Range 10000
using namespace std;

int prime[max_Range + 5] = {0};
int num_Many[max_Range] = {0};
int min_Num[max_Range] = {0};

int main()
{
    for(int i = 2; i <= max_Range; i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]] = i;
            min_Num[i] = 1;
            num_Many[i] = 2;
        }
        for(int j = 1; j <= prime[0]; j++)
        {
            if(i * prime[j] > max_Range)
                break;
            prime[i * prime[j]] = 1;
            if(i % prime[j])
            {
                min_Num[i * prime[j]] = min_Num[prime[j]];
                num_Many[i * prime[j]] = num_Many[i] * num_Many[prime[j]];
            }
            else
            {
                num_Many[i * prime[j]] = num_Many[i] / (min_Num[i] + 1) * (min_Num[i] + 2);
                min_Num[i * prime[j]] = min_Num[i] + 1;
            }
        }
    }

    int n;
    while(scanf("%d", &n) != EOF)
    {
        printf("%5d%5d%5d\n", n, num_Many[n], min_Num[n]);
    }
}
