/*************************************************************************
	> File Name: problem17.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 22时05分40秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
 
int32_t GetLetterNum(int32_t i) {
    static int32_t LN20[20] = {
        0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
        6, 6, 8, 8, 7, 7, 9, 8, 8
    };
    static int32_t LN_shi[10] = {
        0, 0, 6, 6, 5, 5, 5, 7, 6, 6
    };
    int32_t temp;
    if (i < 20) {
        return LN20[i];
    } else if (i < 100) {
        return LN_shi[i / 10] + LN20[i % 10];
    } else if (i < 1000) {
        temp = GetLetterNum(i % 100);
        if (temp != 0) temp += 3;
        return temp + LN20[i / 100] + 7;
    } else if (i == 1000) {
        return 11;
    } else {
        return 0;
    }
    return 0;
}
 
int32_t main() {
    int32_t sum = 0;
    for (int32_t i = 1; i<= 1000; ++i) {
        sum += GetLetterNum(i);
    }
    printf("%d\n", sum);
    return 0;
}
 
