#include <stdio.h>

typedef int bool;

const bool TRUE = 1;
const bool FALSE = 0;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

bool is_US(int MM, int DD) {
    return (IN_RANGE(1, MM, 12) && IN_RANGE(1, DD, 31)); 
}

bool is_EU(int DD, int MM) {
    return (IN_RANGE(1, MM, 12) && IN_RANGE(1, DD, 31)); 
}

int main(void) {
    int AA, BB, CCCC;

    scanf("%d/%d/%d", &AA, &BB, &CCCC);

    if (is_US(AA, BB) && is_EU(AA, BB)) {
        puts("either");
    } else {
        if (is_US(AA, BB)) {
            puts("US");
        } else {
            puts("EU");
        }
    }

    return 0;
}