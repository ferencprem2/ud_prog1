#include <stdio.h>

// ---- DIAMOND ----

int main() {

    char buffer[100];
    int n;

    printf("magassag: ");
    fgets(buffer, sizeof(buffer), stdin);

    if (sscanf(buffer, "%d", &n) != 1 || n < 1 || n % 2 == 0) {
        printf("Hiba: A program csak pozitiv paratlan egesz szamot fogad el!\n");
        return -1;
    }
    
    for (int i = 1; i <= n; i += 2) {
        
        for (int j = 0; j < (n - i) / 2; j++) {
            printf(" ");
        }
        
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = n - 2; i >= 1; i -= 2) {

        for (int j = 0; j < (n - i) / 2; j++) {
            printf(" ");
        }

        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}