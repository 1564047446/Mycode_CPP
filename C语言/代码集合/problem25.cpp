/*************************************************************************
	> File Name: problem25.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 22时13分37秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>

using namespace std;


long f[3][1005] = {0};

int main()
{
    f[1][0] = f[1][1] = 1;
    f[2][1] = f[2][0] = 1;
    f[0][0] = 1;
    long  num = 2;
    while(f[num % 3][0] < 1000)
    {
       num++;
        for(long i = 1; i <= f[(num - 1) % 3][0]; i++)
        {
            f[num % 3][i] = f[(num - 1) % 3][i] + f[(num - 2) % 3][i];
        }
        f[num % 3][0] = f[(num - 1) % 3][0];
        for(long i = 1; i <= f[num % 3][0]; i++)
        {
            if(f[num % 3][i] < 10)
            continue;
            f[num % 3][i + 1] += f[num % 3][i] / 10;
            f[num % 3][i] %= 10;
            if(i == f[num % 3][0])
            f[num % 3][0]++;
        }
        cout << "lalala" << endl;

    }
    printf("%ld\n", num);
    
}
