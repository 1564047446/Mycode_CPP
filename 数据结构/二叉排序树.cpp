#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
	int key;
	struct BSTNode *left, *right;
} BSTNode;

BSTNode *get_new_node(int key) {
	BSTNode *p = (BSTNode *)malloc(sizeof(BSTNode));
	p->left = p->right = NULL;
	p->key = key;
	return p;
}

BSTNode *get_pre_node(BSTNode *tree) {
	BSTNode *temp = tree->left;
	while (temp->right) {
		temp = temp->right;
	}
	return temp;
}

BSTNode *insert(BSTNode *tree, int key) {
	if (tree == NULL) {
		return get_new_node(key);
	}
	if (tree->key == key) return tree;
	if (key < tree->key) {
		tree->left = insert(tree->left, key);
	} else {
		tree->right = insert(tree->right, key);
	}
	return tree;
}

BSTNode *delete_node(BSTNode *tree, int key) {
	if (tree == NULL) return NULL;
	if (tree->key > key) {
		tree->left = delete_node(tree->left, key);
	} else if (tree->key < key){
		tree->right = delete_node(tree->right, key);
	} else {
		if (tree->left == NULL && tree->right == NULL) {
			free(tree);
			return NULL;
		} else if (tree->left == NULL || tree->right == NULL) {
			BSTNode *ret_tree = (tree->left ? tree->left : tree->right);
			free(tree);
			return ret_tree;
		} else {
			BSTNode *p = get_pre_node(tree);
			tree->key == p->key;
			tree->left = delete_node(tree->left, p->key);
		}
	}
	return tree;
}

int search(BSTNode *tree, int key) {
	if (tree == NULL) return 0;
	if (key == tree->key) return 1;
	if (key < tree->key) return search(tree->left, key);
	if (key > tree->key) return search(tree->right, key);
}

void clear(BSTNode *tree) {
	if (tree == NULL) return ;
	clear(tree->left);
	clear(tree->right);
	free(tree);
	return ;
}

void in_order(BSTNode *tree) {
	if (tree == NULL) return ;
	in_order(tree->left);
	printf("%d ", tree->key);
	in_order(tree->right);
	return ;
}

int main() {
	int op, value;
	BSTNode *tree = NULL;
	while (~scanf("%d%d", &op, &value)) {
		if (op == -1) break;
		switch (op) {
			case 1: tree = insert(tree, value);break;
			case 2: tree = delete_node(tree, value); break;
			case 3: printf("%d\n", search(tree, value)); break;
			case 4: in_order(tree), printf("\n"); break;
		}
	}
	return 0;
}
