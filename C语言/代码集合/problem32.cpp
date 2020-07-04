/*************************************************************************
	> File Name: problem32.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 23时34分57秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int s[1000000] = {0};

int is_value(int x, int y, int z)
{
    int a[10] = {0};
    
    while(x || y ||z)
    {
        a[x % 10] = 1;
        a[y % 10] = 1;
        a[z % 10] = 1;
        x /= 10; y /= 10; z /= 10;
    }
    
    int num = 0;
    for(int j = 1; j <= 9; j++)
    {
        if(a[j] == 0)
        num ++;
    }
    if(num == 0)
    return 1;
    else
    return 0;

}


int digit_num(int x, int y, int z)
{
    if(floor(log10(x)) + floor(log10(y)) + floor(log10(z)) + 3 > 9)
    return 0;
    else
    return 1;
}



int main()
{
   long long sum = 0;
    for(int i = 1; i <= 99; i++)
    {
        for(int j = 99; j <= 2000; j++)
        {
            if(is_value(i, j, i * j) && s[i * j] == 0 && digit_num(i, j, i * j))
            {
               
                sum += i * j;
                
                s[i * j] = 1;
                cout << i * j  << endl;
            }
                 
        }
    }
    
    
    cout << is_value(39, 186, 7254) << endl;
    printf("%lld\n", sum);
}

