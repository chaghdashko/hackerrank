#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int lonelyinteger(int size, int* a) {
    if (size == 1) {
        return a[0];
    }

    int b[101];
    memset(b, 0, 101 * sizeof(int));

    int i;
    for (i = 0; i < size; i++) {
        b[a[i]]++;
    }

    /*for (i = 0; i < 101; i++) {
        printf("%d ", b[i]);
    }

    printf("\n");
    */

    int res;
    for (i = 0; i < 101; i++) {
        if (b[i] == 1) {
            res = i;
            break;
        }
    }

    return res;
}

int main() {

    int size, i;
    scanf("%d", &size);
    int a[size];

    for(i = 0; i < size; i++) {
        int item;
        scanf("%d", &item);

        a[i] = item;
    }

    printf("%d", lonelyinteger(size, a));

    return 0;
}
