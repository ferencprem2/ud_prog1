#include <stdio.h>  

// ---- Megrajzolható háromszögek ----

short valid_triangle(int a, int b, int c);

int main() {
    printf(valid_triangle(3, 4, 5) ? "Megrajzolhato\n" : "Nem rajzolhato meg\n");

    return 0;
}

short valid_triangle(int a, int b, int c) {
    return ((a + b > c) && (b + c > a) && (c + a > b)) ? 1 : 0;
}