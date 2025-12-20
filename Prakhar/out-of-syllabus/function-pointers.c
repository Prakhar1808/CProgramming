// function_pointers.c - YOUR NEXT LEVEL
#include <stdio.h>

// Regular functions
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    // Declare function pointer
    // Syntax: return_type (*pointer_name)(parameter_types)
    int (*operation)(int, int);
    
    // Point to add function
    operation = &add;  // & is optional
    printf("Addition: %d\n", operation(5, 3));
    
    // Point to multiply function
    operation = multiply;
    printf("Multiplication: %d\n", operation(5, 3));
    
    return 0;
}