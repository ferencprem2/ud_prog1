#include <stdio.h>

// ---- különböző elemek száma ----

int sort(int array[], int size);

int main() {
    int inputChar;
    int counter = 0;
    int array[98];

    printf("Adjon meg 0 vegjelin szamokat az [1, 99] invervallumbol! ");
    scanf("%d", &inputChar);
    array[0] = inputChar;
    counter += 1;


    if (inputChar < 1 || inputChar > 99) {
        printf("Ez a szam kivul esik az elfogathato intervallumon!\n");
        return 1;
    }

    while (inputChar != 0) {
        printf("Szam: ");
        scanf("%d", &inputChar);
        array[counter] = inputChar;
        counter += 1;
    }

    printf("%d db kulonbozo szam lett megadva\n", counter);
    sort(array, counter);
    for (int i = 0; i < counter; i++) {
        printf("%d ", array[i]);
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