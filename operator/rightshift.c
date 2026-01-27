// right_shift.c
#include <stdio.h>

int main() {
    int a = 40;    // 00101000
    
    // 40 >> 1 = 00010100 = 20 (divide by 2)
    // 40 >> 2 = 00001010 = 10 (divide by 4)
    // 40 >> 3 = 00000101 = 5 (divide by 8)
    
    printf("%d >> 1 = %d\n", a, a >> 1);
    printf("%d >> 2 = %d\n", a, a >> 2);
    printf("%d >> 3 = %d\n", a, a >> 3);
    
    // Right shifting by n is equivalent to dividing by 2^n
    int num = 100;
    int shift = 2;
    printf("%d / (2^%d) = %d\n", num, shift, num >> shift);
    
    // Note: For signed integers, >> is arithmetic shift (sign bit is preserved)
    // For unsigned integers, >> is logical shift (0 is shifted in)
    
    int signed_num = -8;     // 11111000 (in 8-bit two's complement)
    unsigned int unsigned_num = 8;
    
    printf("Signed -8 >> 1 = %d\n", signed_num >> 1);
    printf("Unsigned 8 >> 1 = %u\n", unsigned_num >> 1);
    
    // Practical application: Extracting specific bits
    unsigned int value = 0b11011010;  // 218
    unsigned int extracted = (value >> 3) & 0b111;  // Extract bits 3-5
    printf("Extracted bits 3-5: %u\n", extracted);
    
    return 0;
}