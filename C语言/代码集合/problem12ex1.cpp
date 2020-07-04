/*************************************************************************
	> File Name: problem12ex1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月13日 星期一 11时24分32秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<inttypes.h>

using namespace std;

int64_t triangle(int64_t x)
{
    return x * (x + 1) / 2;
}

int64_t get_NUM(int64_t n)
{
    int64_t sum = 1;
    for(int64_t i = 2; i * i <= n; i++)
    {
        if(n % i != 0)
        continue;
        int64_t num = 1;
        while(n % i == 0)
        {
            n /= i;
            num++;
        }
        sum *= num;
        
    }
  //  sum *= num;
    if(n != 1)
    sum *= 2;
    return sum;
}

int main()
{
   int64_t k = 1;
    while(get_NUM(triangle(k)) <= 500)
    {
        k++;
      //  cout << k << endl;
    }
    printf("%"PRId64   "      "   "%"PRId64 "\n", triangle(k), get_NUM(triangle(k)));

    


}

