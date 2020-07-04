/*************************************************************************
	> File Name: test7.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月16日 星期四 15时51分56秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

#define max_RANGE 10000
char s1[max_RANGE], s2[max_RANGE];
int a[max_RANGE] = {0}, b[max_RANGE] = {0};
int sum[max_RANGE * 10] = {0};


int main()
{
    scanf("%s%s", s1, s2);
    for(int i = 0; i < strlen(s1); i++)
        a[strlen(s1) - i] += s1[i] - '0';
    for(int i = 0; i < strlen(s2); i++)
        b[strlen(s2) - i] += s2[i] - '0';
    int num = 0, len = 1, k = 0;
    for(int i = 1; i <= strlen(s1); i++)
    {
        for(int j = 1; j <= strlen(s2); j++)
        {
            sum[++num] += a[i] * b[j];
        }
        for(int j = 1; j <= num; j++)
        {
            if(sum[j] < 10)  continue;
            sum[j + 1] += sum[j] / 10;
            sum[j] %= 10;
            if(j == num)
            num++;
        }
        k = num;
        num = len;
        len++;
    }
    for(int i = k; i >= 1; i--)
        printf("%d", sum[i]);
    printf("\n");

    
}
