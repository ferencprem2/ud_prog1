#include <stdio.h>

// ---- MARIO V3 ----

int main() {

    int n;
    printf("Magassag: \n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
     
        for (int j = n - i; j > 0; j--) {
            printf(" ");

        }
        for (int k = 1; k <= i; k++) {
            printf("*");
        }

        printf("  ");

        for (int j = 1; j <= i; j++) {
            printf("*");
        }

        printf("\n");
    }


    return 0;
}