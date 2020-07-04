/*************************************************************************
	> File Name: problem38.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月14日 星期二 19时22分19秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<inttypes.h>
#include<math.h>
#include<algorithm>
using namespace std;
int64_t ans = 0;

int64_t isvalue(int64_t n)
{
    int64_t i = 1;
    int64_t a[10] = {0};
    int num = 0;
    while(num < 9)
    {
        int64_t m = i * n;
        int64_t k = floor(log10(m)) + 1;

        while(m)
        {
            if(m % 10 == 0)
            return 0;
            if(a[m % 10])
            return 0;
            a[m % 10] = (++num);
            m /= 10;
        }
        ans *= pow(10, k);
        ans += i * n;
        i++;
    }
    return ans;
}

int main()
{
    int64_t maxn = 0;
   // int64_t ans = 0;
    for(int64_t i = 2; i < 10000; i++)
    {
        if(isvalue(i))
        {
            ans = 0;
            maxn = max(maxn, isvalue(i));
            printf("%"PRId64"   ""%"PRId64"\n", maxn, ans);
        }
    }
    printf("%"PRId64"\n", maxn);
}
