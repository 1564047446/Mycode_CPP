/*************************************************************************
	> File Name: jisuanke26-3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月27日 星期一 22时44分01秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;


int target[1000010] = {0};

int main() {
    int n, m, num = 0;
    bool flag = 1;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= m; j++) 
            target[i * i + j * j] = 1;
    }
    for(int j = 1; j <= pow(m, 2) / 2; j++) {
            int a, p;
            for(int i = 0; i <= pow(m, 2) * 2; i++) {
                a = i, p = 0;
                if(!target[a]) continue;
                for(int k = 0; k < n; k++) {
                    //if(a > pow(m, 2) * 2) break;
                    if(target[a]) a += j, ++p;
                }
                if(p == n) {
                    printf("%d %d\n", i, j);
                    flag = 0;
                }
            }
    }
    if(flag) printf("NONE\n");
    //cout << target[12] << endl;
}
