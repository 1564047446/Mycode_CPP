/*************************************************************************
	> File Name: test1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月15日 星期三 16时13分27秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;


#define max_Range 150000
int prime[max_Range + 5] = {0};

int main()
{
    for(int i = 2; i < max_Range; i++)
    {
        if(!prime[i])
            prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++)
        {
            if(i * prime[j] > max_Range)
            break;
            prime[i * prime[j]] = 1;
            if(!i % prime[j])
            break;
        }
    }
    int n;
    while(~scanf("%d", &n))
    {
        printf("%d\n", prime[n]);
    }
}
