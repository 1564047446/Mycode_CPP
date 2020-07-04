/*************************************************************************
	> File Name: problem21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月13日 星期一 16时26分34秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<inttypes.h>
#define maxn_range 10000
int64_t prime[maxn_range + 5] = {0};
int64_t min_NUM[maxn_range + 5] = {0};
int64_t number_SUM[maxn_range + 5] = {0};

using namespace std;


void init_prime()
{
    for(int64_t i = 2; i < maxn_range; i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]] = i;
            number_SUM[i] = 1 + i;
            min_NUM[i] = i * i;
        }
        for(int64_t j = 1; j <= prime[0]; j++)
        {
            if(i * prime[j] > maxn_range)
            break;
            if(i % prime[i])
            {
                prime[i * prime[j]] = 1;
                min_NUM[i * prime[j]] = min_NUM[prime[j]];
                number_SUM[i * prime[j]] = number_SUM[i] * number_SUM[prime[j]];
            }
            else
            {
                prime[i * prime[j]] = 1;
                min_NUM[i * prime[j]] = min_NUM[i] * prime[j];
                number_SUM[i * prime[j]] = number_SUM[i] * (1 - min_NUM[i] * prime[j]) / (1 - min_NUM[i]);
               // min_NUM[i * prime[j]] = min_NUM[i] * prime[j];
                break;
            }
        }
    }
}



int main()
{
   init_prime();
    for(int64_t i = 2; i < maxn_range; i++)
    {
        number_SUM[i] -= i;
    }
    for(int i = 1; i < 50; i++)
    {
        printf("%"PRId64 "    " "%"PRId64"    " "%"PRId64"\n", i, number_SUM[i], min_NUM[i]);
    }
    int n = 1000;
    int64_t sum = 0;
    int i = 2;
    while(n)
    {
        if(number_SUM[number_SUM[i]] = i && number_SUM[i] != i)
        {
            sum += i;
            n--;
        }
        i++;
        
        
        
    }
    printf("%"PRId64"\n", sum);

}
