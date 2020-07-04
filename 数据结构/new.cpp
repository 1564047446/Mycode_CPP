#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TrieNode {
	struct TrieNode *next[26];
	struct TrieNode *fail;
	int flag;
} TrieNode, *Trie;

struct TrieNode *get_newNode() {
	TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode) * 1);
	p->flag = 0;
	p->fail = NULL;
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
	int times = 0;
	while (str[0]) {
		if (p->next[str[0] - 'a'] == NULL) {
			p->next[str[0] - 'a'] = get_newNode();
			++times;
		}
		p = p->next[str[0] - 'a'];
		++str;
	}
	p->flag = 1;
	return times;;
}

int search(Trie tree, const char *str) {
	TrieNode *p = tree;
	while (str[0] && p) {
		p = p->next[str[0] - 'a'];
		++str;
	}
	return p && p->flag;
}

void build_automatain(Trie tree, int n) {
	if (tree == NULL) return ;
	tree->fail = NULL;
	TrieNode **queue = (TrieNode **)malloc(sizeof(TrieNode *) * (n + 5));
	int head = 0, tail = 0;
	queue[tail++] = tree;
	while (head < tail) {
		TrieNode *p = queue[head++], *q;
		for (int i = 0; i < 26; ++i) {
			if (p->next[i] == NULL) continue;
			q = p->fail;
			while (q != NULL && q->next[i] == NULL) {
				q = q->fail;
			}
			if (q == NULL) q = tree;
			else q = q->next[i];
			p->next[i]->fail = q;
			queue[tail++] = p->next[i];
		}
	}
	printf("builde ok!\n");
	fflush(stdout);
	free(queue);
	return ;
}

int search_automatain(Trie ac_tree, char *str) {
	int ret = 0;
	TrieNode *p = ac_tree, *q;
	while (str[0]) {
		while (p != NULL && p->next[str[0] - 'a'] == NULL) p = p->fail;
		if (p) p = p->next[str[0] - 'a'];
		else p = ac_tree;
		q = p;
		while (q) ret += q->flag, q = q->fail;
		str++;
	}
	return ret;
}

int main() {
	int n, m, node_count = 0;
	scanf("%d%d", &n, &m);
	Trie tree = get_newNode();
	char str[100];
	while (n--) {
		scanf("%s", str);
		node_count += insert(tree, str);
	}
	build_automatain(tree, node_count);
	while (m--) {
		scanf("%s", str);
		printf("%d : %s\n", search_automatain(tree, str), str);
	}
	return 0;
}
