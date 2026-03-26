#include <stdio.h>
#include <stdlib.h>

// ---- Tombrol masolat ----

int main()
{
    int db;

    printf("Hany db szamot szeretnel bevinni?\n");
    scanf("%d", &db);

    int *array = (int*)malloc(db * sizeof(int));
    int *arrayAbsolute = (int*)malloc(db * sizeof(int));

    if (array == NULL || arrayAbsolute == NULL)
    {
        printf("Memoriafoglalasi hiba.\n");
        return 1;
    }

    for (int i = 0; i < db; i++)
    {
        printf("%d. szam: ", i + 1);
        scanf("%d", &array[i]);

        if (array[i] < 0)
            arrayAbsolute[i] = -array[i];
        else
            arrayAbsolute[i] = array[i];
    }

    printf("\nA bevitt szamok abszolutertekei: ");
    for (int i = 0; i < db; i++)
    {
        printf("%d", arrayAbsolute[i]);
        if (i < db - 1)
            printf(", ");
    }

    printf("\nA megadott szamok: ");
    for (int i = 0; i < db; i++)
    {
        printf("%d", array[i]);
        if (i < db - 1)
            printf(", ");
    }

    printf("\n");

    free(array);
    free(arrayAbsolute);

    return 0;
}