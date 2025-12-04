#include <stdio.h>

int main() {
    int row1, col1, row2, col2;
    int i, j, k;
    
    printf("=== MATRIX MULTIPLICATION ===\n\n");
    
    // Input dimensions of first matrix
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &row1, &col1);
    
    // Input dimensions of second matrix
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &row2, &col2);
    
    // Check if multiplication is possible
    if (col1 != row2) {
        printf("\n❌ ERROR: Matrix multiplication not possible!\n");
        printf("   Columns of first matrix (%d) must equal rows of second matrix (%d)\n", col1, row2);
        return 1;
    }
    
    // Declare matrices
    int A[row1][col1], B[row2][col2], C[row1][col2];
    
    // Input first matrix
    printf("\n📝 Enter elements of first matrix (%dx%d):\n", row1, col1);
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    
    // Input second matrix
    printf("\n📝 Enter elements of second matrix (%dx%d):\n", row2, col2);
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    
    // Initialize result matrix to 0
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            C[i][j] = 0;
        }
    }
    
    // Multiply matrices (TRIPLE LOOP)
    for (i = 0; i < row1; i++) {          // For each row of A
        for (j = 0; j < col2; j++) {      // For each column of B
            for (k = 0; k < col1; k++) {  // For each column of A / row of B
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    // Display matrices and result
    printf("\n✅ First Matrix A (%dx%d):\n", row1, col1);
    for (i = 0; i < row1; i++) {
        printf("   ");
        for (j = 0; j < col1; j++) {
            printf("%6d ", A[i][j]);
        }
        printf("\n");
    }
    
    printf("\n✅ Second Matrix B (%dx%d):\n", row2, col2);
    for (i = 0; i < row2; i++) {
        printf("   ");
        for (j = 0; j < col2; j++) {
            printf("%6d ", B[i][j]);
        }
        printf("\n");
    }
    
    printf("\n✅ Result Matrix C = A×B (%dx%d):\n", row1, col2);
    for (i = 0; i < row1; i++) {
        printf("   ");
        for (j = 0; j < col2; j++) {
            printf("%6d ", C[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}