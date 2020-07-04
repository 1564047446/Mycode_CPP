#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

char s[10010];
char cop[10010];
int main() {
    int n;
    scanf("%d", &n);
    s[0] = '1';
    if(n == 1) {
        printf("%c", s[0]);
        return 0;
    }
    for(int i = 1; i < n; i++) {
        int num = 1, m = 0;
        for(int j = 0; j < strlen(s); j++) {
            if(s[j] == s[j + 1]) {
                ++ num;
            }
            else {
                cop[m] = num + '0';
                cop[++ m] = s[j];
                ++ m;
                num = 1;
            }
            /*if(num > 1 && j == strlen(s) - 1) {
                cop[m] = num + '0';
                cop[++ m] = s[j];
            }*/
        }
        strcpy(s, cop);
    }
    for(int i = 0; i < strlen(s); i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}
