/*************************************************************************
	> File Name: 二叉树.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月18日 星期四 18时41分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node, *BinaryTree;

Node *init(int n) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = n;
    p->left = p->right = NULL;
    return p;
}

Node *clear(BinaryTree tree) {
    if (tree == NULL) return tree;
    clear(tree->left);
    clear(tree->right);
    free(tree);
    return tree;
}

int pre_order(BinaryTree tree) {
    if (tree == NULL) return 0;
    printf("%d ", tree->data);
    tree->left && (pre_order(tree->left));
    tree->right && (pre_order(tree->right));
    return 1;
}

int in_order(BinaryTree tree) {
    if (tree == NULL) return 0;
    tree->left && in_order(tree->left);
    printf("%d ", tree->data);
    tree->right && in_order(tree->right);
}

int post_order(BinaryTree tree) {
    if (tree == NULL) return 0;
    tree->left && post_order(tree->left);
    tree->right && post_order(tree->right);
    printf("%d ", tree->data);
}

int get_depth(BinaryTree tree) {
    if (tree == NULL) return 0;
    int l = get_depth(tree->left);
    int r = get_depth(tree->right);
    return (l > r ? l : r) + 1;
}

int main() {
    BinaryTree tree = init(1);
    tree->left = init(2);
    tree->right = init(3);
    tree->left->left = init(4);
    tree->left->right = init(5);
    tree->right->left = init(6);
    tree->right->right = init(7);
    pre_order(tree), printf("\n");
    in_order(tree), printf("\n");
    post_order(tree), printf("\n");
    printf("Depth %d \n", get_depth(tree));
    tree = clear(tree);
    pre_order(tree), printf("\n");
    return 0;
}
