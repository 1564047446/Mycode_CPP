#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(x, y) { \
	__typeof(x) __temp = x; \
	x = y; \
	y = __temp; \
}

#define hswap(x, y) { \
	swap(root[x], root[y]); \
}

typedef struct Node {
	char value;
	int data;
	struct Node *left, *right;
} Node;

Node *init() {
	Node *root = (Node *)malloc(sizeof(Node));
	root->left = root->right = NULL;
	root->value = root->data = 0;
	return root;
}

Node *build(Node **root, int n) {
	Node *current = NULL;
	for (int i = 0; i < n - 1; i++) {
		int index1 = n - i - 1;
		int index2 = n - i - 2;
		for (int j = 0; j < n - i - 1; j++) {
			if (root[j]->data < root[index1]->data) {
				hswap(j, index1);
				hswap(j, index2);
			}
			if (root[j]->data < root[index2]->data) {
				hswap(j, index2);
			}
		}
		current = init();
		current->left = root[index1];
		current->right = root[index2];
		current->data = root[index1]->data + root[index2]->data;
		root[index2] = current;
	}
	return current;
}

void get_half_code(Node *root, char *str, int k, int *sum) {
	if (root == NULL) return ;
	if (root->right == NULL) {
		str[k] = '\0';
		printf("%c -> %s\n", root->value, str);
		*sum += k * root->data;
		return ;
	}
	str[k] = '0';
	get_half_code(root->left, str, k + 1, sum);
	str[k] = '1';
	get_half_code(root->right, str, k + 1, sum);
	return ;
}

int main() {
	char str[100];
	int n;
	scanf("%d", &n);
	Node **root = (Node **)malloc(sizeof(Node *) * n);
	for (int i = 0; i < n; i++) {
		int data;
		scanf("%s%d", str, &data);
		root[i] = (Node *)malloc(sizeof(Node));
		root[i]->value = str[0];
		root[i]->data = data;
		root[i]->left = root[i]->right = NULL;
	}
	Node *tree = build(root, n);
	char half_code[100];
	int sum = 0;
	get_half_code(tree, half_code, 0, &sum);
	printf("sum = %d\n", sum);
	return 0;
}