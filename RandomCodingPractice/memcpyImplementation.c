// Write your own `memcpy()`
#include <stdio.h>
#include <string.h>

void myMemCpy(void* dest, void* src, size_t n){
    // Typecast src and dest to (char*)
    char* csrc = (char*)src;
    char* cdest = (char*)dest;

    // Copy contents of src[] to dest[]
    for(int i=0; i<n; i++)
        cdest[i] = csrc[i];
}

int main() {
    char csrc[] = "Geeksforgeeks";
    char cdest[100];
    myMemCpy(cdest, csrc, strlen(csrc)+1);
    printf("Copied string is %s", cdest);

    int isrc[] = {10,20,30,40,50};
    int n = sizeof(isrc)/sizeof(isrc[0]);
    int idest[n], i;
    myMemCpy(idest, isrc, sizeof(isrc));
    printf("\nCopied array is ");
    for(int i=0; i<n; i++)
        printf("%d ", idest[i]);
    printf("\n");
    return 0;
}