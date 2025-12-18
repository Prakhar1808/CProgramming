// sequential.c
#include <stdio.h>

int main() {
    FILE *fp;
    
    // Writing sequentially
    fp = fopen("sequential.txt", "w");
    fprintf(fp, "Line 1\n");
    fprintf(fp, "Line 2\n");
    fprintf(fp, "Line 3\n");
    fclose(fp);
    
    // Reading sequentially
    fp = fopen("sequential.txt", "r");
    char buffer[100];
    
    printf("Sequential Reading:\n");
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);
    
    return 0;
}