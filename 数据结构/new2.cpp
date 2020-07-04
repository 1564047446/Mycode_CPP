#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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
    return ;
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

int main() {


    return 0;
}