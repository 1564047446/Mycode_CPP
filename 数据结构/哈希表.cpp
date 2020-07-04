#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTable {
    int *data, *flag;
    int size;
    int cnt;
} HashTable;

HashTable *init(int n) {
    HashTable *p = (HashTable *)malloc(sizeof(HashTable) * 1);
    p->data = (int *)malloc(sizeof(int) * 2 * n);
    int size = 2 * n / 30 + 1;
    p->flag = (int *)calloc(size, sizeof(int));
    p->size = 2 * n;
    p->cnt = 0;
    return p;
}

int has_value(HashTable *p, int ind) {
    int x = ind / 30, y = ind % 30;
    return p->flag[x] & (1 << y);
}

int set_value(HashTable *p, int val, int ind) {
    int x = ind / 30, y = ind % 30;
    p->data[ind] = val;
    p->flag[x] |= (1 << y);
    p->cnt += 1;
    return 1; 
}

int hash(HashTable *p, int x) {
    return (x % p->size + p->size) % p->size;
}

int hash_conflict(HashTable *p, int *ind, int val) {
    int times = 0, temp_ind = *ind;
    while (has_value(p, temp_ind) && p->data[temp_ind] != val) {
        temp_ind += (++times);
        temp_ind %= p->size;
    }
    *ind = temp_ind;
    return times;
}

int insert(HashTable *p, int val) {
    if (p->cnt * 2 >= p->size) {
        return 0;
    }
    int ind = hash(p, val);
    hash_conflict(p, &ind, val);
    if (p->data[ind] == val) return 0;
    set_value(p, val, ind);   
    return 1;
}

int search(HashTable *p, int val) {
    int ind = hash(p, val);
    hash_conflict(p, &ind, val);
    return has_value(p, ind);
}

void clear(HashTable *p) {
    if (p == NULL) return ;
    free(p->data);
    free(p);
    return ;
}

int main() {
    HashTable *hash_table = init(100);
    int op, val;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1:
                insert(hash_table, val);
                break;
            case 2:
                printf("value = %d\tresult = %d\n", val, search(hash_table, val));
                break;
            default:
                fprintf(stderr, "error\n");
                break;
        }
    }
    return 0;
}

