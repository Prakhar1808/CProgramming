// compound_bitwise.c
#include <stdio.h>

int main() {
    unsigned int a = 5;
    
    a &= 3;  // a = a & 3
    printf("After &= 3: %u\n", a);
    
    a = 5;
    a |= 3;  // a = a | 3
    printf("After |= 3: %u\n", a);
    
    a = 5;
    a ^= 3;  // a = a ^ 3
    printf("After ^= 3: %u\n", a);
    
    a = 5;
    a <<= 2;  // a = a << 2
    printf("After <<= 2: %u\n", a);
    
    a = 20;
    a >>= 2;  // a = a >> 2
    printf("After >>= 2: %u\n", a);
    
    return 0;
}