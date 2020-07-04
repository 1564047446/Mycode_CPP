#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TrieNode {
	struct TrieNode *next[26];
	struct TrieNode *fail, *father;
	int flag, ind;
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

TrieNode *get_fail_pointer(TrieNode *node, int ind) {
    if (node == NULL) return NULL;
    if (node->fail == NULL) {
        node->fail = get_fail_pointer(node->father, node->ind);
    }
    if (node->fail == NULL) return node;
    TrieNode *p = node->fail, *pre_p = node;
    while (p && p->next[ind] == NULL) {
        if (p->fail == NULL) {
            p->fail = get_fail_pointer(p->father, p->ind);
        }
        pre_p = p;
        p = p->fail;
    }
    if (p) p = p->next[ind];
    else p = pre_p;
    return p;
}

void build_automatain2(Trie tree) {
    if (tree == NULL) return ;
    for (int i = 0; i < 26; i++) {
        if (tree->next[i] == NULL) continue;
        tree->next[i]->fail = get_fail_pointer(tree, i);
        build_automatain2(tree->next[i]);
    }
    printf("build ok!\n");
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
	int n, m;
	scanf("%d%d", &n, &m);
	Trie tree = get_newNode();
	char str[100];
	while (n--) {
		scanf("%s", str);
		insert(tree, str);
	}
	build_automatain2(tree);
	while (m--) {
		scanf("%s", str);
		printf("%d : %s\n", search_automatain(tree, str), str);
	}
	return 0;
}
