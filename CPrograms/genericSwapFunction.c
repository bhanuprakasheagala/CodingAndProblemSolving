#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void* a, void* b, size_t size) {
    // Allocate memory for temporary variable
    void* temp = (void*)malloc(size);

    if(temp == NULL){
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Copy the contents of `a` to `temp`
    memcpy(temp, a, size);

    // Copy the contents of `b` to `a`
    memcpy(a, b, size);

    // Copy the contents of `temp` to `b`
    memcpy(b, temp, size);

    // Free the allocated memory
    free(temp);
}

int main() {

    int a = 5; int b = 10;
    double c = 19.45; double d = 38.12;
    char str1[]="Hi";
    char str2[]="Hello";

    printf("Before swap - a: %d, b: %d\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("After swap - a: %d, b: %d\n", a, b);

    printf("Before swap - c: %.2f, d: %.2f\n", c, d);
    swap(&c, &d, sizeof(double));
    printf("Before swap - c: %.2f, d: %.2f\n", c, d);

    printf("Before swap - str1: %s, str2: %s\n", str1, str2);
    swap(&str1, &str2, sizeof(str2));
    printf("After swap - str1: %s, str2: %s\n", str1, str2);

    return 0;
}