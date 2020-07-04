#include <stdio.h>
#include "any_stack2.h"

void quick_sort(int *a, int left, int right) {

	//0
	if (left >= right) return ;  //100
	int l = left, r = right, base = a[left];
	while (l < r) {  //1
		while (l < r && base > a[r]) --r;
		if (l < r) a[l++] = a[r];
		while (l < r && base < a[l]) ++l;
		if (l < r) a[r--] = a[l];
	}
	a[l] = base;
	quick_sort(a, left, l - 1); // 2
	quick_sort(a, l + 1, right); // 3
	return ; // 100
}

typedef struct quick_sort_arg {
	int *arr, l, r, status;
	int x;
} quick_sort_arg;

void init(quick_sort_arg *q, int *arr, int left, int right, int x) {
	q->status = 0;
	q->arr = arr;
	q->l = left, q->r = right;
	q->x = x;
}

int __quick_sort(int *a, int left, int right) {
	int l = left, r = right, base = a[left];
	while (l < r) {
		while (l < r && base <= a[r]) --r;
		a[l] = a[r];
		while (l < r && base >= a[l]) ++l;
		a[r] = a[l];
	}
	a[l] = base;
	return l;
}

void quick_sort(int *arr, int n) {
    Stack *s = init_stack(10000, quick_sort_arg);
    quick_sort_arg qsa;
    init(&qsa, arr, 0, n - 1, 0);
    push_stack(s, &qsa);
    while (!empty_stack(s)) {
        quick_sort_arg *tqsa = top_stack(s, quick_sort_arg);
        switch (tqsa->status) {
            case 0:
                if (tqsa->r <= tqsa->l) {
                    tqsa->status = 4;
                } else {
                    tqsa->status = 1;
                }
                break;
            case 1:
                tqsa->x = __quick_sort(tqsa->arr, tqsa->l, tqsa->r);
                tqsa->status = 2;
                break;
            case 2:
                init(&qsa, arr, tqsa->l, tqsa->x - 1, 0);
                push_stack(s, &qsa);
                tqsa->status = 3;
                break;
            case 3:
                init(&qsa, arr, tqsa->x + 1, tqsa->r, 0);
                push_stack(s, &qsa);
                tqsa->status = 4;
                break;
            case 4:
                pop_stack(s);
                break;
            default:
                printf("ERROR\n");
                break;
        }
    }
    return ;
}

int main() {
	int a[1000];
	int n;
    scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	quick_sort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}
