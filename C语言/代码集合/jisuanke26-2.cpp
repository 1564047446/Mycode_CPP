/*************************************************************************
	> File Name: jisuanke26-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月27日 星期一 15时55分41秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

int target[1001], a[1001], b[1001];
int num;

int binary_s(int x) {
    int head = 0,  tail = num - 1, mid = (head + tail) >> 1;
    while(head <= tail) {
        if(target[mid] == x) return 1;
        if(target[mid] < x) head = mid + 1;
        if(target[mid] > x) tail = mid - 1;
        mid = (head + tail) >> 1;
    }
    return 0;
}

int is_value(int i, int j, int n) {
    int sum = i, p = 0;
    for(int k = 0; k < n; k++) {
        if(binary_s(sum)) ++p;
        sum += j;
    }
    if(p == n) return 1;
    else 
        return 0;
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    num = 0;
    int k = 0;
    for(int i = 0; i <= m; i++) {
        for(int j = i; j <= m; j++) {
            target[num++] = pow(i, 2) + pow(j, 2);
        }
    }
    sort(target, target + num);
    for(int i = 0; i <= 2 * pow(m, 2); i++) {
        //if(! binary_s(i)) continue;
        for(int j = 1; j <= pow(m, 2) / 2 + 5; j++) {
            //if(! binary_s(j)) continue;
            if(is_value(i, j, n)) {
                a[k] = i, b[k ++] = j;
            }
        }
    }
   // for(int i = 0; i < k; i++) printf("%d   %d\n", a[i], b[i]);
    for(int i = 0; i < k; i++) {
        for(int j = i + 1; j < k; j++) {
            if(b[i] > b[j]) {
                int t1, t2;
                t1 = b[i], b[i] = b[j], b[j] = t1;
                t2 = a[i], a[i] = a[j], a[j] = t2;
            }
        }
    }
    for(int i = 0; i < k; i++) {
        for(int j = i + 1; j < k; j++) {
            if(b[i] == b[j]) {
                if(a[i] > a[j]) {
                    int t1, t2;
                    t1 = a[i], a[i] = a[j], a[j] = t1;
                    t2 = b[i], b[i] = b[j], b[j] = t2;
                }
            }
        }
    }
    for(int i = 0; i < k; i++) printf("%d %d\n", a[i], b[i]);
    return 0;

}
