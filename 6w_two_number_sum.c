#include <stdio.h>

// ---- Két szám összege ----

int main()
{
    int a, b;
    char sor[100];

    printf("Adj meg ket szamot: ");

    if (fgets(sor, sizeof(sor), stdin) == NULL)
    {
        printf("Hiba! Ket szamot kell megadni.\n");
        return 1;
    }

    if (sscanf(sor, "%d %d", &a, &b) != 2)
    {
        printf("Hiba! Ket szamot kell megadni.\n");
        return 1;
    }

    printf("%d\n", a + b);

    return 0;
}
