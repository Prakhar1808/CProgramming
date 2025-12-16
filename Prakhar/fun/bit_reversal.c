// bit_reversal.c
#include <stdio.h>

// Reverse bits of an 8-bit number
unsigned char reverseBits8(unsigned char num) {
    unsigned char result = 0;
    
    for(int i = 0; i < 8; i++) {
        if(num & (1 << i)) {
            result |= (1 << (7 - i));
        }
    }
    
    return result;
}

// More efficient method using lookup table (pre-calculated)
unsigned char reverseBits8Lookup(unsigned char num) {
    // Lookup table for 8-bit reversal
    static const unsigned char lookup[256] = {
        0x00, 0x80, 0x40, 0xC0, 0x20, 0xA0, 0x60, 0xE0,
        0x10, 0x90, 0x50, 0xD0, 0x30, 0xB0, 0x70, 0xF0,
        // ... (complete table would have 256 entries)
    };
    return lookup[num];
}

int main() {
    unsigned char numbers[] = {0x01, 0x02, 0x03, 0x0F, 0xAA, 0x55, 0x80, 0xFF};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    
    printf("Number\tBinary\t\tReversed\tReversed Binary\n");
    printf("--------------------------------------------------------\n");
    
    for(int i = 0; i < size; i++) {
        unsigned char reversed = reverseBits8(numbers[i]);
        
        printf("0x%02X\t", numbers[i]);
        for(int j = 7; j >= 0; j--) printf("%d", (numbers[i] >> j) & 1);
        printf("\t0x%02X\t", reversed);
        for(int j = 7; j >= 0; j--) printf("%d", (reversed >> j) & 1);
        printf("\n");
    }
    
    return 0;
}