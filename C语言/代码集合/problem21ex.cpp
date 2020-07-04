#include <stdio.h>
#include <stdint.h>
 
#define MAX_N 10000
 
int32_t isPrime[MAX_N + 5] = {0};
int32_t prime[MAX_N] = {0};
int32_t d[MAX_N + 5]  = {0};
 
int32_t main() {
    d[1] = 0;
    for (int32_t i = 2; i <= MAX_N; i++) {
        if (!isPrime[i]) { 
            isPrime[i] = i;
            d[i] = i + 1;
            prime[++prime[0]] = i;
        }
        for (int32_t j = 1; j <= prime[0] && prime[j] * i <= MAX_N; j++) {
            if (i % prime[j] == 0) {
                isPrime[i * prime[j]] = isPrime[i] * prime[j];
                d[i * prime[j]] = d[i] * 
                    (isPrime[i] * prime[j] * prime[j] - 1) / 
                    (isPrime[i] * prime[j] - 1);
                break;
            } else {
                isPrime[i * prime[j]] = prime[j];
                d[i * prime[j]] = d[prime[j]] * d[i];
            }
        }
    }
    for (int32_t i = 0; i <= MAX_N; i++) {
        d[i] -= i;
    }
    int32_t sum = 0;
    for (int32_t i = 0; i <= MAX_N; i++) {
        if (d[i] <= MAX_N && d[i] != i && d[d[i]] == i) {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}
