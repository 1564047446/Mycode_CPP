#include <stdio.h>
#include <stdlib.h>

typedef struct UnionSet {
	int n;
	int *father;
	int *size;
} UnionSet;

UnionSet *init(int n) {
	UnionSet *p = (UnionSet *)malloc(sizeof(UnionSet));
	p->n = n;
	p->father = (int *)malloc(sizeof(int) * n);
	p->size = (int *)malloc(sizeof(int) *n);
	for (int i = 0; i < n; i++) {
		p->father[i] = i;
		p->size[i] = 1;
	}
	return p;
}

int find(UnionSet *u, int index) {
	if (u->father[index] == index) return index;
	int father = find(u, u->father[index]);
	u->father[index] = father;
	return father;
}

int merge(UnionSet *u, int a, int b) {
	int father_a = find(u, a);
	int father_b = find(u, b);
	if (father_a == father_b) return 0;
	if (u->size[father_a] > u->size[father_b]) {
		u->father[father_b] = father_a;
		u->size[father_a] += u->size[father_b];
	} else {
		u->father[father_a] = father_b;
		u->size[father_b] += u->size[father_a];	
	}
	return 1;
}

void clear(UnionSet *u) {
	free(u->size);
	free(u->father);
	free(u);
	return ;
}

int main() {
	int op, a, b;
	UnionSet *u = init(100);
	while (~scanf("%d%d%d", &op, &a, &b)) {
		switch (op) {
			case 1: {
				printf("merge %d -> %d : %d\n", a, b, merge(u, a, b));
				break;
			}
			case 2: {
				printf("find %d -> %d : %d\n", a, b, find(u, a) == find(u, b));
				break;
			}
		}
	}
}	