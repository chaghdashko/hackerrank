#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long N, M;
    scanf("%ld %ld\n", &N, &M);
    
    long sum = 0;
    
    long i;
    for (i = 0; i < M; i++) {
        long a, b, k;
        scanf("%ld %ld %ld\n", &a, &b, &k);
        sum += (b - a + 1) * k;
    }
    
    printf("%ld\n", (sum / N));
    return 0;
}
