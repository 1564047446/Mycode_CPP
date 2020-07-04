/*************************************************************************
	> File Name: bignum2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月15日 星期三 14时26分50秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<inttypes.h>
using namespace std;


#define value 102400
int64_t a[value + 5] = {0};

int64_t get_sum( int64_t n)
{
    return 0;
}

int get_mul(int n)
{
   a[0] = 1;
    a[1] = 1;
    for(int64_t i = 1; i <= n; i++)
    {
        for(int64_t k = 1; k <= a[0]; k++)
        {
            a[k] *= i;
        }
        for(int64_t j = 1; j <= a[0]; j++)
        {
            if(a[j] < 10)
            continue;
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
            if(j == a[0])
            ++a[0];
        }
    }
}



int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        get_mul(n);
        cout << a[0] << endl;
        for(int i = a[0]; i >= 1; i--)
        {
            cout << a[i];
        }
        cout << endl;
    }
}

