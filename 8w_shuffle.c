#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int arr[], int n);

int main() {

    srand(time(NULL));

    const int n = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    shuffle(array, n);

    printf("Shuffled array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");


    return 0;
}

void shuffle(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}