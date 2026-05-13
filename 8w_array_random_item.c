#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int choice(const int n, const int tomb[]);

int main() {
    srand(time(NULL));

    const int n = 10;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int random_item = choice(n, arr);
    printf("Random item: %d\n", random_item);

    return 0;
}


int choice(const int n, const int tomb[]) {
    int random_index = rand() % n;
    return tomb[random_index];
}