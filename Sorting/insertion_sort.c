// insertion_sort.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n);
void insertionSortBinary(int arr[], int n);  // Optimized with binary search
void printArray(int arr[], int n);
void generateRandomArray(int arr[], int n);

int main() {
    int n;
    
    printf("=== INSERTION SORT ALGORITHM ===\n\n");
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }
    
    int *arr = (int*)malloc(n * sizeof(int));
    int *arr2 = (int*)malloc(n * sizeof(int));
    
    if(arr == NULL || arr2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    generateRandomArray(arr, n);
    
    // Copy array for second sort
    for(int i = 0; i < n; i++) {
        arr2[i] = arr[i];
    }
    
    printf("\nOriginal array:\n");
    printArray(arr, n);
    
    // Standard Insertion Sort
    clock_t start = clock();
    insertionSort(arr, n);
    clock_t end = clock();
    
    printf("\nStandard Insertion Sort result:\n");
    printArray(arr, n);
    printf("Time: %f seconds\n", ((double)(end - start))/CLOCKS_PER_SEC);
    
    // Binary Insertion Sort
    start = clock();
    insertionSortBinary(arr2, n);
    end = clock();
    
    printf("\nBinary Insertion Sort result:\n");
    printArray(arr2, n);
    printf("Time: %f seconds\n", ((double)(end - start))/CLOCKS_PER_SEC);
    
    free(arr);
    free(arr2);
    
    return 0;
}

// Standard Insertion Sort
void insertionSort(int arr[], int n) {
    int comparisons = 0;
    int shifts = 0;
    
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        printf("\nInserting element %d (value: %d):\n", i, key);
        
        // Move elements greater than key to one position ahead
        while(j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            shifts++;
            j = j - 1;
        }
        
        arr[j + 1] = key;
        
        printf("  Array after insertion: ");
        printArray(arr, n);
    }
    
    printf("\nTotal comparisons: %d\n", comparisons);
    printf("Total shifts: %d\n", shifts);
}

// Binary Insertion Sort (optimized)
void insertionSortBinary(int arr[], int n) {
    int comparisons = 0;
    
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0;
        int right = i;
        
        // Binary search for insertion position
        while(left < right) {
            comparisons++;
            int mid = left + (right - left) / 2;
            
            if(key < arr[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // Shift elements
        for(int j = i; j > left; j--) {
            arr[j] = arr[j - 1];
        }
        
        arr[left] = key;
    }
    
    printf("Binary Insertion Sort - Comparisons: %d\n", comparisons);
}

void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%3d ", arr[i]);
    }
    printf("\n");
}