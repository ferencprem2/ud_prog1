#include <stdio.h>

// ---- PÁRATLAN SZÁMOK VISSZAFELÉ ----

int main() {

    int n;

    printf ("n: ");
    scanf ("%d", &n);

    for (int i = n; i > 0; i--) {
        if (i % 2 != 0) {
            printf ("%d ", i);
            printf("\n");
        }
    }

    return 0;
}