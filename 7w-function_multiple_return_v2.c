#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int smallest;
    int largest;
    float average;
} Stats;

void fill(int n, int array[]);
Stats getItems(int n, int array[]);

int main() {
    srand(time(NULL));

    int n = 10;
    int array[10];

    fill(n, array);
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    Stats stats = getItems(n, array);
    printf("Legkisebb: %d\n", stats.smallest);
    printf("Legnagyobb: %d\n", stats.largest);
    printf("Átlag: %.2f\n", stats.average);

    return 0;
}

void fill(int n, int array[]) {
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 90 + 10; 
    }
}


Stats getItems(int n, int array[]) {
    int smallest = array[0];
    int largest = array[0];
    int avg = 0;

    for (int i = 0; i < n; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
        }
        if (array[i] > largest) {
            largest = array[i];
        }
        avg += array[i];
    }
    
    Stats stats = {smallest, largest, (float)avg / n};
    return stats;
}