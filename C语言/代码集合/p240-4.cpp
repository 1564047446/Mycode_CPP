/*************************************************************************
	> File Name: p240-4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月20日 星期三 12时50分15秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int get_value(int x) {
    int a[10] = {0};
    while (x) {
        if (a[0] == 1) return 0;
        if (a[x % 10] == 1) return 0;
        a[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

int get_num(int x) {
    int a[10] = {0};
    int i = 0;
    while (x) {
        a[i++] = x % 10;
        x /= 10;
    }
    int num = 1, sum = 0;
    for ( i = 9; i > 0; i++) {
        sum = sum * 10 + a[i];
        if (sum % num != 0) return 0;
        num++;
    }
    return 1;
}


int main() {
    for (int i = 100000000; i < 999999999; i++) {
        if (get_value(i) && get_num(i)) {

        }
    }
}
