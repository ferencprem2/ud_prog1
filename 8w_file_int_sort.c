#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Hiba! Nem sikerült megnyitni az input.txt fájlt!\n");
        return 1;
    }

    int numbers[100];
    int i = 0;
    while (i < 100 && fscanf(file, "%d", &numbers[i]) == 1) {
        i++;
    }

    fclose(file);

    for (int j = 1; j < i; j++) {
        if (numbers[j] < numbers[j - 1]) {
            int temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
        }
    }

    for (int j = 0; j < i; j++) {
        printf("%d ", numbers[j]);
    }

    return 0;
}