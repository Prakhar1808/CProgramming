/*
 * COMPREHENSIVE POINTERS GUIDE IN C
 * 
 * This program demonstrates:
 * 1. Basic pointers
 * 2. Pointer arithmetic
 * 3. Pointers with arrays
 * 4. Pointers with strings
 * 5. Pointers to pointers
 * 6. Pointers to functions
 * 7. Dynamic memory allocation
 * 8. Common pointer pitfalls
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype for function pointer example
int add(int a, int b);
int multiply(int a, int b);

int main() {
    printf("=======================\n");
    printf("C POINTERS COMPREHENSIVE GUIDE\n");
    printf("=======================\n\n");

    /* ==================== */
    /* 1. BASIC POINTERS */
    /* ==================== */
    printf("1. BASIC POINTERS:\n");
    printf("------------------\n");
    
    int num = 42;
    int *ptr;           // Declaration: ptr is a pointer to int
    
    ptr = &num;         // Assignment: ptr now holds the address of num
    
    printf("   Variable 'num':\n");
    printf("   - Value: %d\n", num);
    printf("   - Address: %p\n", (void*)&num);
    
    printf("\n   Pointer 'ptr':\n");
    printf("   - Value (address stored): %p\n", (void*)ptr);
    printf("   - Dereferenced value: %d\n", *ptr);
    printf("   - Address of pointer itself: %p\n", (void*)&ptr);
    
    // Changing value through pointer
    *ptr = 100;
    printf("\n   After *ptr = 100:\n");
    printf("   - num = %d\n", num);
    printf("   - *ptr = %d\n\n", *ptr);

    /* ==================== */
    /* 2. POINTER ARITHMETIC */
    /* ==================== */
    printf("2. POINTER ARITHMETIC:\n");
    printf("-----------------------\n");
    
    int arr[] = {10, 20, 30, 40, 50};
    int *arr_ptr = arr;  // Points to first element of arr
    
    printf("   Array: [");
    for (int i = 0; i < 5; i++) {
        printf("%d%s", arr[i], i < 4 ? ", " : "");
    }
    printf("]\n\n");
    
    printf("   Pointer arithmetic operations:\n");
    printf("   - arr_ptr     points to: %d (address: %p)\n", *arr_ptr, (void*)arr_ptr);
    
    arr_ptr++;  // Move to next integer (increases by sizeof(int))
    printf("   - arr_ptr++   points to: %d (address: %p)\n", *arr_ptr, (void*)arr_ptr);
    
    arr_ptr += 2;  // Move forward by 2 integers
    printf("   - arr_ptr+=2  points to: %d (address: %p)\n", *arr_ptr, (void*)arr_ptr);
    
    arr_ptr--;  // Move back by 1 integer
    printf("   - arr_ptr--   points to: %d (address: %p)\n", *arr_ptr, (void*)arr_ptr);
    
    // Difference between pointers
    int *ptr1 = &arr[0];
    int *ptr2 = &arr[3];
    printf("   - Difference (&arr[3] - &arr[0]): %ld elements\n\n", ptr2 - ptr1);

    /* ==================== */
    /* 3. POINTERS AND ARRAYS */
    /* ==================== */
    printf("3. POINTERS AND ARRAYS:\n");
    printf("------------------------\n");
    
    printf("   Array access methods:\n");
    printf("   - arr[2] = %d\n", arr[2]);
    printf("   - *(arr + 2) = %d\n", *(arr + 2));
    printf("   - 2[arr] = %d (unconventional but valid!)\n\n", 2[arr]);
    
    // Iterating through array using pointers
    printf("   Iterating with pointers:\n   ");
    for (int *p = arr; p < arr + 5; p++) {
        printf(" %d", *p);
    }
    printf("\n\n");

    /* ==================== */
    /* 4. POINTERS AND STRINGS */
    /* ==================== */
    printf("4. POINTERS AND STRINGS:\n");
    printf("-------------------------\n");
    
    char str1[] = "Hello";  // Array of chars (modifiable)
    char *str2 = "World";   // Pointer to string literal (read-only)
    
    printf("   str1 (array): %s\n", str1);
    printf("   str2 (pointer to literal): %s\n", str2);
    
    // Modifying array string
    str1[0] = 'J';
    printf("   After str1[0] = 'J': %s\n", str1);
    
    // This would cause undefined behavior (crash on some systems):
    // str2[0] = 'w'; // DON'T DO THIS!
    
    // String traversal with pointers
    printf("   Traversing str1 with pointer:\n   ");
    char *p = str1;
    while (*p != '\0') {
        printf("%c ", *p);
        p++;
    }
    printf("\n\n");

    /* ==================== */
    /* 5. POINTERS TO POINTERS */
    /* ==================== */
    printf("5. POINTERS TO POINTERS:\n");
    printf("-------------------------\n");
    
    int value = 300;
    int *ptr_to_int = &value;
    int **ptr_to_ptr = &ptr_to_int;
    int ***ptr_to_ptr_to_ptr = &ptr_to_ptr;
    
    printf("   value = %d\n", value);
    printf("   Address of value: %p\n", (void*)&value);
    printf("\n   ptr_to_int points to value:\n");
    printf("   - ptr_to_int = %p\n", (void*)ptr_to_int);
    printf("   - *ptr_to_int = %d\n", *ptr_to_int);
    
    printf("\n   ptr_to_ptr points to ptr_to_int:\n");
    printf("   - ptr_to_ptr = %p\n", (void*)ptr_to_ptr);
    printf("   - *ptr_to_ptr = %p (address of value)\n", (void*)*ptr_to_ptr);
    printf("   - **ptr_to_ptr = %d (value)\n", **ptr_to_ptr);
    
    printf("\n   ptr_to_ptr_to_ptr points to ptr_to_ptr:\n");
    printf("   - ***ptr_to_ptr_to_ptr = %d (value)\n\n", ***ptr_to_ptr_to_ptr);

    // Practical use: Array of strings
    char *names[] = {"Alice", "Bob", "Charlie"};
    printf("   Array of strings (char*[]):\n");
    for (int i = 0; i < 3; i++) {
        printf("   - names[%d] = %s (address: %p)\n", 
               i, names[i], (void*)names[i]);
    }
    printf("\n");

    /* ==================== */
    /* 6. DYNAMIC MEMORY ALLOCATION */
    /* ==================== */
    printf("6. DYNAMIC MEMORY ALLOCATION:\n");
    printf("------------------------------\n");
    
    int *dynamic_arr = NULL;
    int n = 5;
    
    // Allocate memory
    dynamic_arr = (int*)malloc(n * sizeof(int));
    if (dynamic_arr == NULL) {
        printf("   Memory allocation failed!\n");
        return 1;
    }
    
    printf("   Allocated %d integers (%zu bytes)\n", n, n * sizeof(int));
    
    // Initialize and use
    for (int i = 0; i < n; i++) {
        dynamic_arr[i] = i * 10;
    }
    
    printf("   Dynamic array values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dynamic_arr[i]);
    }
    
    // Reallocate (resize)
    n = 10;
    dynamic_arr = (int*)realloc(dynamic_arr, n * sizeof(int));
    printf("\n   After reallocation to %d elements:\n", n);
    
    // Initialize new elements
    for (int i = 5; i < n; i++) {
        dynamic_arr[i] = i * 10;
    }
    
    printf("   Values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dynamic_arr[i]);
    }
    
    // Free memory
    free(dynamic_arr);
    dynamic_arr = NULL; // Good practice to avoid dangling pointer
    printf("\n   Memory freed, pointer set to NULL\n\n");

    /* ==================== */
    /* 7. POINTERS TO FUNCTIONS */
    /* ==================== */
    printf("7. POINTERS TO FUNCTIONS:\n");
    printf("--------------------------\n");
    
    // Declare function pointers
    int (*func_ptr)(int, int);
    
    // Point to add function
    func_ptr = add;
    printf("   func_ptr pointing to add():\n");
    printf("   - add(5, 3) = %d\n", add(5, 3));
    printf("   - func_ptr(5, 3) = %d\n", func_ptr(5, 3));
    
    // Point to multiply function
    func_ptr = multiply;
    printf("\n   func_ptr pointing to multiply():\n");
    printf("   - multiply(5, 3) = %d\n", multiply(5, 3));
    printf("   - func_ptr(5, 3) = %d\n\n", func_ptr(5, 3));

    /* ==================== */
    /* 8. VOID POINTERS (GENERIC POINTERS) */
    /* ==================== */
    printf("8. VOID POINTERS (GENERIC):\n");
    printf("----------------------------\n");
    
    int int_val = 65;
    float float_val = 3.14;
    char char_val = 'A';
    
    void *void_ptr;
    
    printf("   Void pointer can point to any type:\n");
    
    void_ptr = &int_val;
    printf("   - Pointing to int: %d\n", *(int*)void_ptr);
    
    void_ptr = &float_val;
    printf("   - Pointing to float: %.2f\n", *(float*)void_ptr);
    
    void_ptr = &char_val;
    printf("   - Pointing to char: %c\n\n", *(char*)void_ptr);

    /* ==================== */
    /* 9. COMMON POINTER PITFALLS */
    /* ==================== */
    printf("9. COMMON POINTER PITFALLS:\n");
    printf("----------------------------\n");
    
    printf("   A. Uninitialized pointers:\n");
    int *uninit_ptr;  // Dangerous! Contains garbage address
    printf("   - int *uninit_ptr; // Never dereference before initialization!\n");
    
    printf("\n   B. Dangling pointers:\n");
    int *dangling_ptr = (int*)malloc(sizeof(int));
    *dangling_ptr = 42;
    free(dangling_ptr);
    printf("   - After free(), dangling_ptr points to freed memory\n");
    printf("   - Always set pointer to NULL after free()\n");
    
    printf("\n   C. Memory leaks:\n");
    printf("   - Forgetting to free() allocated memory\n");
    printf("   - Losing the pointer to allocated memory\n");
    
    printf("\n   D. Pointer type mismatches:\n");
    float f = 3.14;
    int *wrong_type = (int*)&f;  // Casting but wrong interpretation
    printf("   - int *wrong_type = (int*)&float_var; // Technically allowed but dangerous\n");
    
    printf("\n   E. Pointer arithmetic on non-array pointers:\n");
    int single_var = 100;
    int *single_ptr = &single_var;
    printf("   - single_ptr + 1 points to: %p (undefined behavior if dereferenced)\n", 
           (void*)(single_ptr + 1));

    /* ==================== */
    /* SUMMARY AND BEST PRACTICES */
    /* ==================== */
    printf("\n10. SUMMARY AND BEST PRACTICES:\n");
    printf("--------------------------------\n");
    
    printf("   1. Always initialize pointers:\n");
    printf("      - int *ptr = NULL; // Good\n");
    printf("      - int *ptr;        // Bad (contains garbage)\n\n");
    
    printf("   2. Check for NULL before dereferencing:\n");
    printf("      - if (ptr != NULL) { *ptr = value; }\n\n");
    
    printf("   3. Match pointer types (use void* when generic needed)\n\n");
    
    printf("   4. Use array syntax with pointers to arrays\n\n");
    
    printf("   5. After free(), set pointer to NULL:\n");
    printf("      - free(ptr); ptr = NULL;\n\n");
    
    printf("   6. Remember pointer arithmetic scales by type size\n\n");
    
    printf("   7. Use const with pointers when appropriate:\n");
    printf("      - const int *ptr;        // Pointer to constant data\n");
    printf("      - int *const ptr;        // Constant pointer to data\n");
    printf("      - const int *const ptr;  // Constant pointer to constant data\n\n");
    
    printf("   8. Be careful with pointer casting\n");

    printf("\n=======================\n");
    printf("END OF POINTERS GUIDE\n");
    printf("=======================\n");

    return 0;
}

/* Function definitions */

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}