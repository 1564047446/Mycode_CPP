/*************************************************************************
	> File Name: p185-5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月14日 星期四 12时28分39秒
 ************************************************************************/

#include <stdio.h>

int ans[100];
int sum = 0;


int dfs(int cur, int n) {
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
                //if (flag) dfs(cur + 1, n);
            }
            if (flag) dfs(cur + 1, n);
        }

    }
    
    return sum;
}



int main() {

    dfs(0, 8);
    printf("%d\n", sum);
    return 0;
}
