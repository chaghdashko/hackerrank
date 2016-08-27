#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long T, i, cuts, vcuts, hcuts, pieces;
    scanf("%ld\n", &T);

    for (i = 0; i < T; i++) {
        scanf("%ld\n", &cuts);

        if (cuts % 2 == 0) {
            vcuts = cuts / 2;
            hcuts = vcuts;
        } else {
            vcuts = cuts / 2;
            hcuts = vcuts + 1;
        }

        pieces = vcuts * hcuts;
        printf("%ld\n", pieces);
    }

    return 0;
}
