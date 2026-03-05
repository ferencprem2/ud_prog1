#include <stdio.h>

int main() {

    int sum = 0;

    for (int i = 32; i <= 126; i++) {
        printf("%d: %c\n", i, i);

        i >= 65 && i <= 90 ? sum += i : sum;
    }

    printf("Osszeg: %d", sum);
    return 0;
}