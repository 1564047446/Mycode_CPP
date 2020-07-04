/*************************************************************************
	> File Name: p240-6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月20日 星期三 13时50分18秒
 ************************************************************************/

#include<iostream>
using namespace std;


const int INF = 10000000;
int n, cc = 0, bestc = INF;
int **g;
int *x, *bestx;

void travel(int t) {
	if (t == n) {
		if (g[x[t - 1]][x[t]] != INF && g[x[t]][1] != INF &&
			(cc + g[x[t - 1]][x[t]] + g[x[t]][1] < bestc || bestc == INF)) {
			for (int i = 0; i < n + 1; i++)
				bestx[i] = x[i];
			bestc = cc + g[x[t - 1]][x[t]] + g[x[t]][1];
		}
		return;
	}

	for (int i = t; i < n; i++) {
		if (g[x[t - 1]][x[i]] != INF && (cc + g[x[t - 1]][x[i]] < bestc
			|| bestc == INF)) {
			swap(x[i], x[t]);
			cc += g[x[t - 1]][x[t]];
			travel(t + 1);
			cc -= g[x[t - 1]][x[t]];
			swap(x[i], x[t]);
		}
	}
}

void output() {
	cout << bestc << endl;
	cout << bestx[1];
	for (int i = 2; i < n + 1; i++)
		cout << " " << bestx[i];
	cout << " " << bestx[1] << endl;
}

int main() {

	n = 4;
	g = new int*[n + 1];
	x = new int[n + 1];
	bestx = new int[n + 1];

	for (int i = 0; i < n + 1; i++) {
		g[i] = new int[n + 1];
		x[i] = i;

		for (int j = 0; j < n + 1; j++)
			g[i][j] = INF;
	}

	g[1][2] = g[2][1] = 30;
	g[1][3] = g[3][1] = 6;
	g[1][4] = g[4][1] = 4;

	g[2][3] = g[3][2] = 5;
	g[2][4] = g[4][2] = 10;

	g[3][4] = g[4][3] = 20;

	travel(2);
	output();

	return 0;
}
