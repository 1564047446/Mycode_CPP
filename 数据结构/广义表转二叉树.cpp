#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	char value;
	struct Node *left, *right;
}Node, *Btree;

Btree init(char value) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = value;
	node->left = node->right = NULL;
	return node;
}

Node *build(char *str) {
	int k = 0, i = 0;
	Node *p = NULL, *root;
	static Node *s[101];
	int top = -1;
	while (str[i]) {
		switch (str[i]) {
			case '(':
				s[++top] = p;
				p = NULL;
				k = 1;
				break;
			case ')':
				if (top == -1) {
					printf("error\n");
					return NULL;
				}
				top--;
				break;
			case ',':
				k = 2;
				break;
			case ' ': 
				break;
			default :
				p = init(str[i]);
				if (k == 0) {
					root = p;
				} else if(s[top] == NULL) {
					fprintf(stderr, "error root\n");
					break;
					return NULL;
				} else if (k == 1) {
					s[top]->left = p;
				} else {
					s[top]->right = p;
				}
				break;
		}
		++i;
	}
	if (top != -1) {
		fprintf(stderr, "error top\n");
		return NULL;
	}
	return root;
}

void output(Node *root) {
	if (root == NULL) return ;
	printf("%c", root->value);
	if (root->left != NULL) output(root->left);
	if (root->right != NULL) output(root->right);
	return ;
}

int main() {
	char str[100];
	Node *root = NULL;
	while (~scanf("%[^\n]s", str)) {
		getchar();
		root = build(str);
		output(root), printf("\n");
	}
	return 0;
}