/*************************************************************************
	> File Name: dfs1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月10日 星期五 23时19分27秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>

int a[10];
int used[10];
using namespace std;


void dfs(int x)
{
    if(x > 4)
    {
        for(int i = 1; i <= 4; i++)
        {
            printf("%d", a[i]);
        }
        cout << endl;
    }
    else
    {
        for(int i = 1; i <= 4; i++)
        {
            if(!used[i])
            {
                used[i] = 1;
                a[x] = i;
                dfs(x + 1);
                used[i] = 0;
            }
        }
    }
}

int main()
{
    dfs(1);
}
