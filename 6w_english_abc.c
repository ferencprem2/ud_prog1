#include <stdio.h>
#include <stdlib.h>

typedef char* string;

// ---- Angol ABC ----

int main() {
    char array[26];
    string abc = malloc(27);

    for (int i = 0; i < 26; i++) {
        array[i] = (char)(i + 97);
    }

    printf("Char array:");
    for (int i = 0; i < 26; i++) {
        abc[i] = array[i];
        printf("%c", abc[i]);
    }
    abc[26] = '\0';

    printf("\nSingle string: %s", abc);
    free(abc);
    return 0;
}