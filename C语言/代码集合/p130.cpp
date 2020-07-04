/*************************************************************************
	> File Name: p130.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 13时27分11秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;


int main() {
    float a, b;
    scanf("%f%f", &a, &b);
    float fa = pow(a, 3) / 2 + pow(a, 2) * 2 - 8;
    float fb = pow(b, 3) / 2 + pow(b, 2) * 2 - 8;
    float fc;
    if(fa * fb > 0) printf("no \n");
    float c;
    do {
        c = (a + b) / 2;
        //float fc;
        fc = pow(c, 3) / 2 + pow(c, 2) * 2 - 8;
        if(fc == 0) break;
        if(fa * fc < 0) {
            b = c;
        }
        else {
            a = c;
            fa = fc;
        }
    } while(fabs(fc) >= 1e-4);
    printf("%.6f\n", c);
}
