/*************************************************************************
	> File Name: ccf1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月20日 星期一 11时33分21秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int key_Start[1000 + 5] = {0};
int key_End[1000 + 5] = {0};
int key_Sort[1000 + 5] = {0};
int key_num[1000 + 5] = {0};

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        key_Sort[i] = i;
    int w, s, c, maxn = 0, num = 1, minn = -1;
    for(int i = 1; i <= k; i++)
    {
        scanf("%d%d%d", &w, &s, &c);
        key_Start[num] = s, key_End[num] = s + c, key_num[num] = w;
        num++;
        if(s + c > maxn) maxn = s + c;
        if(s < minn) minn = s;
            
    }
    sort(key_Start + 1, key_Start + num - 1);
    sort(key_End + 1, key_End + num - 1);
    int num_Start = 1, num_End = 1;
    for(int i = minn; i <= maxn; i++)
    {
        while(i == key_End[num_End])
        {
            for(int j = 1; j < num; j++)
            {
                if(key_Sort[j] == 0)
                {
                    key_Sort[j] = key_num[j];
                    num_End ++;
                    break;
                }
            }
        }
        while(i == key_Start[num_Start])
        {
            for(int j = 1; j < num; j++)
            {
                if(key_Sort[j] == )
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(i == n)
            printf("%d\n", key_Sort[i]);
        else
            printf("%d ", key_Sort[i]);
    }
       /* printf("%d ", key_Sort[i]);
    printf("\n");*/
}
