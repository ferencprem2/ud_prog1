#include <stdio.h>

// ---- Tartalmazza-e a tömb az adott értéket? ----

short contains(int* arr, int size, int value);

int main() {

    int array[] = {3, 0, 4, 1, 5, 9};
    int size = sizeof(array) / sizeof(array[0]);
    int value = 4;

    printf(contains(array, size, value) == 1 ? "Tartalmazza\n" : "Nem tartalmazza\n");
    return 0;
}

short contains(int* arr, int size, int value) {
    if (size == 0) return 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }

    return 0;
}