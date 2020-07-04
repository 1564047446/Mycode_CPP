/*************************************************************************
	> File Name: 滑动窗口2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月07日 星期二 17时31分16秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<inttypes.h>
#include"ss.h"


using namespace std;


int main()
{
    int64_t maxn = 0;
    int64_t sum = 1;
    int64_t k;
    int64_t num = -1;
    int flag = 0;
    for(int64_t i = 0; i < strlen(s); i++)
    {
        if(s[i] == '0')
        {
            i += 12;
            if(i > strlen(s))
            break;
            sum = 1;
            num = 0;
            flag = 0;
            continue;
        }
        else
        {
            sum *= s[i] - '0';
            ++num;
        }
       /* if(num >= 13)
        {
            sum /= s[i - num] - '0';
            ++num;
        }
        if(maxn < sum)
        {
            maxn = sum;
        }*/
        if(flag == 0 && num >= 13)
        {
            sum /= s[i - num] - '0';
            ++num;
        }
        if(flag == 1 && num >= 14)
        {
            sum /= s[i - num] - '0';
        }
        if(maxn < sum)
        {
            maxn = sum;
        }


    }
    printf("%"PRId64"\n", maxn);
}
