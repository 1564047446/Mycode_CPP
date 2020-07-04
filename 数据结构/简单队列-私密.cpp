/*************************************************************************
	> File Name: 简单队列.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月16日 星期二 14时45分00秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define defvalue(n, defal) ((#n[0] ? n : defval))
//#define init(n) __init(defvalue(n, 10))
#define DEFAULTARG(n, x) (#n[0] ? n + 0 : x)
#define init(T, n) (__init(sizeof(T), 10))
#define push(q, value) ((__push(q, &value)))
#define front(q, T) ((*(T *)__front(q)))

typedef struct Queue {
    int length, head, tail;
    int data_size;
    void *data;
} Queue;

Queue *__init(int, int);
int __push(Queue *, void *);
int pop(Queue *);
int empty(Queue *);
int expand(Queue *);
void *__front(Queue *);
void clear(Queue *);


Queue *__init(int data_size, int length = 10) {
    Queue *p = (Queue *)malloc(sizeof(Queue));
    p->data = malloc(sizeof(data_size) * length);
    p->head = 0;
    p->tail = 0;
    p->length = length;
    p->data_size = data_size;
    return p;
}
void clear(Queue *p) {
    if (p == NULL) return ;
    free(p->data);
    free(p);
}

int __push(Queue *q, void *value) {
    if (q->tail >= q->length) {
        if (!expand(q)) return 0;
    }
    char *data = (char *)(q->data);
    memcpy(data + q->tail * q->data_size, value, q->data_size);
    q->tail++;
    return 1;
}

int pop(Queue *q) {
    if (empty(q)) return 0;
    q->head++;
    return 1;
}

int empty(Queue *q) {
    return q->head == q->tail;
}

int expand(Queue *q) {
    void *temp_data = realloc(q->data, q->data_size * q->length * 2);
    if (temp_data == NULL) return 0;
    q->data = temp_data;
    q->length *= 2;
    return 1;
}

void *__front(Queue *q) {
    //if (empty(q)) return ;
    return (char *)(q->data) + q->head * q->data_size;
}


int main() {
    Queue *q = init(int, 10);
    int op, value;
    while (~scanf("%d", &op)) {
        switch (op) {
            case 1:
                scanf("%d", &value);
                push(q, value);
                break;
            case 2 :
                pop(q);
                break;
            default : break;

        }
        int temp = front(q, int);
        printf("%d \n", temp);
    }
}
