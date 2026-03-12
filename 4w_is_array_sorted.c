#include <stdio.h>

// ---- Tömb rendezett-e? ----

short is_array_sorted(int* arr);

int main() {
    printf(is_array_sorted((int[]){1, 2, -500, 4, 5}) ? "Rendezett\n" : "Rendezetlen\n");
    return 0;
}

short is_array_sorted(int* arr) {
    if (sizeof(arr) == 0) {
        return 0;
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }

    return 1;
}
