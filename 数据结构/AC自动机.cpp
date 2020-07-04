#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 26;
const char BASE = 'a';
const int MAX_SIZE = 200010;
const int MAX_LEN = 200000;


typedef struct TrieNode {
    int count;
    struct TrieNode** childs;
    struct TrieNode* fail;
} TrieNode, *Trie;

TrieNode* new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->fail = NULL;
    p->count = 0;
    return p;
}

void clear() {
    
}

void insert(Trie trie, char *buffer) {
    TrieNode *p = trie;
    for (int i = 0; i < strlen(buffer); i++) {
        if (p->childs[buffer[i] - BASE] == NULL) {
            p->childs[buffer[i] - BASE] = new_node();
        }
        p = p->childs[buffer[i] - BASE];
    }
    p->count++;
}

void build_automaton(Trie tree) {
    TrieNode *queue[MAX_SIZE];
    tree->fail = NULL;
    int head = 0, tail = 0;
    queue[tail++] = tree;
    while (head < tail) {
        TrieNode *p = queue[head++], *q;
        for (int i = 0; i < 26; i++) {
            if (p->childs[i] == NULL) continue;
            q = p->fail;
            while (q != NULL && q->childs[i] == NULL) q = q->fail;
            if (q == NULL) q = tree;
            else q = q->childs[i];
            p->childs[i]->fail = q;
            queue[tail++] = p->childs[i];
        }
    }
}

int match_count(Trie ac_tree, const char *str) {
    TrieNode *p = ac_tree, *q;
    int cnt = 0;
    while (str[0]) {
        while (p != NULL && p->childs[str[0] - 'a'] == NULL) p = p->fail;
        if (p == NULL) p = ac_tree;
        else p = p->childs[str[0] - 'a'];
        q = p;
        while (q) cnt += q->count, q = q->fail;
        ++str;
    }
    return cnt;
}

int main() {
    Trie root = new_node();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char pattern[100];
        scanf("%s", pattern);
        insert(root, pattern);
    }
    build_automaton(root);
    char str_buffer[MAX_LEN];
    scanf("%s", str_buffer);
    printf("%d\n", match_count(root, str_buffer));
    return 0;
}