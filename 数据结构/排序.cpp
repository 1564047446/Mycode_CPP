/*************************************************************************
	> File Name: 排序.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月23日 星期二 19时06分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define swap(a, b) { \
    __typeof(a) t = a; \
    a = b; \
    b = t; \
}

void insert_sort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j + 1] < a[j]) {
                swap(a[j + 1], a[j]);
            } else {
                break;
            }
        }
    }
}


void bubble_sort(int *a, int n) {
    int times = 0;
    for (int i = 0; i < n - 1; i++) {
        times = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                times = 1;
            }
        }
        if (times == 0) break;
    }
}

#define TEST(n, func) { \
    int *num = (int *)malloc(sizeof(int) * n); \
    for (int i = 0; i < n; i++) { \
        num[i] = rand() % 100; \
    } \
    func; \
    printf("%s :", #func); \
    for (int i = 0; i < n; i++) { \
        printf("%d ", num[i]);\
    }\
    printf("\n");\
}

void merge_sort(int *a, int left, int right) {
    if (left == right) return ;
    int mid = (left + right) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    int *temp = (int *)malloc(sizeof(int) * (right - left + 1));
    int index1 = left, index2 = mid + 1, k = 0;
    while (index1 <= mid || index2 <= right) {
        if (index2 > right || (index1 <= mid && a[index1] <= a[index2])) {
            temp[k++] = a[index1++];
        } else {
            temp[k++] = a[index2++];
        }
    }
    memcpy(a + left, temp, sizeof(int) * (right - left + 1));
    free(temp);
    return ;
}

void select_sort(int *num, int n) {
    for (int i = 0; i < n - 1; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (num[j] < num[index]) index = j;
        }
        swap(num[i], num[index]);
    }
    return ;
}


void select_sort_good(int *num, int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (num[i] < num[index]) index = i;
    }
    while (index) {
        swap(num[index], num[index - 1]);
        --index;
    }
    for (int i = 2; i < n; i ++) {
        for (int j = i - 1; num[j] < num[j - 1]; j--) {
                swap(num[j + 1], num[j]);
        }
    }
    return ;
}

void quick_sort(int *num, int left, int right) {
    if (left >= right) return ;
    int x = left, y = right, z = num[left];
    while (x < y) {
        while (x < y && num[y] >= z) y--;
        if (x < y) num[x] = num[y], x++;
        while (x < y && num[x] <= z) x++;
        if (x < y) num[y] = num[x], y--;
    }
    num[x] = z;
    quick_sort(num, left, x - 1);
    quick_sort(num, x + 1, right);
}

void quick_sort_good(int *num, int left, int right) {
    while (left < right){
        int x = left, y = right, z = num[(left + right) / 2];
        do {
            while (num[x] < z) ++x;
            while (num[y] > z) --y;
            if (x <= y) {
                swap(num[x], num[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort_good(num, x, right);
        right = y;
    }
    return ;
}

int main() {
    srand(time(0));
    TEST(20, bubble_sort(num, 20));
    TEST(20, insert_sort(num, 20));
    TEST(20, merge_sort(num, 0, 19));
    TEST(20, quick_sort(num, 0, 19));
    TEST(20, select_sort(num, 20));
    TEST(20, quick_sort_good(num, 0, 19));
    return 0;
} 
