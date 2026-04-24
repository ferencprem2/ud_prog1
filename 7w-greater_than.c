#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in = fopen("in.txt", "r");
    if (in == NULL) {
        fprintf(stderr, "Hiba! Nem sikerült megnyitni az in.txt fájlt!\n");
        return 1;
    }
    printf("# in.txt sikeresen megnyitva\n");

    FILE *out = fopen("out.txt", "w");
    if (out == NULL) {
        fprintf(stderr, "Hiba! Nem sikerült megnyitni az out.txt fájlt!\n");
        fclose(in);
        return 2;
    }

    printf("# 0,5-nél nagyobb számok szűrése...\n");

    double num;
    int count = 0;

    while (fscanf(in, "%lf", &num) == 1) {
        if (num > 0.5) {
            fprintf(out, "%.15f\n", num); // kiírás fájlba
            count++;
        }
    }

    printf("# szűrés vége\n");

    fclose(in);
    fclose(out);

    printf("# out.txt bezárva\n");
    printf("# out.txt-be kiírt számok mennyisége: %d db\n", count);

    return 0;
}