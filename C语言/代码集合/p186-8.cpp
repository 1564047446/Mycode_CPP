/*************************************************************************
	> File Name: p186-8.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月13日 星期三 19时35分04秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>


int get_value(int n) {
    
    int a[10] = {0};
    int x = n, sum = 0;
    while (x) {
        sum += pow(x % 10, 2);
        x /= 10;
    }
    if (n % sum != 0) return 0;
    x = n;
    while (x) {
        if (a[x % 10] == 1) return 0;
        a[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

int main() {

    for (int i = 1000; i < 10000; i++) {
        if (get_value(i)) printf("%d\n", i);
    }
}
