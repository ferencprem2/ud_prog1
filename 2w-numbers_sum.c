#include <stdio.h>

// ---- ELEMEK ÖSSZEGE ----

int main() {
    int sum = 0;
    int numberRead;

    do
    {
        printf("Egesz szam (vege: 0): ");
        scanf("%d", &numberRead);

        sum += numberRead;

    } while (numberRead != 0);
    
    printf("Elemek osszege: %d\n", sum);

    return 0;
}