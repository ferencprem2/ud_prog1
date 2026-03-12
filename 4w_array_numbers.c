#include <stdio.h>

void print_array(int* arr, int size);

int main() {

    int array[] = {3, 0, 4, 1, 5, 9};
    int size = sizeof(array) / sizeof(array[0]);

    print_array(array, size);

    return 0;
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
}