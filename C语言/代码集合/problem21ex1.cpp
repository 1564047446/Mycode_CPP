/*************************************************************************
	> File Name: problem21ex1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月14日 星期二 16时00分33秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<inttypes.h>

#define maxn_range 100000
int64_t prime[maxn_range + 5] = {0};
int64_t num_SUM[maxn_range + 5] = {0};
int64_t min_NUM[maxn_range + 5] = {0};


void init_prime()
{
    for(int64_t i = 2; i < maxn_range; i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]] = i;
            min_NUM[i] = i * i;
            num_SUM[i] = 1 + i;
        }
        for(int64_t j = 1; j <= prime[0]; j++)
        {
            if(i * prime[j] > maxn_range)
            break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)
            {
                min_NUM[i * prime[j]] = min_NUM[i] * prime[j];
                num_SUM[i * prime[j]] = num_SUM[i] * (1 - min_NUM[i] * prime[j]) / (1 - min_NUM[i]);
                break;
            }
            else
            {
                num_SUM[i * prime[j]] = num_SUM[i] * num_SUM[prime[j]];
                min_NUM[i * prime[j]] = min_NUM[prime[j]];
            }
        }
    }
}    


int main()
{
    int64_t n;
    init_prime();
    for(int64_t i = 2; i < 10001; i++)
    num_SUM[i] -= i;
  /*  while(~scanf("%"PRId64, &n))
    {
        printf("%"PRId64 "          ""%"PRId64"\n", num_SUM[n], min_NUM[n]);
    }*/


    int64_t sum = 0;
    for(int64_t i = 2; i < 10000; i++)
    {
       int64_t a = num_SUM[i];
        int64_t b = i;
        if(b == num_SUM[a] && i != num_SUM[i])
        sum += i;
    }
    printf("%"PRId64"\n", sum);
}
