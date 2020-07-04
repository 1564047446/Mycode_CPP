/*************************************************************************
	> File Name: job2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月28日 星期二 16时35分19秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>

int f[1000];
using namespace std;


int main() {
    f[1] = 1, f[2] = 1;
    for(int i = 3; i < 30; i++)
        f[i] = f[i - 1] + f[i - 2];
    int n;
    //for(int i = 3; i < 20; i++) cout << f[i];
    while(cin >> n) {
        int k;
        for(int i = 1; i < 26; i++) {
            if(f[i] > n) {
                k = i;
                break;
            }
        }
    //cout << n << endl;
    if(f[k] - n > abs(f[k - 1] - n)) printf("%d %d\n", k-1, f[k - 1]);
    else
    printf("%d %d\n", k, f[k]);
    }
    
    
}
