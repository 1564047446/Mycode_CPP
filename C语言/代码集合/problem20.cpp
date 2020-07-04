/*************************************************************************
	> File Name: problem20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月13日 星期一 20时02分46秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#define maxn_range 100000
int a[maxn_range] = {0};
using namespace std;

int main()
{
   a[1] = 1;
    a[0] = 1;
    for(int i = 1; i <= 100; i++)
    {
      // a[a[0]] *= i;
        for(int j = 1; j <= a[0]; j++)
        {
            a[j] *= i;
        }
        for(int j = 1; j <= a[0]; j++)
        {
            if(a[j] < 10)
            continue;
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
            if(j == a[0])
            ++a[0];
        }
    }

    int sum = 0;
    for(int i = a[0]; i >= 0; i--)
    printf("%d", a[i]);
    //sum += a[i];
    printf("%d\n", sum);
    cout << a[0] << endl;
}

