/*************************************************************************
	> File Name: job1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月28日 星期二 16时11分31秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;


int is_value1(int x) {
    int a = x;
    int n = floor(log10(a)) + 1;
	if(x == 0) cout << 1 << " ";
	else printf("%d ", n);
    	if(n == 1) return 0;
    while(a) {
        int num1, num2;
        num1 = a / pow(10, n - 1);
        num2 = a % 10;
        int sum = pow(10, n - 1);
        a = a % sum;
        a /= 10;
        n -= 2;
        if(num1 != num2) return 0;
    }
    return 1;
}

int is_value2(int x) {
	if(x == 1)  return 0;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    while(cin >> n) {
        if(is_value1(n)) printf("Yes ");
        else printf("No ");
        if(is_value2(n)) printf("Yes\n");
        else printf("No\n");
    }
}
