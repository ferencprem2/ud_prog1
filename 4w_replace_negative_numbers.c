#include <stdio.h>

void replace_negative_numbers(int* arr, int size);

int main() {

    int array[] = {3, -1, 4, -5, 0, 9};
    int size = sizeof(array) / sizeof(array[0]);

    
    printf("Eredeti tomb: ");
    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }

    replace_negative_numbers(array, size);


    printf("\nModositott tomb: ");
    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }

    return 0;
}

void replace_negative_numbers(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            arr[i] = 0 - arr[i];
        }
    }
}