#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int maxXor(int l, int r) {
    int max = 0;
    int a, b, res;
    
    for (a = l; a <= r; a++) {
        for (b = a; b <= r; b++) {
            res = a ^ b;
            
            if (res > max)
                max = res;
        }
    }

    return max;
}

int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}
