/*************************************************************************
	> File Name: test4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月16日 星期四 14时46分19秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

#define maxn_range 10000
int prime[maxn_range + 5] = {0};


int main()
{
    for(int i = 2; i < maxn_range; i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]] = i;
        }
        for(int j = 1; j <= prime[0]; j++)
        {
            if(i * prime[j] > maxn_range)  break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)
            break;
        }
    }
    int n;
    while(~scanf("%d", &n))
          {
              printf("%d\n", prime[n]);
          }
}

