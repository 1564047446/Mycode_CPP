/*************************************************************************
	> File Name: 简单队列.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月16日 星期二 14时45分00秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//#define defvalue(n, defal) ((#n[0] ? n : defval))
//#define init(n) __init(defvalue(n, 10))

typedef struct Queue {
    int length, head, tail;
    int *data;
} Queue;

Queue *init(int);
int push(Queue *, int);
int pop(Queue *);
int empty(Queue *);
int expand(Queue *);
void clear(Queue *);


Queue *init(int length = 10) {
    Queue *p = (Queue *)malloc(sizeof(Queue));
    p->data = (int *)malloc(sizeof(int) * length);
    p->head = 0;
    p->tail = 0;
    p->length = length;
    return p;
}

void clear(Queue *p) {
    if (p == NULL) return ;
    free(p->data);
    free(p);
}

int push(Queue *q, int value) {
    if (q->tail >= q->length) {
        if (!expand(q)) return 0;
    }
    q->data[q->tail] = value;
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
    int *temp_data = (int *)realloc(q->data, sizeof(int) * q->length * 2);
    if (temp_data == NULL) return 0;
    q->data = temp_data;
    q->length *= 2;
    return 1;
}

void output(Queue *q) {
    for (int i = q->head; i < q->tail; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue *q = init();
    int op, value;
    while (~scanf("%d", &op)) {
        switch (op) {
            case 1: {
                scanf("%d", &value);
                //push(q, value);
                printf("%d\n", push(q, value));
                break;
            }
            case 2: {
                printf("%d\n", pop(q));
                break;
            }
            default : {
                break;
            }
        }
        output(q);
    }
    clear(q);
    return 0;
}
