#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>

using namespace std;

int num = 0;
int target[1001] = {0};
int a[1001] = {0}, b[1001] = {0};
int binary_search(int x, int y) {
    int head = 0, tail = y - 1, mid = (head + tail) >> 1;
    while(head <= tail) {
        if(target[mid] == x) return 1;
        if(target[mid] < x) head = mid + 1;
        if(target[mid] > x) tail = mid - 1;
        mid = (head + tail) >> 1;
    }
    return 0;
}

int is_value(int i, int j, int n) {
    int p = 0, sum = i;
    for(int k = 1; k < n; k++) {
        sum += j;
        cout << sum << "   " << binary_search(sum, num) << endl;
        if(binary_search(sum, num)) {
            p ++;
        }
       // sum += j;
    }
    //cout << num1 << endl;
    //cout << i << "   " << j << "   " << num1 <<endl;
    if(p == n - 1) return 1;
    else return 0;
}


int main() {
    int n, m;
    int k = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= m; i++) {
        for(int j = i; j <= m; j++) {
            target[num++] = pow(i, 2) + pow(j, 2);
        }
    }
    //for(int i = 0; i < num; i++) printf("%d\n", target[i]);
    sort(target, target + num);
    //for(int i = 0; i < num; i++) printf("%d\n", target[i]);
    for(int i = 0; i <= 2 * pow(m, 2); i++) {
        if(!binary_search(i, num)) continue;
        for(int j = 1; j <= pow(m, 2) / 2; j++) {
            if(!binary_search(j, num)) continue;
            //cout << binary_search(j, num);
            if(is_value(i, j, n)) {
                a[k] = i, b[k ++] = j;
            }
        }
    }
    for(int i = 0; i < k; i++) {
        printf("%d %d\n", a[i], b[i]);
    }
}
