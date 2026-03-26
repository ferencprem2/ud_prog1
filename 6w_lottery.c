#include <stdio.h>
#include <stdlib.h>

// ---- lotto ----

int contains(int array[], int size, int value);
int sort(int array[], int size);

int main() {

    int n;
    int min;
    int max;


    printf("Hany db random szamot ker? ");
    scanf("%d", &n);

    int *numbers = malloc(n * sizeof(int));

    printf("Also hatar: ");
    scanf("%d", &min);

    printf("Felso hatar (zart intervallum): ");
    scanf("%d", &max);

    if (min >= max) {
        printf("Hiba! A felso hatar nagyobbnak kell lennie az also hatarnal.\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        int randomNum = min + rand() % (max - min);
        if (contains(numbers, n, randomNum)) {
            i--;
            continue;
        }
        numbers[i] = randomNum;
        printf("%d ", randomNum);
    }

    sort(numbers, n);

    printf("A generalt random szamok: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}

int contains(int array[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return 1;
        }
    }
    return 0;
}

int sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return 0;
}