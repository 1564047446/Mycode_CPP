/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月07日 星期二 18时15分17秒
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "ss.h"
 
int main() {
    int64_t ans = 1, zero = 0, maxN = 0;
    for (int32_t i = 0; i < 1000; ++i) {
        if (s[i] != '0') {
            ans *= s[i] - '0';
        } else {
            ++zero;
        }
        if (i >= 13) {
            if (s[i - 13] != '0') {
                ans /= s[i - 13] - '0';
            } else {
                --zero;
            }
        }
        if (zero == 0 && ans > maxN) maxN = ans;
    }
    printf("%"PRId64"\n",maxN);
    return 0;
}
