// Structure: Each member has own memory
struct S { int a; float b; }; // Size: 8 bytes (typically)

// Union: All members share memory
union U { int a; float b; };  // Size: 4 bytes (largest member)