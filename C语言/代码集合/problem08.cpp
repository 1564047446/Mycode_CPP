/*************************************************************************
	> File Name: problem08.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月06日 星期一 17时49分56秒
 ************************************************************************/


#include<stdio.h>
#include"ss.h"
#include<string.h>

long long p[2000001] = {0};

bool is_prime(long long x)
{
    for(long long  i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
        return 0;
    }
    return 1;
}


int main()
{
    long long sum = 0;
    
    for(long long i = 2; i < 2000001; i++)
    {
        if(is_prime(i))
        sum += i;
    }
    printf("%lld\n", sum);

   // long long p[200]
    // for
   /* for(long long i = 2; i < 2000001; i++)
    {
        if(!p[i])
        {
            p[++p[0]] = i;
            sum += i;
        }
       // p[++p[0]]mZ= mZ;
       // printf("%lld\n", sum);
       // sum += p[p[0]];  
         for(long long j = 1; j <= p[0]; j++)
        {
           if(i * p[j] > 2000001)
            break;
            p[i * p[j]] = 1;
            if(i % p[j] == 0)
            {
                break;
            }
        }
       // sum += p[p[0]];
    }*/
    printf("%lld\n", sum);
}
