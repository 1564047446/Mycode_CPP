/*************************************************************************
	> File Name: test0.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月14日 星期四 13时25分55秒
 ************************************************************************/

#include <stdio.h>

int ans[100];
//int sum = 0;

int dfs(int cur, int n, int sum) {
    if (cur == n) sum++;
    else {
        for (int i = 0; i < n; i++) {
            ans[cur] = i;
            int flag = 1;
            for (int j = 0; j < cur; j++) {
                if (ans[j] == ans[cur] || j - ans[j] == cur - ans[cur] || j + ans[j] == cur + ans[cur]) {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            dfs(cur + 1, n, sum);
        }
    }
    return sum;
}



int main() {
    int sum = dfs(0, 8, 0);
    printf("%d\n", sum);
    return 0;
}
