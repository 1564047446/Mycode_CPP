/*************************************************************************
	> File Name: bignum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月14日 星期二 20时20分17秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[100] = {0};
int b[100] = {0};
char s[100], s2[100];
int sum[10001] = {0};
int main()
{
    while(~scanf("%s%s", s, s2))
    {
        int t = strlen(s);
        int t2 = strlen(s2);
        for(int i = 0; i < t; i++)
        a[t - i] += s[i] - '0';
        for(int i = 0; i < t2; i++)
        b[t2 - i] += s2[i] - '0';
        int n = 1;
        int num = 0;
        int len = 0;
        for(int i = 1; i <= t; i++)
        {
            for(int j = 1; j <= t2; j++)
            {
                sum[++num] += a[i] * b[j];
            }
            for(int k = 1; k <= num; k++)
            {
                if(sum[k] < 10)
                continue;
                sum[k + 1] += sum[k] / 10;
                sum[k] %= 10;
                if(k == num)
                num++;
                len += num - len;

            }
            num = n;
            n++;
        }
        cout << len << endl;
        for(int i = len; i > 0; i--)
        printf("%d", sum[i]);
        cout << endl;
    }
}
