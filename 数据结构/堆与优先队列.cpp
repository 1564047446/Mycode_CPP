#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {  \
    __typeof(a) __temp = a;  \
    a = b;  \
    b = __temp;  \
}

typedef struct PriorityQueue {
    int *data;
    int n, size;
} PriorityQueue;

PriorityQueue *init(int n) {
    PriorityQueue *p = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    p->data = (int *)malloc(sizeof(int) * (n + 1));
    p->n = 0;
    p->size = n + 1;
    return p;
}

int push(PriorityQueue *p, int value) {
    if (p->n + 1 >= p->size) return 0;
    p->data[++p->n] = value;
    int index = p->n;
    while (index > 1 && p->data[index >> 1] < p->data[index]) {
        swap(p->data[index >> 1], p->data[index]);
        index >>= 1;
    }
    return 1;
}

int pop(PriorityQueue *p) {
    swap(p->data[1], p->data[p->n]);
    int index = 1;
    --p->n;
    while (index * 2 <= p->n) {
        int index1 = 2 * index, index2 = 2 * index + 1;
        int maxn = index;
        if (p->data[index1] > p->data[maxn]) maxn = index1;
        if (index2 <= p->n && p->data[index2] > p->data[maxn]) maxn = index2;
        if (maxn == index) break;
        swap(p->data[index], p->data[maxn]);
        index = maxn;
    }
    return 1;
}

int front(PriorityQueue *p) {
    return p->data[1];
}

int main() {

    int n;
    scanf("%d", &n);
    PriorityQueue *p = init(n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        push(p, k);
        printf("The front is = %d\n", front(p));
    }
    int num = p->n;
    while (p->n != 0) {
        printf("top = %d\n", front(p));
        pop(p);
    }
    printf("sort :");
    for (int i = 1; i <= num; i++) {
        printf("%d ", p->data[i]);
    }
    printf("\n");

    return 0;
}