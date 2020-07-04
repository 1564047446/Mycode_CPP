#include<stdio.h>
#include<math.h>

int main()
{
    int maxn = 200000;
    long long p[maxn] = {0};
    for(long long i = 2; i <= maxn; i++)
    {
        if(!p[i])
        {
            p[++ p[0]] = i;        
            for(long long j = i * i; j <= maxn; j += i)
            {
               if(!p[j])
                {
                    p[j] = i;
                }
              //  p[j] = i;
            }


        
    }}
    long long n;
    while(scanf("%lld", &n) != EOF)
    {
        printf("%lld\n", p[n]);
    }

}
