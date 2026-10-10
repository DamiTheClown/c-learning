#include <stdio.h>
#include <string.h>
#include <ctype.h>

void arrays() {
    // Array -> consecutive memory locations of same type
    int nums[5] = {1, 2, 3, 4, 5};
    // int nums[5] = {0}; // Fills array with zeros

    for (int i = 0; i < 5; i++) {
        printf("nums[%d] = %d\n", i, nums[i]);
    }

    // C has no len(). Length must be calculated:
    int count = sizeof(nums) / sizeof(nums[0]);
    printf("count = %d\n", count);
    // Warning: sizeof calculation only works in the scope where array was defined.

    // Memory layout:
    for (int i = 0; i < 5; i++) {
        printf("%p\n", (void*)&nums[i]);
    }
    // Addresses grow by 4 (size of int). Elements are contiguous.

    // Out of bounds access:
    int a[3] = {1, 2, 3};
    // printf("%d\n", a[5]); // Compiles, but reads garbage memory
    // a[5] = 99;            // Writes to unallocated memory (DANGEROUS)
}

void strings() {
    // Strings are arrays of characters terminated by null character '\0'
    char s[] = "Ahoj";

    /* Memory representation:
       Index    0    1    2    3    4
       Char    'A'  'h'  'o'  'j'  '\0'
       Value    65   104  111  106  0
    */

    char c = 'A';
    printf("%c\n", c);   // A
    printf("%d\n", c);   // 65

    // Character math:
    // 'c' - 'a'  // 2 (alphabetical position diff)
    // '7' - '0'  // 7 (char to int conversion)
    // 'a' - 'A'  // 32 (case diff)

    // Manual length calculation:
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
}

void string_library() {
    // #include <string.h>
    char x[32] = "Ahoj";
    char y[32];

    int length = strlen(x);          // 4
    strcpy(y, x);                    // Copy x to y (including '\0')
    strcat(y, " Svete");             // Append. Result: "Ahoj Svete"
    int cmp = strcmp(x, y);          // 0 if equal, otherwise < 0 or > 0
}

void safe_input() {
    // DO NOT USE: scanf("%s", buf); // Unsafe, can overflow

    char name[32];
    printf("Name: ");

    // fgets(destination, max_size, stream)
    // Reads max_size - 1 chars, adds '\0'. Prevents overflow.
    // Leaves '\n' in the buffer.
    if (fgets(name, sizeof(name), stdin) == NULL) {
        return; // Error or EOF
    }

    // strcspn returns index of first '\n' (or length if not found)
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline
}

void char_types() {
    // #include <ctype.h>
    char letter = 'a';
    char digit = '5';
    char lower = 'b';
    char upper = 'B';

    if (isalpha(letter)) {
        printf("Is letter.\n");
    }

    if (isdigit(digit)) {
        printf("Is digit.\n");
    }

    if (islower(lower)) {
        printf("Is lowercase.\n");
    }

    if (isupper(upper)) {
        printf("Is uppercase.\n");
    }

    // These return non-zero (true) or 0 (false)
    // Example: printf("%d\n", isupper('A'));
}