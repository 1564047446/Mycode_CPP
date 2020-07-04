/*************************************************************************
	> File Name: 简单栈.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月16日 星期二 17时35分11秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Static {
    int top, size;
    int *data;
}Stack;

Stack *init(int);
void clear(Stack *);
int empty(Stack *);
int push(Stack *, int);
int pop(Stack *);
int top(Stack *);


int main() {
    Stack *s = init(10);
    int op, value;
    while (~scanf("%d", &value)) {
        push(s, value);
        printf("value is %d\n", value);
    }
    while (!empty(s)) {
        printf("%d\n", top(s));
        pop(s);
    }
    return 0;
}


Stack *init(int n = 10) {
    Stack *s = (Static *)malloc(sizeof(Stack));
    s->top = -1;
    s->size = n;
    s->data = (int *)malloc(sizeof(int *) * n);
    return s;
}

void clear(Stack *s) {
    if (s== NULL) return ;
    free(s->data);
    free(s);
}

int empty(Stack *s) {
    return s->top == -1;
}

int push(Stack *s, int value) {
    if (s->top == s->size - 1) return 0;
    s->data[++s->top] = value;
    return 1;
}


int pop(Static *s) {
    if (s->top == -1) return 0;
    s->top--;
    return 1;
}

int top(Static *s) {
    if (s->top == -1) return 0;
    return s->data[s->top];
}
