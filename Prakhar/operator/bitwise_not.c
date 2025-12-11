// bitwise_not.c
#include <stdio.h>

int main() {
    int a = 12;    // 00001100 (assuming 8-bit for simplicity)
    
    // ~12 = 11110011 (assuming 8-bit)
    // In two's complement: -13
    
    int result = ~a;
    
    printf("~%d = %d\n", a, result);
    
    // Important: NOT flips ALL bits
    // For signed integers, this gives two's complement result
    
    unsigned char b = 0b00001111;  // 15
    unsigned char not_b = ~b;      // 11110000 = 240
    
    printf("~%u = %u\n", b, not_b);
    
    // Practical application: Create mask
    unsigned int mask = ~0;  // All bits set to 1
    printf("All ones mask: %u\n", mask);
    
    return 0;
}