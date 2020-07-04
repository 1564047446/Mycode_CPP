/*************************************************************************
	> File Name: KMP通用.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月09日 星期四 15时58分53秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#define maxn  100
using namespace std;

int next[maxn];

int get_next(char p[])
{
    next[0] = -1;
    int k = -1;
    int i = 0;
    while(i < strlen(p) - 1)
    {
        if(k == -1 || p[i] == p[k])
        {
            ++i;
            ++k;
            next[i] = k;
        }
        else
        {
            k = next[k];
        }
    
    }
}


int kmp(char s[], char p[])
{
  // get_next(p);
    int flag = 1;
    int i = 0, j = 0;
    while(i < strlen(s) && j < strlen(p))
    {
        if(j == -1 || s[i] == p[j])
        {
            ++i;
            ++j;

        }
        else
        {
            j = next[j];
        }

    }
    if(j == strlen(p))
    cout << "YES\n" << endl;
    else
    cout << "NO\n" << endl;
}

int main()
{
    char s[100], p[100];
    int n;
    scanf("%d", &n);
    while(n--)
    {
        
    
    scanf("%s%s", s,  p);
    get_next(p);
    kmp(s, p);
    for(int i = 0; i < strlen(p); i++)
        cout << next[i] << endl;
    }
}
