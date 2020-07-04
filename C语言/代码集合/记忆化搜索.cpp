/*************************************************************************
	> File Name: 记忆化搜索.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月09日 星期四 13时57分57秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>

#define maxn_x  1000000
#define maxn_range  5000000
long long keep[maxn_range + 5] = {0};
using namespace std;


int getlength(long long x)
{
    if(x == 1)
    return 1;
    if(x <= maxn_x && keep[x] != 0)
    return keep[x];
    long long len;
    switch(x % 2)
    {
        case 0:
        len = getlength(x / 2) + 1;
        break;
        case 1:
        len = getlength(x * 3 + 1) + 1;
        break;
    }
    if(x <= maxn_x)
    keep[x] = len;
    return len;
}



int main()
{
    long long maxn = 0;
    long long num = 0;
    for(long long i = 1; i <= maxn_x; i++)
    {
        if(getlength(i) > maxn)
        {
            maxn = getlength(i);
            num = i;
        }
    }
    printf("%lld\n", num);
    for(int i = 0; i < 50; i++)
    cout << keep[i] << endl;
}
