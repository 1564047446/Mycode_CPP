/*************************************************************************
	> File Name: p115-12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 14时46分32秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int num = 0;
int porker[53] = {1};

int main() {
    int n = 2;
    while(num != 104) {
        for(int i = n; i <= 52; i += n) {
            if(porker[i] == 0) porker[i] = 1;
            else porker[i] = 0;
            num++;
            if(num == 104) break;
        }
        n++;
    }
    for(int i = 1; i <= 52; i++) {
        if(porker[i] == 1) printf("%d ", i);
    }
    printf("\n");
}
