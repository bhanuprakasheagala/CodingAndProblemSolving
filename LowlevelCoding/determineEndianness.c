#include <stdio.h>
#include <stdlib.h>

union EndianCheck {
    int value; // Union uses the same address space for
    char c[4]; // all of it's members.
};

int main() {
    union EndianCheck u;
    u.value = 0x12345678;

    /*
    The char array is implicitly initialized based on the value of the int
    Now u.c[0] contains the most significant byte, u.c[1] the next one, and so on.
    */

    if(u.c[0] == 0x12) {
        printf("%X.%X.%X.%X\n", u.c[0], u.c[1], u.c[2], u.c[3]);
        printf("Big Endian\n");
    }
    else {
        printf("%X.%X.%X.%X\n", u.c[3], u.c[2], u.c[1], u.c[0]);
        printf("Littel Endian\n");
    }
    return 0;
}