#include <stdio.h>

// 1. Functions

// Return type: int
// Function name: square
// Parameter: int x
int square(int x) {
    return x * x; // What function returns
}

void function_basics() {
    int r = square(5);
    printf("%d\n", r);
    // C reads top to bottom. Function must be declared before it's called.
}

// Function Prototype: Promise to the compiler that this function exists later
int prototype(int x);

// 2. Pass by Value (Copy)

void swap(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

void pass_by_value() {
    int x = 1, y = 2;
    swap(x, y);
    printf("%d %d\n", x, y); // Output: 1 2 (NOT SWAPPED)
    // Parameters are passed as copies. Original variables are untouched.
}

// 3. Scope

void scope_example() {
    int secret = 42;
}
// 'secret' variable does not exist here.

// 4. Recursion

int factorial(int n) {
    if (n <= 1) return 1; // Base case
    return n * factorial(n - 1);
}

void recursion() {
    int f = factorial(5); // 5! = 120
    printf("%d\n", f);

    // Warning: 13! exceeds 32-bit int capacity.
    // Missing base case or too deep recursion = Stack Overflow
}

// 5. Arrays in Functions

void zero_out(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
}

void array_parameters() {
    int nums[5] = {1, 2, 3, 4, 5};
    zero_out(nums, 5);
    // 'nums' is now completely zeros.
    // Functions CAN modify arrays directly (no copy is made).

    // Inside 'zero_out', sizeof(arr) returns size of memory address (e.g., 8 bytes), NOT array size!
    // Always pass array length as separate parameter 'n'.
}

// const keyword guarantees the function won't modify the array
int sum(const int arr[], int n);

// 6. Multiple Files

/*
// mathutil.h (Header file)
#ifndef MATHUTIL_H   // Include guard: Prevents double inclusion
#define MATHUTIL_H

int square_x(int x); // Prototype

#endif
*/

/*
// mathutil.c (Implementation)
#include "mathutil.h"

int square_x(int x) { return x * x; }
*/

/*
// main.c (Usage)
#include <stdio.h>    // <...> for system headers
#include "mathutil.h" // "..." for your own headers

int main(void) {
    printf("%d\n", square_x(5));
    return 0;
}
*/

// Compile command: gcc -Wall -Wextra -g main.c mathutil.c -o prog