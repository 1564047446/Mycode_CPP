/*************************************************************************
	> File Name: q.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 15时48分21秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>

#define max_range 10000
long long pre[max_range + 5] = {0};
using namespace std;

int is_value(int x, int y)
{
   bool flag1 = 0, flag2 = 0;
    for(int i = 1; i < max_range; i++)
    {
        if(x - y == pre[i])
        {
            flag2 = 1;
        }
        if(x + y == pre[i])
        {
            flag1 = 1;
        }
    }
    if(flag1 && flag2)
    return 1;
}




int main()
{
    for(int i = 1; i <= 20; i++)
    {
        if(i % 2 == 0)
        continue;
       // cout << i  << endl;
    }
    pre[0] = 0;
    long long min_ans = 101111111111;
    cout << abs(min_ans);
    for(long long i = 1; i <  max_range; i++)
    {
        pre[++pre[0]] = i * (3 * i - 1) / 2;
    }
    int a[4] = {0};
    for(int i = 1; i < max_range; i++)
    {
        for(int j = i; j < max_range; j++)
        {
            if(is_value(pre[i], pre[j]))
            {
                if(min_ans > abs( pre[i] - pre[j]))
                min_ans = abs(pre[i] - pre[j]);
            }
        }
    }

    printf("%lld\n", min_ans);
}
