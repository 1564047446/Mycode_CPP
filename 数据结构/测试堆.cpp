
 

/*************************************************************************
   > File Name: 7.priority_queue.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 二  1/23 15:26:08 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b; b = __temp;  \
}

typedef struct PriorityQueue {
    int *data;
    int n, size;
} PriorityQueue;

PriorityQueue *init(int n) {
    PriorityQueue *p = (PriorityQueue *)malloc(sizeof(PriorityQueue) * 1);
    p->data = (int *)malloc(sizeof(int) * (n + 1));
    p->n = 0;
    p->size = n + 1;
    return p;
}

int push(PriorityQueue *p, int val) {
    if (p->n + 1 >= p->size) {
        return 0;
    }
    p->n += 1;
    p->data[p->n] = val;
    int ind = p->n;
    while (ind > 1 && p->data[ind >> 1] < p->data[ind]) {
        swap(p->data[ind >> 1], p->data[ind]);
        ind = ind >> 1;
    }
    return 1;
}

int empty(PriorityQueue *p) {
    return p->n == 0;
}

int front(PriorityQueue *p) {
    return p->data[1];
}

int pop(PriorityQueue *p) {
    if (empty(p)) {
        return 0;
    }
    //p->data[1] = p->data[p->n];
    swap(p->data[1], p->data[p->n]);
    p->n -= 1;
    int ind = 1;
    while (ind * 2 <= p->n) {
        int ind1 = ind * 2;
        int ind2 = ind * 2 + 1;
        int max_ind = ind;
        if (p->data[ind1] > p->data[max_ind]) max_ind = ind1;
        if (ind2 <= p->n && p->data[ind2] > p->data[max_ind]) max_ind = ind2;
        if (max_ind == ind) break;
        swap(p->data[ind], p->data[max_ind]);
        ind = max_ind;
    }
    return 1;
}

void clear(PriorityQueue *p) {
    if (p == NULL) return ;
    free(p->data);
    free(p);
    return ;
}

int main() {
    int n, a;
    scanf("%d", &n);
    PriorityQueue *p = init(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        printf("push to queue : %d\n", a);
        push(p, a);
        printf("front queue : %d\n", front(p));
    }
    int num = p->n;
    while (!empty(p)) {
        printf("%d ", front(p));
        pop(p);
    }
    printf("\n");
    for (int i = 1; i <= n; i++) {
        printf("sort = %d\n", p->data[i]);
    }
    return 0;
}

