/*************************************************************************
	> File Name: problem37.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月12日 星期日 11时53分02秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxn_range 1000000
long long prime[maxn_range] = {0};

int is_prime(long long x)
{
   if(x == 1)
    return 0;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
        return 0;
    }
    return 1;
}

int is_value(long long n)
{
    int m = pow(10, floor(log10(n)));
    int m1 = m;
    while(m )
    {
        if(!is_prime(n / m))
        return 0;
        m /= 10;
    }
    while(m1)
    {
        if(!is_prime(n % m1))
        return 0;
        m1 /= 10;
    }
    return 1;
}


int main()
{
   long long sum = 0, num = 0;
    for(int i = 2; i < maxn_range; i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]] = i;
            if(is_value(i) && i > 10 && num <= 11)
            {
                sum += i;
                num++;
                cout << i << endl;
            }
        }
        for(int j = 1; j <= prime[0]; j++)
        {
            if(i * prime[j] > maxn_range)
            break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)
            break;
        }
    }
   int k;
   // scanf("%d", &k);
   // printf("%d\n", is_value(k));
    printf("%lld    %lld\n", sum, num);
}
