#include <stdio.h>

// ---- Tömb legkisebb és legnagyobb eleme? ----

typedef struct 
{
    int min;
    int max;
} MinMax;

MinMax array_min_max(int* arr, int size);

int main() {
    int array[] = {3, 0, 4, 1, 5, 9};

    int size = sizeof(array) / sizeof(array[0]);
    MinMax result = array_min_max(array, size);
    printf("Min: %d, Max: %d\n", result.min, result.max);
    return 0;
}

MinMax array_min_max(int* arr, int size) {
    MinMax result = {0, 0};

    if (size == 0) return (MinMax){0, 0};
    if (size == 1) return (MinMax){arr[0], arr[0]};

    for (int i = 0; i < size - 1; i += 2) {
        if (i + 1 >= size) return result;

        if (arr[i] < arr[i + 1]) {
            if (arr[i] < result.min) result.min = arr[i];
            if (arr[i + 1] > result.max) result.max = arr[i + 1];
        } else {
            if (arr[i + 1] < result.min) result.min = arr[i + 1];
            if (arr[i] > result.max) result.max = arr[i];
        }
    }

    return result;
}