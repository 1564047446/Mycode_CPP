#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TrieNode {
	struct TrieNode *next[26];
	int flag;
} TrieNode, *Trie;

typedef struct  doublearrayNode {
	int *base, *check;
	int n;
} doublearrayNode, *DATrie;

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
	return times;
}

int search(Trie tree, const char *str) {
	TrieNode *p = tree;
	while (str[0] && p) {
		p = p->next[str[0] - 'a'];
		++str;
	}
	return p && p->flag;
}

DATrie init_DATrie(int n) {
	doublearrayNode *p = (doublearrayNode *)malloc(sizeof(doublearrayNode));
	p->base = (int *)calloc(n, sizeof(int));
	p->check = (int *)calloc(n, sizeof(int));
	p->n = n;
	p->check[1] = -1;
	return p;
}

void clear_DATtrie(DATrie tree) {
	if (tree == NULL) return ;
	free(tree->base);
	free(tree->check);
	free(tree);
	return ;
}

int transToDATrie(Trie ftree, int index, DATrie ttree) {
	int value = 0, flag = 1, ret = index;
	while (flag) {
		flag = 0;
		++value;
		for (int i = 0; i < 26; i++) {
			if (ftree->next[i] == NULL) continue;
			if (ttree->check[value + i] == 0) continue;
			flag = 1;
			break;
		}
	}
	if (ftree->flag) ttree->check[index] = -ttree->check[index];
	ttree->base[index] = value;
	for (int i = 0; i < 26; ++i) {
		if (ftree->next[i] == NULL) continue;
		ttree->check[value + i] = index;
	}
	for (int i = 0; i < 26; ++i) {
		if (ftree->next[i] == NULL) continue;
		int temp = transToDATrie(ftree->next[i], value + i, ttree);
		ret = ret > temp ? ret : temp;
	}
	return ret;
}

int main() {
	int n, m;
	int node_count = 0;
	scanf("%d%d", &n, &m);
	Trie tree = get_newNode();
	char str[100];
	while (n--) {
		scanf("%s", str);
		node_count += insert(tree, str);
	}
	DATrie da_tree = init_DATrie(2 * node_count);
	int max_node_ind = transToDATrie(tree, 1, da_tree);
	for (int i = 1; i <= max_node_ind; ++i) {
		printf("%3d%3d%3d", i, da_tree->base[i], da_tree->check[i]);
		if (i % 6 == 0) printf("\n");
	}
	printf("\n");
	while (m--) {
		scanf("%s", str);
		//node_count += insert(tree, str);
		printf("%d : %s\n", search(tree, str), str);
	}
	return 0;
}
