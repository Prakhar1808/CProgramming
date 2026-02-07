# C Tokens Classification

## 1. Keywords (32 in ANSI C)
- Data types: `int`, `float`, `char`, `double`
- Control: `if`, `else`, `for`, `while`, `do`, `switch`, `case`
- Storage: `auto`, `register`, `static`, `extern`
- Others: `return`, `void`, `sizeof`, `typedef`

## 2. Identifiers
- Rules: Start with letter/underscore, alphanumeric, case-sensitive
- Valid: `_total`, `sum1`, `student_name`
- Invalid: `1st`, `total-amount`, `int` (reserved)

## 3. Constants
// Literal Constants
85          // Decimal integer
0213        // Octal
0x4b        // Hexadecimal
30u         // Unsigned
30l         // Long

// Floating-point
3.14159
314159E-5L

// Character
'x'
'\n'
'\t'

## 4. Strings

+ Array of characters ending with '\0'
+ "Hello World" stored as 12 bytes (including null)

## 5. Special Symbols

+ Brackets: (), {}, []
+ Punctuation: ;, :
+ Operators: +, -, *, /
+ Preprocessor: #
+ Pointer: *
