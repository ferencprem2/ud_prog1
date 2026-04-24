#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Nem adtál meg egyetlen szót sem!\n");
        return 1;
    }

    int shortestLength = strlen(argv[1]);
    for (int i = 1; i < argc; i++) {
        if (strlen(argv[i]) < shortestLength) {
            shortestLength = strlen(argv[i]);
        }
    }

    for (int i = 1; i < argc; i++) {
        if (strlen(argv[i]) == shortestLength) {
            printf("%s\n", argv[i]);
        }
    }


    return 0;
}