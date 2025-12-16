// left_shift.c
#include <stdio.h>

int main() {
    int a = 5;     // 00000101
    
    // 5 << 1 = 00001010 = 10 (multiply by 2)
    // 5 << 2 = 00010100 = 20 (multiply by 4)
    // 5 << 3 = 00101000 = 40 (multiply by 8)
    
    printf("%d << 1 = %d\n", a, a << 1);
    printf("%d << 2 = %d\n", a, a << 2);
    printf("%d << 3 = %d\n", a, a << 3);
    
    // Left shifting by n is equivalent to multiplying by 2^n
    int num = 7;
    int shift = 3;
    printf("%d * (2^%d) = %d\n", num, shift, num * (1 << shift));
    
    // Practical application: Setting specific bit
    unsigned int flags = 0;
    int bit_position = 3;
    flags = flags | (1 << bit_position);  // Set bit at position 3
    printf("Flags after setting bit %d: %u\n", bit_position, flags);
    
    return 0;
}