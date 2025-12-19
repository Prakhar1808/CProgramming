// bubble_sort.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);
void generateRandomArray(int arr[], int n, int min, int max);
void bubbleSortOptimized(int arr[], int n);

int main() {
    int n;
    
    printf("=== BUBBLE SORT ALGORITHM ===\n\n");
    
    // Get array size from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Error: Array size must be positive!\n");
        return 1;
    }
    
    // Create array
    int *arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Generate random numbers
    generateRandomArray(arr, n, 1, 100);
    
    printf("\nOriginal array:\n");
    printArray(arr, n);
    
    // Time the sorting
    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();
    
    printf("\nSorted array:\n");
    printArray(arr, n);
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken by standard Bubble Sort: %f seconds\n", time_taken);
    
    // Test optimized version
    generateRandomArray(arr, n, 1, 100);
    
    start = clock();
    bubbleSortOptimized(arr, n);
    end = clock();
    
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by optimized Bubble Sort: %f seconds\n", time_taken);
    
    free(arr);
    return 0;
}

// Standard Bubble Sort
void bubbleSort(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;
    
    for(int i = 0; i < n-1; i++) {
        printf("\nPass %d:\n", i+1);
        
        for(int j = 0; j < n-i-1; j++) {
            comparisons++;
            
            if(arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
                
                printf("  Swapped %d and %d: ", arr[j+1], arr[j]);
                printArray(arr, n);
            }
        }
    }
    
    printf("\nTotal comparisons: %d\n", comparisons);
    printf("Total swaps: %d\n", swaps);
}

// Optimized Bubble Sort (stops if array is already sorted)
void bubbleSortOptimized(int arr[], int n) {
    int i, j;
    int swapped;
    int comparisons = 0;
    int swaps = 0;
    
    for(i = 0; i < n-1; i++) {
        swapped = 0;
        
        for(j = 0; j < n-i-1; j++) {
            comparisons++;
            
            if(arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
                swaps++;
            }
        }
        
        // If no two elements were swapped, array is sorted
        if(!swapped) {
            break;
        }
    }
    
    printf("Optimized version - Comparisons: %d, Swaps: %d\n", comparisons, swaps);
}

// Generate random array
void generateRandomArray(int arr[], int n, int min, int max) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

// Print array
void printArray(int arr[], int n) {
    printf("[");
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if(i < n-1) printf(", ");
    }
    printf("]\n");
}