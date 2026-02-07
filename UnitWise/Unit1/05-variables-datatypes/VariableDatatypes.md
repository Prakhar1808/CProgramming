# Variables
- Memory location with name
- Declaration: `int count;`
- Initialization: `int count = 10;`

# Data Types
## Basic Types
1. `char` - 1 byte
2. `int` - 2/4 bytes
3. `float` - 4 bytes
4. `double` - 8 bytes

## Type Modifiers
- `signed`, `unsigned`
- `short`, `long`
- `long long` (C99)

# I/O Statements
```c
// Input
scanf("%d", &num);
getchar();
gets(string);

// Output
printf("Value: %d", num);
putchar('A');
puts("Hello");
```
---
# Type Conversion (Interconversion)
1. Implicit (Automatic)
```c
int i = 10;
float f = i;    // int → float
char c = 'A';
int j = c;      // char → int (ASCII)
```

2. Explicit (Type Casting)
```c
float result;
result = (float) 5 / 2;  // 2.5
int val = (int) 3.14;    // 3
```
