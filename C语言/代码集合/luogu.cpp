/*************************************************************************
	> File Name: luogu.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月09日 星期四 11时09分47秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;


int main()
{
    int x;
    long n;
    while(~scanf("%d%ld", &x, &n))
    {
        long long sum = 0;
        for(long i = n; i > 0; i--)
        {
          // printf("%d\n", x);
        
           if(x % 6 == 0 || x % 7 == 0)
            {
                x++;
                x = x % 7;
                continue;
            }
            else
            {
                sum += 250;
                x++;
                x = x % 7;
            }
           // printf("%d\n", x);
            
        }
        printf("%lld\n", sum);
    }
}

