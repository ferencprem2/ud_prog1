#include <stdio.h>

// ---- Páros? Páratlan? ----

int is_even(int n);
int is_odd(int n);

int main() {

    printf("4: %s\n", is_even(4) ? "Paros" : "Paratlan");
    printf("5: %s\n", is_odd(5) ? "Paratlan" : "Paros");

    return 0;
}

int is_even(int n) {
    return (n % 2 == 0) ? 1 : 0;
}

int is_odd(int n) {
    return is_even(n) ? 0 : 1;
}