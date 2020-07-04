#include<stdio.h>



int main()
{
    long long maxn = 150000;
    long long p[maxn + 5] = {0};
    for(long long i = 2; i <= maxn; i++)
    {
        if(!p[i])
        {
            p[++ p[0] ] = i;
        }
        for(long long j = 1; j <= p[0]; j++)
        {
            if(i * p[j] > maxn)
            break;
            p[i * p[j]] = 1;
            if(i % p[j] == 0)
            break;
        }
    }
    long long n;
    while(~scanf("%lld", &n))
    {
        printf("%lld\n", p[n]);
    }
}
