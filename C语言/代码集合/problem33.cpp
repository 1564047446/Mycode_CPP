/*************************************************************************
	> File Name: problem33.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月12日 星期日 09时50分20秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
    return a;
    return gcd(b, a % b);
}

int is_same(int a, int b)
{
    if(a % 10 == b / 10 && a / 10 < b % 10)
    return 1;
    else
    return 0;
}




int is_value(int a, int b)
{
   int c = a / 10;
    int d = b % 10;
    if(a * d == b * c && is_same(a, b))
    return 1;
    else
    return 0;
}



int main()
{
  
    long long sum1 = 1, sum2 = 1, num = 0;
    int k1 = 1, k2 = 1;
    for(int i = 10; i < 100; i++)
    {
        if(i % 10 == 0)
        continue;
        for(int j = i + 1; j < 100; j++)
        {
            if(is_value(i, j))
            {
                sum1 *= i;
                sum2 *= j;
              //  printf("%d  %d\n", sum1, sum2);
              // k1 *= sum1 /  gcd(sum1, sum2);
               // k2 *=sum2 /  gcd(sum1, sum2);
               // printf("%d  %d\n", sum1, sum2);

                num++;
            }
        }
    }

    printf("%lld    %d\n", sum2 / gcd(sum1, sum2));
  //  printf("%d", gcd(6, 4));
    
}

