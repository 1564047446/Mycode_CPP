/*************************************************************************
	> File Name: test46.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月12日 星期五 12时28分15秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
    int length, size;
    int *data;
} Node;

void init(Node *node, int size) {
    node->size = size;
    node->length = 0;
    node->data = (int *)malloc(sizeof(int) * size);
}

int insert(Node *node, int value, int locate) {
    if (locate < 0 || locate > node->length) {
        return 0;
    }
    for (int i = node->length; i > locate; i--) {
        node->data[i] = node->data[i - 1];
    }
    node->data[locate] = value;
    node->length++;
    return 1;
}

void clear(Node *node) {
    free(node->data);
    free(node);
}

void print(Node *node) {
    for (int i = 0; i < node->length; i++) {
        if (i == 0) printf("%d", node->data[i]);
        else printf(" %d", node->data[i]);
    }
    printf("\n");
}

int reverse1(Node *node, int k, int tail) {
    int n = k - 1;
    for (int i = 0; i < (k - 0) / 2; i++) {
        int t;
        t = node->data[i];
        node->data[i] = node->data[n];
        node->data[n] = t;
        n--;
    }
    int p = tail + 1;
    for (int i = 0; i < (p - k) / 2; i++) {
        int t;
        t = node->data[k + i];
        node->data[k + i] = node->data[tail];
        node->data[tail] = t;
        tail--;
    }
    return 1;
}

int reverse2(Node *node, int k, int tail) {
    int n = k;
    int num = 0;
    for (int i = n + 1; i <= tail; i++) {
        int t = node->data[i];
        for (int j = k + num; j >= num; j--) {
            node->data[j + 1] = node->data[j];
        }
        node->data[num] = t;
        num++;
    }
}

int main() {
    Node *node = (Node *)malloc(sizeof(Node));
    int n, k;
    scanf("%d%d", &n, &k);
    init(node, n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        insert(node, a, i);
    }
    if (k % n == 0) {
        print(node);
    } else {
        reverse1(node, k, n - 1);
        reverse2(node, k - 1, n - 1);
        reverse1(node, n - k, n - 1);
        print(node);
    }
    
    return 0;
}