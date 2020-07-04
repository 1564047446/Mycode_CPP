/*************************************************************************
	> File Name: 顺序表.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月11日 星期四 16时42分05秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


typedef struct Node {
    int length, size;
    int *data;
} Node;

Node *init(int n = 3) {
    Node *ret = (Node *)malloc(sizeof(Node));
    ret->data = (int *)malloc(sizeof(int) * n);
    ret->size = n;
    ret->length = 0;
    return ret;
}

void clear(Node *node) {
    if (node == NULL) return;
    if (node->data != NULL) {
        free(node->data);
    }
    free(node);
    return ;
}

int expand(Node *node) {
    int *p = (int *)realloc(node->data, node->size * 2 * sizeof(int));
    if (p == NULL) return 0;
    node->data = p;
    node->size *= 2;
    return 1;
}

int insert(Node *node, int value, int index) {
    if (node == NULL) return 0;
    if (index > node->length || index < 0) return 0;
    if (node->length == node->size && !expand(node)) return 0; 
    for (int i = node->length; i > index; i--) {
        node->data[i] = node->data[i - 1];
    }
    node->data[index] = value;
    node->length++;
    return 1;
}

int delete_node(Node *node, int index) {
    if (node == NULL) return 0;
    if (index < 0 || index >= node->length) return 0;
    for (int i = index + 1; i < node->length; i++) {
        node->data[i - 1] = node->data[i];
    }
    node->length--;
    return 1;
}

void output(Node *node) {
    printf("[ ");
    for (int i = 0; i < node->length; i++) {
        printf("%d ", node->data[i]);
    }
    printf("]\n");
}

int main() {
    Node *node = init();
    int value, index;
    while (~scanf("%d%d", &value, &index)) {
        printf("insert : %d\n", insert(node, value, index));
        output(node);
    }
    clear(node);
}
