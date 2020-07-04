/*************************************************************************
	> File Name: test16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 15时22分58秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

#define INF 0xffffffff

int main()
{
    int n = 1;
    switch(n)
    {
        case 1:
        {
            cout << "one" << endl;
            break;
        }
        //break;
        case 2:
        {
            cout << "two" << endl;
            break;
        }
        //break;
        case 3:
        {
            cout << "tree" << endl;
            break;
        }
        default:
        {
            cout << "error" << endl;
            break;
        }
    }

    int i = 1;
    while(i <= 100)
    {
        cout << i << endl;
        ++i;
    }
    for(int i = 1; i <= 100; i++)
    cout << i << endl;
}
 
