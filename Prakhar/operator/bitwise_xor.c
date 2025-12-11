// bitwise_xor.c
#include <stdio.h>

int main() {
    int a = 12;    // 00001100
    int b = 25;    // 00011001
    
    // 12 = 00001100
    // 25 = 00011001
    // ^  = 00010101 = 21 (decimal)
    
    int result = a ^ b;
    
    printf("%d ^ %d = %d\n", a, b, result);
    
    // XOR properties:
    // a ^ a = 0
    // a ^ 0 = a
    // a ^ b ^ b = a
    
    // Practical application: Toggle bits
    unsigned char mask = 0b00000111;  // Binary: 00000111 (7)
    unsigned char toggle = 0b00000101; // Binary: 00000101 (5)
    
    mask = mask ^ toggle;  // Toggle specific bits
    printf("Mask after toggle: %d\n", mask);
    
    // Another application: Swap without temporary variable
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);
    
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    
    printf("After swap: x = %d, y = %d\n", x, y);
    
    return 0;
}