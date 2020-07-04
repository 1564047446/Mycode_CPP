/*************************************************************************
	> File Name: CFS1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月15日 星期三 10时44分39秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n + 1] = {1};
    int b[n + 1] = {0};
    for(int i = 1; i <= n; i++)
    a[i] = i;
    int w, s, d;
    for(int i = 1; i <= k; i++)
    
    {
        scanf("%d%d%d", &s, &w, &d);
        b[s] = w + d;
    }
   /* for(int i = 1; i <= n; i++)
    cout << b[s] << " ";
    cout << endl;*/
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(b[i] && b[j] && b[j] < b[i])
            {
                int q, p;
                q = b[j];
                b[j] = b[i];
                b[i] = q;
                p = a[j];
                a[j] = a[i];
                a[i] = p;
            }
        }
    }
  /*  for(int i = 1; i <= n; i++)
    cout << b[i] << " ";
    cout << endl;*/
    for(int i = 1; i <= n; i++)
    cout << a[i] << " ";
    cout << endl;
}

