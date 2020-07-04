#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

const int INF = 0x3f3f3f3f;

typedef struct Graph {
    int n;
    int visited[MAX_N], dist[MAX_N];
    int mat[MAX_N][MAX_N];
}Graph;

void init(Graph *g, int input_n) {
    g->n = input_n;
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            g->mat[i][j] = INF;
        }
    }
}

void insert(Graph *g, int x, int y, int weight) {
    g->mat[x][y] = weight;
    g->mat[y][x] = weight;
}

int prim(Graph *g, int v) {
    for (int i = 0; i < g->n; i++) {
        g->dist[i] = INF;
        g->visited[i] = 0;
    }
    int sum = 0;
    g->dist[v] = 0;
    for (int i = 0; i < g->n; i++) {
        int min_index, min_dist = INF;
        for (int j = 0; j < g->n; j++) {
            if (!g->visited[j] && g->dist[j] < min_dist) {
                min_dist = g->dist[j];
                min_index = j;
            }
        }
        sum += min_dist;
        g->visited[min_index] = 1;
        printf("%d\n", min_dist);
        for (int j = 0; j < g->n; j++) {
            if (g->visited[j] == 0 && g->mat[min_index][j] < g->dist[j]) {
                g->dist[j] = g->mat[min_index][j];
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}

int main() {
    int n, m;
    Graph *g = (Graph *)malloc(sizeof(Graph));
    scanf("%d%d", &n, &m);
    init(g, n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        insert(g, a, b, c);
    }
    int k;
    scanf("%d", &k);
    prim(g, k);
    return 0;
}