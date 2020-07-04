/*************************************************************************
	> File Name: problem44.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月12日 星期日 15时53分06秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;


long long is_pen(long long x)
{
    return x * (x * 3- 1) / 2; 
}


int is_value(long long n)
{
    long long head = 1, tail = n;
    long long mid = (head + tail) >> 1;
    long long t;
    while(head <= tail)
    {
        if(is_pen(mid) == n)
        return 1;
        if(is_pen(mid) < n)
        head = mid + 1;
        if(is_pen(mid) > n)
        tail = mid - 1;
        mid = (head + tail) >> 1;
    }
    return 0;
}


int main()
{
    long long k = 2;
    long long D = 99999999999;
    int n1;
   /* while(~scanf("%d", &n1))
    {
        printf("%d\n", is_value(n1));
    }*/
    while(is_pen(k) - is_pen(k - 1) < D)
    {
        long long num = k - 1;
       // cout << num << endl;
       // break;
        while(is_pen(k) - is_pen(num) < D)
        {
            if(is_value(is_pen(k) + is_pen(num)) && is_value(is_pen(k) - is_pen(num)))
            D = is_pen(k) - is_pen(num);
            num--;
           // cout << num  << endl;
           // break;
            if(num <= 0)
            break;
        }
       // break;
        k++;
    }
    printf("%lld\n", D);
}
