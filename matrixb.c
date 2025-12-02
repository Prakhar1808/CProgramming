#include <stdio.h>

int main(){
    int row , col;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &row, &col);
    int matrix1[row][col];
    int matrix2[row][col];
    int sum[row][col];


    printf("Enter elements of the matrix1:\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("The matrix1 is:\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    } 

    printf("Enter elements of the matrix2:\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("The matrix2 is:\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
printf("The sum of two matrices is:\n");
for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
        sum[i][j] = matrix1[i][j] + matrix2[i][j];
        printf("%d ", sum[i][j]);
    }
    printf("\n");
}


       return 0;
}