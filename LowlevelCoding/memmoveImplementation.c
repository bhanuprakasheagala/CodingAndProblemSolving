#include <stdio.h>
#include <string.h>
void *memmove_custom(void *dest, const void *src, size_t n) {
    // Check if the source and destination overlap
    if (dest <= src || (char *)dest >= (char *)src + n) {
        // No overlap, use regular memcpy
        while (n--) {
            *(char *)dest = *(char *)src;
            dest = (char *)dest + 1;
            src = (char *)src + 1;
        }
    } else {
        // Overlapping region, copy in reverse order
        dest = (char *)dest + n - 1;
        src = (char *)src + n - 1;

        while (n--) {
            *(char *)dest = *(char *)src;
            dest = (char *)dest - 1;
            src = (char *)src - 1;
        }
    }

    return dest;
}

int main() {
    char source[] = "Programming";
    char destination[20];

    // Using custom memmove function
    memmove_custom(destination, source, strlen(source) + 1); // +1 to include the null terminator

    // Print the result
    printf("Using custom memmove: %s\n", destination);

    return 0;
}