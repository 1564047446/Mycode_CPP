/*************************************************************************
	> File Name: test8.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月16日 星期四 17时38分35秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int a[10];
int maxn = 100;

int get_MUL(int n)
{
    int sum = 1;
    for(int i = 1; i <= n; i++)
        sum *= i;
    return sum;
}

void get_sort(int x, int n)
{
    if(x == 9)
        x = -1;
    for(int i = 0; i < 10; i++)
    {
        if( x + 1 == a[i])
        {
            
            int t;
            t = a[i];
            a[i] = a[n];
            a[n] = t;
            cout << a[i] << "     " << a[n] << endl;
            break;
        }
        
    }
}



int main()
{
    for(int i = 0; i < 10; i++)
        a[i] = i;
    int k = 1;
    for(int i = 9; i >= 0; i--)
    {
        while(k + get_MUL(i) <= maxn)
        {
            get_sort(a[9 - i], 9 - i);
            k += get_MUL(i);
        }
    }
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    cout << endl;

}
