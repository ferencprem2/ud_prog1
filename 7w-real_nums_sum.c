#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Hiba! Adja meg a fájl nevét!\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Hiba! A %s nevű file-t nem sikerült megnyitni!\n", argv[1]);
        return 1;
    }

    char buffer[1024];
    long double sum = 0.0;

    while (fgets(buffer, sizeof(buffer), fp)) {
        buffer[strcspn(buffer, "\r\n")] = '\0';

        for (int i = 0; buffer[i]; i++) {
            if (buffer[i] == ',') {
                buffer[i] = '.';
            }
        }

        long double val = strtold(buffer, NULL);
        sum += val;
    }

    fclose(fp);
    printf("%.20Lf\n", sum);
    return 0;
}