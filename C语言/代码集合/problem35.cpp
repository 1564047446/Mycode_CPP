/*************************************************************************
	> File Name: problem35.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月12日 星期日 11时15分05秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxn_range 1000000
long long p[maxn_range] = {0};

bool is_prime(long long x)
{
    for(long long i = 2;i * i <= x; i++)
    {
        if(x % i == 0)
        return 0;
    }
    return 1;
}


int is_value(long long y)
{
    int m = floor(log10(y)) + 1;
    int n = 1;
    for(int i = 1; i < m; i++)
    n *= 10;
    while(m --)
    {
        y = y % n * 10 + y / n;
        if(!is_prime(y))
        return 0;
    }
    return 1;
}



int main()
{
   int num = 0;
    for(long long i = 2; i < maxn_range; i++)
    {
        if(!p[i])
        {
            p[++p[0]] = i;
            if(is_value(i))
            num++;
        }
        for(long long j = 1; j <= p[0]; j++)
        {
            if(i * p[j] > maxn_range)
            break;
            p[i * p[j]] = 1;
            if(i % p[j] == 0)
            break;
        }
    }
    printf("%d\n", num);
    int k;
    while(~scanf("%d", &k))
    printf("%d\n", is_value(k));
}

