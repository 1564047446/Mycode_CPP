/*************************************************************************
	> File Name: test14.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 14时37分08秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

char s1[1000], s2[1000];
int a[1000] = {0}
int b[1000] = {0}
int sum[1000] = {0};

int main()
{
    scanf("%s%s", s1, s2);
    
    int len1 = strlen(s1), len2 = strlen(s2);
    for(int i = 0; i < len1; i++)
        a[len1 - i] += s1[i] - '0';
    for(int i = 0; i < len2; i++)
        b[len2 - i] += s2[i] - '0';
    int k = 1, len = 0;
    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            sum[++[sum[0]] += a[i] * b[j];
        }
        for(int j = 1; j <= sum[0]; j++)
        {
            if(sum[j] < 10)
            continue;
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
            if(j == sum[0]) ++sum[0];
        }
        len = sum[0];
        sum[0] = k;
        k++;
    }
    for(int i = len; i >= 1; i--)
        cout << sum[i];
    cout << endl;
}
