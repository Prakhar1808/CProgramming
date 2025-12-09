//Matrix Addition
#include <stdio.h>
int main(){
    int row,col; //will take garbage values
    printf("Enter no. of rows: \n");
    scanf("%d",&row);
    printf("Enter no. of columns: \n");
    scanf("%d",&col);
    int matrix1[row][col], matrix2[row][col], sum[row][col];

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("Enter Element for First Matrix \n");
            scanf("%d",&matrix1[i][j]);
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("Enter Element for Second Matrix \n");
            scanf("%d",&matrix2[i][j]);
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            sum[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
    printf("Elements of Sum Matrix: \n");
    for(int i=0;i<row;i++){
        printf("\n");
        for(int j=0;j<col;j++){
            printf("\t %d",sum[i][j]);
        }
    }
}