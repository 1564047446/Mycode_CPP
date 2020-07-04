/*************************************************************************
	> File Name: 滑动窗口.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月07日 星期二 17时02分40秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include"ss.h"


using namespace std;


int main()
{
   // printf("%d\n", strlen(s));

    long long sum = 1;
    long long zero = 0;
    long long maxn = 0;
    for(long long i = 0; i < strlen(s); i++)
    {
        if(s[i] != '0')
        {
            sum *= s[i] - '0';
        }
        else
        {
            ++zero;
        }
        if(i > 12)
        {
            if(s[i - 13] != '0')
            {
                sum /= s[i - 13] - '0';
            }
            else
            {
                -- zero ;
            }
        }
        if(zero == 0 && maxn < sum)
        {
            maxn = sum;
        }
    }
    printf("%lld\n", maxn);

}
