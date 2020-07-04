/*************************************************************************
	> File Name: problem13.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 23时10分55秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

char s[55];
int a[60] = {0};


int main()
{
    while(~scanf("%s", s))
    {
        int len = strlen(s);
        for(int i = 0; i < len; i++)
        {
            a[len - i] += s[i] - '0';
        }
        if(a[0] < len)
        a[0] = len;
        for(int i = 1; i <= a[0]; i++ )
        {
            if(a[i] < 10)
            continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            if(i == a[0])
            a[0]++;
        }
    }
    for(int i = a[0]; i >a[0] - 10; i-- )
    {
        printf("%d", a[i]);
    }
}

