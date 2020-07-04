/*************************************************************************
	> File Name: problem16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月15日 星期三 15时50分28秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>

#define maxn_range 100000
int a[maxn_range] = {0};
using namespace std;

int get_SUM()
{
    int sum = 0;
    for(int i = a[0]; i >= 1; i--)
    cout << a[i] << endl;
    for(int i = 1; i <= a[0]; i++)
    {
        while(a[i])
        {
           
            sum += a[i] % 10;
            a[i] /= 10;
        }
       // cout << sum << endl;
    }
   // cout << sum << endl;
}



int main()
{
    a[0] = a[1] = 1;
    for(int i = 1; i <= 1000; i++)
    {
        for(int j = 1; j <= a[0]; j++)
        {
            a[j] *= 2;
        }
        for(int j = 1; j <= a[0]; j++)
        {
            if(a[j] < 100)
            continue;
            a[j + 1] += a[j] / 100;
            a[j] %= 100;
            if(j == a[0])
            ++a[0];
        }
    }
    get_SUM();
}
