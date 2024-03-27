#include <stdio.h>

// Macro to handle endian conversion
#define SWAP_ENDIAN_32(x) (((x & 0xFF) << 24) | (((x >> 8) & 0xFF) << 16) | (((x >> 16) & 0xFF) << 8) | ((x >> 24) & 0xFF))

/*
NOTES on above macro:
It is designed to swap the byte order of a 32 bit integer.
Example: 0x12345678
1. `((x & 0xFF) << 24)` : This extracts the LSB of `x` and shifts it to the MSB position
    For `0x12345678`, the LSB is `0x78`. After shifting it becomes `0x78000000`
2. `(((x >> 8) & 0xFF) << 16)` : This extracts the second byte of `x` and shifts it to the
    second-most significant byte position.
    For `0x12345678`, the second byte is `0x56`. After shifting, it becomes `0x00560000`.
3. `(((x >> 16) & 0xFF) << 8)` : This extracts the third byte of x and shifts it to the 
    third-most significant byte position.
    For `0x12345678`, the third byte is `0x34`. After shifting, it becomes `0x00003400`.
4. `((x >> 24) & 0xFF))` : This extracts MSB of `x` and shifts it to the
    least significant byte (LSB) position.
    For `0x12345678`, the MSB is `0x12`. After shifting, it becomes `0x00000012`.
Now, combining all these parts with the `|` (bitwise OR) operator:
        `swappedValue = 0x78000000 | 0x00560000 | 0x00003400 | 0x00000012`
The final swappedValue is `0x78563412`, which is the byte-swapped version of the original `0x12345678`.
This process ensures that the byte order is swapped, making the macro endian-independent.
*/
union EndianCheck {
    int value;
    char c[4];
};

int main() {

    union EndianCheck u;
    u.value = 0x12345678;
    printf("Original Value: %X.%X.%X.%X\n", u.c[0], u.c[1], u.c[2], u.c[3]);

    // Convert to little-endian using the macro
    union EndianCheck swapped;
    swapped.value = SWAP_ENDIAN_32(u.value);
    printf("Endian Independent Value: %X.%X.%X.%X\n", swapped.c[0], swapped.c[1], swapped.c[2], swapped.c[3]);
    return 0;
}