/*************************************************************************
	> File Name: kmp1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月15日 星期三 11时30分27秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>

int next[100];
char s[100], t[100];
using namespace std;

void get_next()
{
    int k = -1;
    next[0] = -1;
    int j = 0;
    while(j < strlen(t))
    {
        if(k == -1 || t[j] == t[k])
        {
            ++j;
            ++k;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}


int kmp()
{
    int i = 0, j = 0;
    while(i < strlen(s) && j < strlen(t))
    {
        if(j == -1 || s[i] == t[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
        if(j == strlen(t))
        return 1;
    }
    return 0;
    
}


int main()
{

   
    while(1)
    {
        
    
    scanf("%s%s", t, s);
    get_next();
  /*  for(int i = 0; i < strlen(s); i++)
    cout << next[i] << " ";
        cout << endl;*/
    if(kmp())
    cout << "OK" << endl;
    else
    cout << "NO" << endl;
    }

    return 0;
}
