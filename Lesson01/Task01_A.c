// Primes:
// read N (with scanf validation) and print all prime numbers from 2 to N.
// You will need a nested loop and %.

#include <stdio.h>
#include <ctype.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main () {
    int n;
    printf("Enter a number: ");

    if (scanf("%d", &n) != 1) {
        printf("Wrong input !");
        return 1;
    }

    printf("Prime numbers: \n");
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d, ", i);
        }
    }
    printf("\n");

    return 0;
}