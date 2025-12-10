//1. stdio.h - Standard Input/Output
#include <stdio.h>

// Common functions:
// printf(), scanf(), fopen(), fclose(), fgets(), fputs()
// fprintf(), fscanf(), getchar(), putchar(), puts()

//2. stdlib.h - Standard Library

#include <stdlib.h>

// Memory management
malloc(), calloc(), realloc(), free()

// Program control
exit(), abort(), atexit()

// Conversions
atoi(), atof(), atol(), rand(), srand()

// Searching and sorting
qsort(), bsearch()

//3. assert.h - Diagnostics
#include <assert.h>

void example() {
    int x = 5;
    assert(x > 0);  // If false, program terminates with error message
    // Use for debugging, can be disabled with NDEBUG macro
}