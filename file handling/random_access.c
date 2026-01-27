// random_access.c
#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    FILE *fp;
    struct Student s;
    
    // Writing 3 records
    fp = fopen("students.dat", "wb");
    
    s.roll = 101; strcpy(s.name, "Alice"); s.marks = 85.5;
    fwrite(&s, sizeof(s), 1, fp);
    
    s.roll = 102; strcpy(s.name, "Bob"); s.marks = 92.0;
    fwrite(&s, sizeof(s), 1, fp);
    
    s.roll = 103; strcpy(s.name, "Charlie"); s.marks = 78.5;
    fwrite(&s, sizeof(s), 1, fp);
    
    fclose(fp);
    
    // RANDOM ACCESS: Read 2nd record directly
    fp = fopen("students.dat", "rb");
    
    fseek(fp, sizeof(struct Student) * 1, SEEK_SET); // Skip 1st record
    fread(&s, sizeof(s), 1, fp);
    
    printf("2nd Record (Direct Access):\n");
    printf("Roll: %d\nName: %s\nMarks: %.2f\n", s.roll, s.name, s.marks);
    
    fclose(fp);
    
    return 0;
}