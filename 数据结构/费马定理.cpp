/*************************************************************************
	> File Name: 费马定理.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月25日 星期四 16时11分58秒
 ************************************************************************/

#include<iostream>
using namespace std;

int prime[10001] = {0};

//费马定理公式 : a ^(p - 1) mod p = 1  p为素数且a不能整除p

int quick_mod(int n, int m, int mod_num) {
    int ans = 1, temp = n;
    while (m) {
        if (m & 1) ans = (ans * temp) % mod_num;
        temp = (temp * temp) % mod_num;
        m >>= 1;
    }
    return ans;
}

void setSeed() {
    //素数晒
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
     int n = 1, m, flag = 1;
    
    for (; prime[n] <= maxn_n; n++) {

    }
    for (m = 1; ; m++) {
        flag = 0;
        for (int i = 2; i < prime[n] - 1; i++) {
            if ((prime[n] - 1) % i) continue;
            if (quick_mod(m, i, prime[n]) == 1) {
                flag = 1;
                break;
            }
        }
            if (!flag) break;
    }
    __mod_num = prime[n];
    __multi_num = m;
    printf("seed : %d %d\n", prime[n], m);
}

int getnum() {
    static int n = 1;
    if (__mod_num > __multi_num) return 0;
    n = (n * __mod_num) % __multi_num
    return n;
}


int main() {
    
}
