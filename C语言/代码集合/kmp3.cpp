/*************************************************************************
	> File Name: kmp3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月15日 星期三 14时04分03秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>

int next[1000];
char s[100], p[100];
using namespace std;


void get_next()
{
    int i = 0, k = -1;
    next[0] = -1;
    while(i <= strlen(p))
    {
        if(k == -1 || p[i] == p[k])
        {
            next[++i] = ++k;
        }
        else
            k = next[k];
    }

}


int kmp()
{
    get_next();
    int i = 0, j = 0;
    while(i < strlen(s))
    {
        if(j == - 1 || s[i] == p[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
        if(j == strlen(p))
        return 1;
    }
    return 0;
    
}

int main()
{
    while(cin >> p >> s)
    {
        cout << kmp() << endl;
    }
}
