#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int array[]);
void getItems(int n, int array[], int *smallest, int *largest, float *average);


int main() {
    srand(time(NULL));

    int n = 10;
    int array[10];

    
    fill(n, array);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    int smallest = array[0];
    int largest = array[0];
    float avg = 0;

    getItems(n, array, &smallest, &largest, &avg);
    printf("Legkisebb: %d\n", smallest);
    printf("Legnagyobb: %d\n", largest);
    printf("Átlag: %.2f\n", avg / n);

    return 0;
}

void fill(int n, int array[]) {
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 90 + 10; 
    }
}

void getItems(int n, int array[], int *smallest, int *largest, float *average) {
    *smallest = array[0];
    *largest = array[0];
    *average = 0;

    for (int i = 0; i < n; i++) {
        if (array[i] < *smallest) {
            *smallest = array[i];
        }
        if (array[i] > *largest) {
            *largest = array[i];
        }
        *average += array[i];
    }
}