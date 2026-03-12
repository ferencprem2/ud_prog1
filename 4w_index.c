#include <stdio.h>

// ---- Adott érték indexe a tömbben ----

int index_of(int* arr, int size, int value);

int main() {

    int array[] = {3, 0, 4, 1, 5, 9};
    int size = sizeof(array) / sizeof(array[0]);
    int value = 4;
    printf("Index: %d\n", index_of(array, size, value));

    return 0;
}

int index_of(int* arr, int size, int value) {
    if (size == 0) return -1;

    int index = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return index;
        }
        index++;
    }

    return -1;
}