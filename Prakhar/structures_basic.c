// structures_basic.c
#include <stdio.h>
#include <string.h>

// ============ 1. BASIC STRUCTURE DEFINITION ============

// Method 1: Define structure and declare variables separately
struct Student {
    int rollNumber;
    char name[50];
    float marks;
    char grade;
};  // Note the semicolon!

// Method 2: Define and declare variables at same time
struct Point {
    int x;
    int y;
} p1, p2;  // p1 and p2 are variables of type struct Point

// Method 3: Using typedef to create an alias
typedef struct {
    int day;
    int month;
    int year;
} Date;  // Now we can use 'Date' as a type name

// Method 4: Structure with pointer members
struct ComplexNumber {
    float real;
    float imag;
};

int main() {
    printf("=== BASIC STRUCTURE OPERATIONS ===\n\n");
    
    // ============ STRUCTURE INITIALIZATION ============
    
    printf("1. Structure Initialization:\n");
    printf("----------------------------\n");
    
    // Method 1: Member-by-member initialization
    struct Student student1;
    student1.rollNumber = 101;
    strcpy(student1.name, "John Doe");
    student1.marks = 85.5;
    student1.grade = 'A';
    
    printf("Student 1:\n");
    printf("  Roll Number: %d\n", student1.rollNumber);
    printf("  Name: %s\n", student1.name);
    printf("  Marks: %.2f\n", student1.marks);
    printf("  Grade: %c\n\n", student1.grade);
    
    // Method 2: Initialize at declaration
    struct Student student2 = {102, "Jane Smith", 92.5, 'A'};
    printf("Student 2:\n");
    printf("  Roll Number: %d\n", student2.rollNumber);
    printf("  Name: %s\n", student2.name);
    printf("  Marks: %.2f\n", student2.marks);
    printf("  Grade: %c\n\n", student2.grade);
    
    // Method 3: Designated initialization (C99 feature)
    struct Student student3 = {
        .rollNumber = 103,
        .marks = 78.5,
        .name = "Bob Johnson",
        .grade = 'B'
    };
    printf("Student 3 (Designated Initialization):\n");
    printf("  Roll Number: %d\n", student3.rollNumber);
    printf("  Name: %s\n", student3.name);
    printf("  Marks: %.2f\n", student3.marks);
    printf("  Grade: %c\n\n", student3.grade);
    
    // Method 4: Partial initialization
    struct Student student4 = {104};  // Only rollNumber initialized, others 0/NULL
    printf("Student 4 (Partial Initialization):\n");
    printf("  Roll Number: %d\n", student4.rollNumber);
    printf("  Name: %s\n", student4.name);  // Empty string
    printf("  Marks: %.2f\n", student4.marks);  // 0.0
    printf("  Grade: %c\n\n", student4.grade);  // '\0'
    
    // ============ ACCESSING STRUCTURE MEMBERS ============
    
    printf("2. Accessing Structure Members:\n");
    printf("--------------------------------\n");
    
    // Direct access using dot operator (for normal variables)