#include <stdio.h>
#include <inttypes.h>
 
int32_t fib[3][1005] = {0};
 
int32_t main() {
    fib[1][0] = fib[1][1] = 1;
    fib[2][0] = fib[2][1] = 1;
    int32_t many = 2, ind1, ind2, ind3;
    while (fib[many % 3][0] < 1000) {
        ++many;
        ind1 = (many - 2) % 3;
        ind2 = (many - 1) % 3;
        ind3 = many % 3;
        for (int32_t i = 1; i <= fib[ind2][0]; i++)
            fib[ind3][i] = fib[ind1][i]+fib[ind2][i];
        fib[ind3][0] = fib[ind2][0];
        for (int32_t i = 1; i <= fib[ind3][0]; i++) {
            if (fib[ind3][i] >= 10) {
                fib[ind3][i + 1] += fib[ind3][i] / 10;
                fib[ind3][i] %= 10;
                if (i == fib[ind3][0]) ++fib[ind3][0];
            }
        }
    }
    printf("%d\n",many);
    return 0;
}
