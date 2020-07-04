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
	unsigned char value;
	int data;
	struct Node *left, *right;
	//int *flag;
} Node;

Node *init() {
	Node *root = (Node *)malloc(sizeof(Node));
	root->left = root->right = NULL;
	root->value = root->data = 0;
	//root->flag = 0;
	return root;
}

typedef struct TrieNode {
	struct TrieNode *next[2];
	int flag;
	char value;
} TrieNode, *Trie;

struct TrieNode *get_newNode() {
	TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode) * 1);
	p->flag = 0;
	p->value = 0;
	for (int i = 0; i < 2; i ++) {
		p->next[i] = NULL;
	}
	return p;
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

int insert(Trie tree, unsigned char *str, char **half_code) {
	TrieNode *p = tree;
	while (str[0]) {
		int i = 0;
		while (half_code[str[0]][i]) {
			if (p->next[half_code[str[0]][i] - '0'] == NULL) {
				p->next[half_code[str[0]][i] - '0'] = get_newNode();
			}
			p = p->next[half_code[str[0]][i] - '0'];
			++i;
		}
		++str;
	}
	p->flag = 1;
	return 1;
}

int search(Trie tree, unsigned char *str, char **code) {
	TrieNode *p = tree;
	while (str[0] && p) {
		int i = 0;
		while (code[str[0]][i] && p->next[code[str[0]][i] - '0'] != NULL) {
			p = p->next[code[str[0]][i] - '0'];
			++i;
		}
		++str;
	}
	return p && p->flag;
}

void get_half_code(Node *root, char *str, char **code, int k, int *num) {
	if (root == NULL) return ;
	if (root->right == NULL) {
		str[k] = '\0';
        printf("%c -> %s\n", root->value, str);
		strcpy(code[root->value], str);
		return ;
	}
	str[k] = '0';
	get_half_code(root->left, str, code, k + 1, num);
	str[k] = '1';
	get_half_code(root->right, str, code, k + 1, num);
	return ;
}

int main() {
	unsigned char str[256][256];
	int num[256], q = 0;
	char code[256][256];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int data;
		scanf("%s", str[i]);
		for (int j = 0; str[i][j]; j++) {
			if (num[str[i][j]] == 0) ++q;
			num[str[i][j]] += 1;  // freq
		}
	}
	int cnt = 0;
	Node **root = (Node **)malloc(sizeof(Node *) * q);
	for (int i = 0; i < 256; i++) {
		if (num[i] != 0) {
			root[cnt] = (Node *)malloc(sizeof(Node));
			root[cnt]->data = num[i];
			root[cnt]->value = i;
			root[cnt]->left = root[cnt++]->right = NULL;
		}
	}
	Node *tree = build(root, q);
	char **half_code = (char **)malloc(sizeof(char) * 256);
	for (int i = 0; i < 256; i++) {
		half_code[i] = (char *)malloc(sizeof(char) * 256);
	}
	char str2[256];
	get_half_code(tree, str2, half_code, 0, num);
	int m;
	TrieNode *p = get_newNode();
	for (int i = 0; i < n; i++) {
		insert(p, str[i], half_code);
	}
	scanf("%d", &m);
	while (m--) {
		unsigned char str3[100];
		scanf("%s", str3);
		int ans = search(p, str3, half_code);
		if (ans) printf("is found\n");
		else printf("not found\n");
	}
	return 0;
}
