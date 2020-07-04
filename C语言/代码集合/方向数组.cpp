/*************************************************************************
	> File Name: 方向数组.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月07日 星期二 19时07分40秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

long long a[30][30] = {0};
long long maxn = 0;
long long sum = 0;
long dir[4][2] = {0, 1, 1, 1, 1, 0, 1, -1};

int main()
{
    for(long i = 5; i < 25; i++)
    {
        for(long j = 5; j < 25; j++)
        scanf("%lld", &a[i][j]);
    }
    

    for(long i = 5; i < 25; i++)
    {
        for(long j = 5; j < 25; j++)
       // long sum = 1;
        {
            for(int k = 0; k < 4; k++)
            {
                 long sum = 1;
                for(int dis = 0; dis < 4; dis++)
                {
                   // long sum = 1;
                    
                    int x = i + dir[k][0] * dis;
                    int y = j + dir[k][1] * dis;
                    sum *= a[x][y];
                }
                if(maxn < sum)
                maxn = sum;
            }
        
            
    
        }
    }
    
    printf("%lld\n", maxn);
}

