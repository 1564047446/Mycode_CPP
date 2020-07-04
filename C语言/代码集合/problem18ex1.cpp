/*************************************************************************
	> File Name: problem18ex1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月14日 星期二 18时39分23秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>

int f[20][20];
int num[20][20];
using namespace std;


int main()
{
    for(int i = 0; i < 20; i++)
    for(int j = 0; j <= i; j++)
    scanf("%d", &num[i][j]);

    for(int i = 0; i < 20; i++)
    f[19][i] = num[19][i];

    for(int i = 18; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + num[i][j];
        }
    }
    printf("%d\n", f[0][0]);
    
    
}
