#include <stdio.h>

// ---- LEGNAGYOBB OSZTO ----

int biggest_divisor(int n);

int main() {
    
    for (int i = 1; i <= 50; i++) {
        printf("%d: %d\n", i, biggest_divisor(i));
    } 

    return 0;
}

int biggest_divisor(int n) {
    int biggest = 1;

    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            biggest = i;
        }
    }

    return biggest;
}