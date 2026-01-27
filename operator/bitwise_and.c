// bitwise_and.c
#include <stdio.h>

int main() {
    int a = 12;    // 1100 in binary
    int b = 25;    // 11001 in binary (actually 11001, but let's consider 8-bit: 00011001)
    
    // 12 = 00001100
    // 25 = 00011001
    // &  = 00001000 = 8 (decimal)
    
    int result = a & b;
    
    printf("%d & %d = %d\n", a, b, result);
    printf("Binary: %08b & %08b = %08b\n", a, b, result);
    
    // Practical application: Check if a number is even
    int num = 15;
    if((num & 1) == 0) {
        printf("%d is even\n", num);
    } else {
        printf("%d is odd\n", num);
    }
    
    return 0;
}