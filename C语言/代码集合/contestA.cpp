/*************************************************************************
	> File Name: contestA.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 17时53分46秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<inttypes.h>


#define maxn_RANGE 1500000
int prime[maxn_RANGE + 5] = {0};
int64_t num_SUM[maxn_RANGE + 5] = {0}; //因子和
int64_t min_MANY[maxn_RANGE + 5] = {0};//幂数乘积
int64_t num_MANY[maxn_RANGE + 5] = {0};//因子个数
int64_t min_NUM[maxn_RANGE + 5] = {0};//幂数和
int main()
{
    for(int i = 2; i <= maxn_RANGE; i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]] = i;
            min_MANY[i] = i * i;
            num_SUM[i] = 1 + i;
            min_NUM[i] = 1;
            num_MANY[i] = 2;
        }
        for(int j = 1; j <= prime[0]; j++)
        {
            if(i * prime[j] > maxn_RANGE)  break;
            prime[i * prime[j]] = 1;
            if(i % prime[j])
            {
                num_SUM[i * prime[j]] = num_SUM[i] * num_SUM[prime[j]];
                min_MANY[i * prime[j]] = min_MANY[prime[j]];
                min_NUM[i * prime[j]] = min_NUM[prime[j]];
                num_MANY[i * prime[j]] = num_MANY[i] * num_MANY[prime[j]];
            }
            else
            {
                num_SUM[i * prime[j]] = num_SUM[i] * (1 - min_MANY[i] * prime[j]) / (1 - min_MANY[i]);
                min_MANY[i * prime[j]] = min_MANY[i] * prime[j];
                min_NUM[i * prime[j]] = min_NUM[i] + 1;
                num_MANY[i * prime[j]] = num_MANY[i] / (min_NUM[i] + 1) * (min_NUM[i] + 2);
                break;
            }
        }
    }
    int64_t maxn = 0, num = 0;;
    for(int64_t i = 1; i <= 1000000; i++)
    {
       // if(num_SUM[i] > maxn) maxn = num_SUM[i];
        if(num_SUM[i] * num_MANY[i] > maxn)
        {
            maxn = num_SUM[i] * num_MANY[i];
            num = i;
        }
    }
    printf("%"PRId64"\n", num);
}
