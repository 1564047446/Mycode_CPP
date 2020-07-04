/*************************************************************************
	> File Name: problem18.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月14日 星期二 17时56分13秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>

#define max_rang 25
int f[max_rang][max_rang] = {0};
int num[max_rang][max_rang] = {0};
using namespace std;

int main()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j <= i; j++)
        scanf("%d", &num[i][j]);
    }
    f[0][0] = num[0][0];
    for(int i = 1; i < 20; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0)
            f[i][j] = f[i - 1][j] + num[i][j];
            else
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + num[i][j];
        }
    }
    int maxn = 0;
    for(int i = 0; i < 20; i++)
    maxn = max(f[19][i], maxn);
    printf("%d\n", maxn);
}

