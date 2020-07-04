/*************************************************************************
	> File Name: BBST.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月09日 星期五 14时06分09秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max(a, b) ({\
    __typeof(a) temp = a;\
    __typeof(b) temp2 = b;\
    temp > temp2 ? temp :temp2;\
})

typedef struct AVLTree {
    int key, hight;
    struct AVLTree *left, *right;
} AVLTree;

AVLTree __NIL;
#define NIL (&__NIL)
//int  _____temp = static_init();

int static_init() {
    NIL->right = NIL->left = NIL;
    NIL->hight = 0;
    return 0;
}

int _____temp = static_init();

AVLTree *init(int key) {
    AVLTree *p = (AVLTree *)malloc(sizeof(AVLTree));
    p->key = key;
    p->left = p->right = NIL;
    p->hight = 1;
    return p;
}

inline void Up(AVLTree *root) {
    root->hight = max(root->left->hight, root->right->hight) + 1;
}

AVLTree *left_rorate(AVLTree *root) {
    AVLTree *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    Up(root);
    Up(temp);
    return temp;
}

AVLTree *right_rorate(AVLTree *root) {
    AVLTree *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    Up(root);
    Up(temp);
    return temp;
}

AVLTree *__maintain(AVLTree *root, int flag) {
    if (flag == 1) {
        if (root->left->right->hight > root->left->left->hight) {
            root->left = left_rorate(root->left);
        }
        root = right_rorate(root);
    } else {
        if (root->right->left->hight > root->right->right->hight) {
            root->right = right_rorate(root->right);
        }
        root = left_rorate(root);
    }
}

AVLTree *maintain(AVLTree *root) {
    if (abs(root->left->hight - root->right->hight) < 2) return root;
    root = __maintain(root, root->left->hight > root->right->hight);
    return root;
}

AVLTree *insert(AVLTree *root, int key) {
    if (root == NIL) {
        return init(key);
    }
    if (key == root->key) return root;
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    Up(root);
    root = maintain(root);
    return root;
}

void clear(AVLTree *node) {
    if (node == NIL) return ;
    clear(node->left);
    clear(node->right);
    free(node);
    return ;
}

void pre_order(AVLTree *root) {
    if (root == NIL) return ;
    printf("%d (%d, %d)\n", root->key, root->left->key, root->right->key);
    pre_order(root->left);
    pre_order(root->right);
    return ;
}

int main() {
    int n;
    AVLTree *root = NIL;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        root = insert(root, a);
        printf("Tree info :\n");
        pre_order(root);
        printf("_____________\n");
    }
    clear(root);
    return 0;
}
