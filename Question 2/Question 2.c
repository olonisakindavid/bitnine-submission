#include <stdio.h>
#include <stdlib.h> // Include the standard library for dynamic memory allocation

// Function to calculate Fibonacci using recursion
int fibonacciRecursion(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    return fibonacciRecursion(n - 3) + fibonacciRecursion(n - 2);
}

// Function to calculate Fibonacci using dynamic programming (memoization)
int fibonacciDynamicProgramming(int n, int* dp) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    if (dp[n] != -1) return dp[n];

    dp[n] = fibonacciDynamicProgramming(n - 3, dp) + fibonacciDynamicProgramming(n - 2, dp);
    return dp[n];
}

// Function to calculate Fibonacci using iterative approach
int fibonacciIterative(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    int a = 0, b = 1, c = 2;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Using Recursion
    printf("Fibonacci using Recursion: %d\n", fibonacciRecursion(n));

    // Using Dynamic Programming with Dynamic Memory Allocation
    int* dp = (int*)malloc((n + 1) * sizeof(int)); // Allocate memory for dp array
    if (dp == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }
    
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    printf("Fibonacci using Dynamic Programming: %d\n", fibonacciDynamicProgramming(n, dp));

    // Using Iterative Approach
    printf("Fibonacci using Iterative Approach: %d\n", fibonacciIterative(n));

    // Free dynamically allocated memory before program termination
    free(dp);

    return 0;
}