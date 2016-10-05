#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int t;
    scanf("%d", &t);

    for(int a0 = 0; a0 < t; a0++) {
        long b, w;
        scanf("%ld %ld", &b, &w);

        long x, y, z;
        scanf("%ld %ld %ld", &x, &y, &z);

        long bigger, smaller;

        if (x > y) {
            bigger = x;
            smaller = y;
        } else {
            bigger = y;
            smaller = x;
        }

        if (smaller + z < bigger)
            bigger = smaller + z;

        long total;

        if (smaller == x) {
            total = (smaller * b) + (bigger * w);
        } else {
            total = (smaller * w) + (bigger * b);
        }

        printf("%ld\n", total);
    }

    return 0;
}
