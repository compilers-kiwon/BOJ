#include <stdio.h>

#define NUM_OF_BITS (4)
#define NUM_OF_DATA (3)

int decode_number(int n) {
    const int mask = 0x0000000F;
    return (n&mask);
}

int main(void) {
    int decoded = 0;
    int data[NUM_OF_DATA];

    for (int i = 0; i < NUM_OF_DATA; i++) {
        scanf("%d", &data[i]);
    }

    for (int i = 0; i < NUM_OF_DATA; i++) {
        decoded = (decoded<<NUM_OF_BITS) + decode_number(data[i]);
    }

    printf("%04d\n", decoded);
    return 0;
}