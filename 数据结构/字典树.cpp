#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TrieNode {
	struct TrieNode *next[26];
	int flag;
} TrieNode, *Trie;

struct TrieNode *get_newNode() {
	TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode) * 1);
	p->flag = 0;
	for (int i = 0; i < 26; i ++) {
		p->next[i] = NULL;
	}
	return p;
}

void clear(Trie tree) {
	if (tree == NULL) return ;
	for (int i = 0; i < 26; i++) {
		if (tree->next[i] == NULL) continue;
		clear(tree->next[i]);
	}
	free(tree);
	return ;
}

int insert(Trie tree, const char *str) {
	TrieNode *p = tree;
	while (str[0]) {
		if (p->next[str[0] - 'a'] == NULL) {
			p->next[str[0] - 'a'] = get_newNode();
		}
		p = p->next[str[0] - 'a'];
		++str;
	}
	p->flag = 1;
	return 1;
}

int search(Trie tree, const char *str) {
	TrieNode *p = tree;
	while (str[0] && p) {
		p = p->next[str[0] - 'a'];
		++str;
	}
	return p && p->flag;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Trie tree = get_newNode();
	char str[100];
	while (n--) {
		scanf("%s", str);
		insert(tree, str);
	}
	while (m--) {
		scanf("%s", str);
		printf("%d : %s\n", search(tree, str), str);
	}
	return 0;
}