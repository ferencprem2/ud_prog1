#include <stdio.h>

// ---- NÉGGYEL OSZTHATÓ SZÁMOK ----

int main() {

    int n;

    printf("Adjon meg egy pozitiv egesz szamot: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 4 == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}