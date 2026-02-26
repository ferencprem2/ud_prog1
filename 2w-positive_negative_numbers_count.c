#include <stdio.h>

// ---- POZITÍV ÉS NEGATÍV ELEMEK SZÁMA ----

int main() {
    int positive_count = 0;
    int negative_count = 0;

    int numberRead;

    do
    {
        printf("Egesz szam (vege: 0): ");
        scanf("%d", &numberRead);

        numberRead > 0 ? positive_count++ : positive_count;
        numberRead < 0 ? negative_count++ : negative_count;

    } while (numberRead != 0);
    
    printf("Pozitiv elemek szama: %d\n", positive_count);
    printf("Negativ elemek szama: %d\n", negative_count);

    return 0;
}