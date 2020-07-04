/*************************************************************************
	> File Name: contestD.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 19时36分27秒
 ************************************************************************/


#include<stdio.h>
#define maxn 9973
int a[10];

int get_mul(int n)
{
    int sum = 1;
    for(int i = 1; i <= n; i++)
        sum *= i;
    return sum;
}

void get_swap(int x, int n)
{
    int t;
    t = a[x];
    a[x] = a[n];
    a[n] = t;
}

int main()
{
    for(int i = 1; i < 10; i++)
    {
        a[i] = i;
    }
    int k = 1;
    for(int i = 9; i >= 1; i--)
    {
        int num = 10 - i + 1;
        while(k + get_mul(i - 1) <= maxn && num < 10)
        {
            k += get_mul(i - 1);
            get_swap(10 - i, num);
            num++;
        }
    }
    for(int i = 1; i < 10 ; i++)
        printf("%3d", a[i]);
}
