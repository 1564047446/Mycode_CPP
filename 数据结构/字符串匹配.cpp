#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int brute_force(const char *str, const char *target) {
    int len1 = strlen(str);
    int len2 = strlen(target);
    for (int i = 0; i <= len1 - len2; i++) {
        int flag = 1;
        for (int j = 0; j < len2 && flag; j++) {
            flag = (str[i + j] == target[j]);
        }
        if (flag) return 1;
    }
    return 0;
}

int kmp(const char *str, const char *target) {
    int len1 = strlen(str);
    int len2 = strlen(target);
    int *next = (int *)malloc(sizeof(int) * len2);
    next[0] = -1;
    int i, j = -1;
    for (i = 1; i < len2; i++) {
        while (j != -1 && target[j + 1] != target[i]) {
            j = next[j];
        }
        if (target[j + 1] == target[i]) {
            j += 1;
        }
        next[i] = j;
    }
    i = 0, j = -1;
    while (i < len1) {
        if (str[i] == target[j + 1]) j += 1, i += 1;
        else {
            while (str[i] != target[j + 1] && j != -1) {
                j = next[j];
            }
            if (str[i] != target[j + 1]) {
                i += 1;
            }
        }
        if (j + 1 == len2) break;
    }
    free(next);
    return (j + 1 == len2);
}

int sunday(const char *str, const char *target) {
    int len1 = strlen(str);
    int len2 = strlen(target);
    int ch_ind[128] = {0};
    for (int i = 0; i < 128; i++) {
        ch_ind[i] = len2 + 1; // important
    }
    for (int i = 0; i < len2; i++) {
        ch_ind[target[i]] = len2 - i;
    }
    for (int i = 0; i < len1;) {
        int j = 0;
        for (; j < len2 && str[i + j] == target[j]; j++);
        if (j == len2) return 1; 
        i += ch_ind[str[i + len2]];
    }
    return 0;
}

int shift_and(const char *str, const char *target) {
    int ch_code[128] = {0};
    int len2 = 0;
    for (len2 = 0; target[len2]; len2++) {
        ch_code[target[len2]] |= (1 << len2);
    }
    int p = 0, limit = ((1 << (len2 - 1)) - 1);
    for (int i = 0; str[i]; i++) {
        p = (p << 1 | 1) & ch_code[str[i]];
        if (p > limit) return 1;
    }
    return 0;
}

int shift_and2(const char *str, const char *target) {
	int ch_code[128][10000];
	int len2 = 0;
	for (len2 = 0; target[len2]; len2++) {
		ch_code[target[len2]][len2] |= 1;
	}
	int p[1000] = {0}, k = 0;
	for (int i = 0; str[i]; i++) {
		for (int j = k; j >= 1; j--) {
			p[j] = p[j - 1];
		}
		p[0] = 1;
		for (int j = 0; j < k; j++) {
			p[j] &= ch_code[str[i]][j];
			printf("p[j] = %d\n", p[j]);
		}
		++k;
		if (p[len2 - 1] == 1) return 1;
	}
	for (int i = 0; i < 100; i++) {
			printf("p[%d] = %d\n", i, p[i]);
	}
	return 0;
}


#define TEST(func) { \
    printf("%s = %d\n", #func, func); \
}

int main() {
    char str1[100], str2[100];
    while (~scanf("%s%s", str1, str2)) {
        TEST(brute_force(str1, str2));
        TEST(kmp(str1, str2));
        TEST(sunday(str1, str2));
        TEST(shift_and(str1, str2));
        TEST(shift_and2(str1, str2));
    }
    return 0;
}

