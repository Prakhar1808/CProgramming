// fibonacci_recursive_basic.c
// TODO:a more efficient and simple version
#include <stdio.h>

// Function declaration
int fibonacci(int n);

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series (first %d terms):\n", n);
    for(int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    // Get specific term
    printf("\nEnter term position to find (0-indexed): ");
    int position;
    scanf("%d", &position);
    printf("Fibonacci(%d) = %d\n", position, fibonacci(position));

    return 0;
}

// Recursive function to find nth Fibonacci number
// Base cases:
//   fibonacci(0) = 0
//   fibonacci(1) = 1
// Recursive case:
//   fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)
int fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2); //the part which makes it Recursive, inefficient but works
    //mulitple times a single value is calculated which makes it so much inefficient
}
