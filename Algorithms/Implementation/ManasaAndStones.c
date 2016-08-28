#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int T, i, numStones, a, b, initVal, sum, diff;
    int stones[1000];
    scanf("%d\n", &T);

    for (i = 0; i < T; i++) {
        scanf("%d\n", &numStones);
        scanf("%d\n", &a);
        scanf("%d\n", &b);

        if (a == b) {
            sum = (numStones - 1) * a;
            printf("%d", sum);
        } else {
            initVal = (a < b) ? a : b;
            diff = (a < b) ? b - a : a - b;

            memset(stones, 0, 1000);

            int j;
            for (j = 0; j < numStones - 1; j++) {
                stones[j] = initVal;
            }

            sum = 0;
            for (j = 0; j < numStones - 1; j++) {
                sum += stones[j];
            }

            printf("%d ", sum);

            for (j = 0; j < numStones - 1; j++) {
                sum += diff;
                printf("%d ", sum);
            }
        }

        printf("\n");
    }

    return 0;
}
