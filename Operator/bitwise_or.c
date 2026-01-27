// bitwise_or.c
#include <stdio.h>

int main() {
    int a = 12;    // 00001100
    int b = 25;    // 00011001
    
    // 12 = 00001100
    // 25 = 00011001
    // |  = 00011101 = 29 (decimal)
    
    int result = a | b;
    
    printf("%d | %d = %d\n", a, b, result);
    
    // Practical application: Set specific bits
    unsigned int flags = 0;
    unsigned int READ = 1;    // 00000001
    unsigned int WRITE = 2;   // 00000010
    unsigned int EXECUTE = 4; // 00000100
    
    // Set READ and WRITE permissions
    flags = flags | READ | WRITE;
    printf("Flags after setting READ and WRITE: %u\n", flags);
    
    return 0;
}