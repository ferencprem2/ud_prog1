#include <stdio.h>

// ---- 1 -> 2 -> 3 -> 4 -> 5 ----

int main() {

    int n;

    printf("n: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        printf(i == n ? "%d" : "%d -> ", i);
    }

    return 0;
}