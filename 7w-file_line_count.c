#include <stdio.h>
#include <stdlib.h>

int get_number_of_lines(FILE *fp);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Hiba! Adja meg egy szöveges állomány nevét!\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Hiba! A %s nevű file-t nem sikerült megnyitni!\n", argv[1]);
        return 2;
    }

    int lines = get_number_of_lines(fp);
    fclose(fp);

    printf("%d\n", lines);
    return 0;
}


int get_number_of_lines(FILE *fp) {
    int count = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        count++;
    }

    return count;
}