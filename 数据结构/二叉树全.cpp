#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	char value;
	struct Node *left, *right;
} Node;

Node *init(char value) {
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = value;
	root->left = root->right = NULL;
	return root;
}

Node *build_tree(char *str, int n) {
	Node *current = NULL, *root = NULL;
	Node **stack = (Node **)malloc(sizeof(Node *) * n);
	int top = -1, flag = 0, i = 0;
	while (str[i]) {
		switch (str[i]) {
			case '(':
				stack[++top] = current;
				current = NULL;
				flag = 1;
				break;
			case ')':
				if (top == -1) {
					printf("error\n");
					return NULL;
				}
				--top;
				break;
			case ',':
				flag = 2;
				break;
			default :
				current = init(str[i]);
				if (root == NULL) {
					root = current;
				}
				if (stack[top] == NULL) {
					printf("errot\n");
					return NULL;
				}
				if (flag == 1) {
					stack[top]->left = current;
				}
				if (flag == 2) {
					stack[top]->right = current;
				}
				break;
		}
		++i;
	}
	if (top != -1) {
		printf("error\n");
		return NULL;
	}
	return root;
}

void get_table(Node *root) {
	if (root == NULL) return ;
	printf("%c", root->value);
	if (root->left != NULL) {
		printf("(");
		get_table(root->left);
		if (root->right == NULL) {
			printf(")");
		}
	}
	if (root->right != NULL) {
		if (root->left == NULL) {
			printf("(");
		}
		printf(",");
		get_table(root->right);
		printf(")");
	}
}

void get_table2(Node *root) {
	if (root == NULL) return ;
	printf("%c", root->value);
	if (root->left == NULL && root->right == NULL) return ;
	printf("(");
	if (root->left) get_table2(root->left);
	if (root->right) {
		printf(",");
		get_table2(root->right);
	}
	printf(")");
}

int num = 0;
char* table(Node *root) {
	static char *s = (char *)malloc(sizeof(char) * 100);
	if (root == NULL) return s;
	//printf("%c", root->value);
	s[num++] = root->value;
	if (root->left != NULL) {
		//printf("(");
		s[num++] = '(';
		get_table(root->left);
		if (root->right == NULL) {
			//printf(")");
			s[num++] = ')';
		}
	}
	if (root->right != NULL) {
		if (root->left == NULL) {
			//printf("(");
			s[num++] = '(';
		}
		//printf(",");
		s[num++] = ',';
		get_table(root->right);
		//printf(")");
		s[num++] = ')';
	}
}

void get_middle(Node *root) {
	Node **q = (Node **)malloc(sizeof(Node *) * 100);
	Node *current = NULL;
	current = root;
	int head = 0, tail = -1;
	q[++tail] = root;
	while (tail >= head) {
		printf("%c ", q[head]->value);
		if (q[head]->left != NULL) {
			q[++tail] = q[head]->left;
		}
		if (q[head]->right != NULL) {
			q[++tail] = q[head]->right;
		}
		++head;
	}
	return ;
}

void pre_order(Node *root) {
	if (root == NULL) return ;
	printf("%c ", root->value);
	if (root->left) pre_order(root->left);
	if (root->right) pre_order(root->right);
}

void in_order(Node *root) {
	if (root == NULL) return ;
	if (root->left) in_order(root->left);
	printf("%c ", root->value);
	if (root->right) in_order(root->right);
}

void post_order(Node *root) {
	if (root == NULL) return ;
	if (root->left) post_order(root->left);
	if (root->right) post_order(root->right);
	printf("%c ", root->value);
}

int get_Depth(Node *root) {
	if (root == NULL)
		return 0;
	int l = get_Depth(root->left);
	int r = get_Depth(root->right);
	return (l > r ? l : r) + 1;
}

int main() {
	char str[100];
	Node *root = (Node *)malloc(sizeof(Node));
	Node *root2 = (Node *)malloc(sizeof(Node));
	scanf("%s", str);
	root2 = build_tree(str, strlen(str));
	root = build_tree(str, strlen(str));
	get_table(root);
	printf("\n");
	get_middle(root);
	printf("\n");
	int Depth = get_Depth(root2);
	printf("Depth = %d\n", Depth);
	char *s = table(root2);
	printf("%s\n", s);
	return 0;
}