/*************************************************************************
	> File Name: aa1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月06日 星期一 23时00分04秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>


using namespace std;


int gcd(int a, int b)
{
    if(b == 0)
    return a;
    else
    return gcd(b, a % b);
}

int is_value(int x, int y)

{
   // y = 20;
    return log10(y) / log10(x);
}
int main()
{
    long long p[21] = {0};
    long long sum = 1;
    for(long long i = 2; i <= 20; i++)

    {
        if(!p[i])
        {
            p[++ p[0]] = i;
            int k = i;
            k = pow(k, is_value(i, 20));
            cout << i << endl;
            sum *= k;
        }
        for(long long j = 1; j <= p[0]; j++)
        {
           
           if(i * p[j] > 20) break;
            p[i * p[j]] = 1;
               // cout << i * p[j] << endl;
            if(i % p[j] == 0) break;
          /*  p[i * p[j]] = 1;
            cout << i * p[j] << endl;
            if(i % p[j] == 0);*/
        }
    }
    int n;
    while(cin >> n)
    {
        cout << p[n] << endl;
        cout << sum << endl;
    }

}
