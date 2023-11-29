#include <stdio.h>
#include <limits.h>

int safe_addition(int a, int b, int *result) {
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
        // Overflow will occur
        return 0;
    } else {
        *result = a + b;
        return 1;
    }
}

int main() {
    int num1, num2, sum;

    // Input two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Check for overflow before performing addition
    if (safe_addition(num1, num2, &sum)) {
        // Addition without overflow
        printf("Sum: %d\n", sum);
    } else {
        // Overflow occurred
        printf("Overflow! Addition cannot be performed.\n");
    }

    return 0;
}
