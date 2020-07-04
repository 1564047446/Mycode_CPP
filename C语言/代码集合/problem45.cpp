/*************************************************************************
	> File Name: problem45.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月12日 星期日 18时09分02秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;


int tri(long long x)
{
    return x * (x + 1) / 2;
}
int pen(long long n)
{
    return n * (3 * n - 1) / 2;
}
long long hex(long long z)
{
    return z * (2 * z - 1);
}

long long is_1(long long a)
{
    long long head = 1, tail = a, mid = (head + tail) >> 1;
    while(head <= tail)
    {
        if(tri(mid) == a)
        return 1;
        if(tri(mid) < a)
        head = mid + 1;
        if(tri(mid) > a)
        tail = mid - 1;
        mid = (head + tail) >> 1;
    }
    return 0;
}

long long  is_2(long long n)
{
    long long head = 1, tail = n, mid = (head + tail) >> 1;
    while(tail >= head)
    {
        if(pen(mid) == n)
        return 1;
        if(pen(mid) < n)
        head = mid + 1;
        if(pen(mid) > n)
        tail = mid - 1;
        mid = (head + tail) >> 1;
    }
    return 0;
}
int is_3(long long m)
{
    long long head = 1, tail = m, mid = (head + tail) >> 1;
    while(head <= tail)
    {
        if(hex(mid) == m)
        return 1;
        if(hex(mid) < m)
        head = mid + 1;
        if(hex(mid) > m)
        tail = mid - 1;
    }
    return 0;
}
    








int main()
{
    long long k = 1;
    int num = 0;
    long long a = 0;
    while(1)
    {
        if(is_1(hex(k)) && is_2(hex(k)))
        {
            num++;
            a = hex(k);
            printf("%lld\n", a);
        }
       // num++;
        k++;
      //  cout << num << endl;
        if(num == 2)
        break;
    }
    printf("%lld\n", a);

}
