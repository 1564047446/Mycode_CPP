/*************************************************************************
	> File Name: test20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月24日 星期五 18时10分15秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>

#define S(a, b) a * b
#define P(a, b) a + b
#define max1(a, b)     (((a)) > (b) ? (a) : (b))
using namespace std;

int Binary_seacher(int *a, int x, int n) {
    int head = 0, tail = n - 1, mid = (head + tail) >> 1;
    while(head <= tail) {
        if(a[mid] == x) return mid;
        if(a[mid] > x) tail = mid - 1;
        if(a[mid] < x) head = mid + 1;
        mid = (head + tail) >> 1;
    }
    return -1;
}

int main() {
    int a[100];
    int *p = a;
    p[0] = 5;
    a[0] = 5;
    int b = 7;
  /*  printf("%d\n", S(3, 4));
    printf("%d\n", S((1 + 2), 3));
    printf("%d\n", 2 * (P(4, 5)));*/
    printf("%d\n", max1(2, 3));
    printf("%d\n", 5 + max1(2, 3));
    printf("%d\n", max1(2, max1(3, 4)));
    printf("%d\n", max1(2, 3 > 4 ? 3 : 4));
    printf("%d\n", max1((b)++, 6));
    printf("%d\n", b);
    sizeof(p);
    sizeof(a);
}
