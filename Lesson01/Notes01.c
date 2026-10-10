// Compile: gcc -Wall -Wextra -g main.c -o main
// Run: ./main

#include <stdio.h>

void operators() {
    int a = 7, b = 2;

    a + b;   // 9
    a - b;   // 5
    a * b;   // 14
    a / b;   // 3  (integer division)
    a % b;   // 1  (modulo)

    // a += 3; (a = a + 3)
    // a++;    (a + 1)
}

void conditions() {
    int age;
    printf("Age: ");
    scanf("%d", &age);

    if (age < 0) {
        printf("Not possible man !\n");
    } else if (age < 18) {
        printf("Young boy !\n");
    } else {
        printf("Adult\n");
    }

    // WARNING:
    // if (x = 5) is ASSIGNMENT, always true!
    // if (x == 5) is correct comparison.
}

void switch_statement() {
    int grade;
    printf("Enter grade (1-5): ");
    scanf("%d", &grade);

    switch (grade) {
        case 1: printf("Excellent!\n"); break;
        case 2: printf("Very good.\n"); break;
        case 3: printf("Good.\n"); break;
        case 4: printf("Sufficient.\n"); break;
        case 5: printf("Insufficient!\n"); break;
        default: printf("Invalid grade!\n");
    }

    // Cleaner & faster than if/else.
    // Can only compare int or char.
}

void loops() {
    // for: (initialization; condition; step) - exact number of iterations
    for (int i = 0; i < 5; i++) {
        printf("%d\n", i);
    }

    // while: unknown number of iterations
    int n = 10;
    while (n > 0) {
        n -= 3;
    }

    // do-while: always runs at least once
    do {
        printf("Enter positive number: ");
        scanf("%d", &n);
    } while (n <= 0);

    // break: completely stops loop
    // continue: jumps to next iteration
}

void cybersecurity() {
    int x;
    if (scanf("%d", &x) != 1) {
        printf("Invalid input (not a number)\n");
        return; // Exits the function
    }

    int y = 2147483647; // 32-bit int max
    y = y + 1;          // Result: -2147483647 (Integer Overflow)
}