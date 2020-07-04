
 

/*************************************************************************
   > File Name: 6.halfman.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 六  1/20 20:30:19 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[1000];
    int freq;
    struct Node *lchild, *rchild;
} Node;

#define swap(x, y) { \
    __typeof(x) __temp = x; \
    x = y; \
    y = __temp; \
}

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->lchild = p->rchild = NULL;
    p->freq;
    return p;
}

Node *build(Node **halfman_node, int n) {
    #define hswap(x, y) { \
        swap(halfman_node[x], halfman_node[y]); \
    }
    Node *root;
    for (int i = 0; i < n - 1; i++) {
        int ind1 = n - i - 1;
        int ind2 = n - i - 2;
        if (halfman_node[ind1]->freq > halfman_node[ind2]->freq) {
            hswap(ind1, ind2);
        }
        for (int j = 0; j < ind2; j++) {
            if (halfman_node[j]->freq < halfman_node[ind1]->freq) {
                hswap(j, ind1);
                hswap(j, ind2);
            } else if (halfman_node[j]->freq < halfman_node[ind2]->freq) {
                hswap(j, ind2);
            }
        }
        root = getNewNode();
        root->lchild = halfman_node[ind1];
        root->rchild = halfman_node[ind2];
        root->freq = halfman_node[ind1]->freq + halfman_node[ind2]->freq;
        halfman_node[ind2] = root;
    }
    #undef hswap
    return root;
}

void getEncode(Node *root, int k, char *str) {
    if (root == NULL) return ;
    if (root->lchild == NULL) {
        str[k] = '\0';
        printf("%s -> %s\n", root->data, str);
        return ;
    }
    str[k] = '0';
    getEncode(root->lchild, k + 1, str);
    str[k] = '1';
    getEncode(root->rchild, k + 1, str);
    return ;
}

void find(Node *root, char *str, int *flag) {
    if (root == NULL) return ;
    if (strcmp(root->data, str) == 0) {
        *flag = 1;
        return ;
    }
    if (root->lchild) find(root->lchild, str, flag);
    if (root->rchild) find(root->rchild, str, flag);
    return ;
}

int main() {
    int n;
    char str[1000];
    int freq;
    scanf("%d", &n);
    Node **halfman_node = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++) {
        scanf("%s%d", str, &freq);
        halfman_node[i] = getNewNode();
        //halfman_node[i]->data = str;
        strcpy(halfman_node[i]->data, str);
        halfman_node[i]->freq = freq;
    }
    Node *root = build(halfman_node, n);
    char encode[100];
    getEncode(root, 0, encode);
    int m;
    scanf("%d", &m);
    char buffer[1000];
    for (int i = 0; i < m; i++) {
        scanf("%s", buffer);
        int flag = 0;
        find(root, buffer, &flag);
        if (flag) printf("is find\n");
        else printf("not found\n");
    }
    return 0;
}

