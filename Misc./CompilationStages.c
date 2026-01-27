/* 
 * program1_1_compilation_stages.c
 * Demonstrates compilation process with preprocessor directives
 * gcc -E program1_1.c -o preprocessed.i   (Preprocessing)
 * gcc -S preprocessed.i -o assembly.s      (Compilation)
 * gcc -c assembly.s -o object.o            (Assembly)
 * gcc object.o -o executable               (Linking)
 */

#include <stdio.h>   // Preprocessor directive - includes standard I/O library
#define PI 3.14159   // Macro definition - text substitution

// Function prototype (declaration)
double calculate_area(double radius);

int main() {
    double radius = 5.0;
    double area;
    
    // Function call (linker resolves this)
    area = calculate_area(radius);
    
    printf("Circle with radius %.2f has area: %.2f\n", radius, area);
    printf("Value of PI macro: %f\n", PI);
    
    return 0;  // Return to operating system
}

// Function definition
double calculate_area(double radius) {
    return PI * radius * radius;  // PI gets substituted here
}