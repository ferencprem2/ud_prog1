#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int array[], int bottomLimit, int topLimit);
int contains(int n, int array[], int number);
void sort(int n, int array[]);

int main() {
    srand(time(NULL));
    int n = 0;
    int bottomLimit = 0;
    int topLimit = 0;

    printf("Hány számot szeretnél generálni? ");
    scanf("%d", &n);

    printf("Alsó határ? ");
    scanf("%d", &bottomLimit);

    printf("Felső határ? (zárt intervallum)");
    scanf("%d", &topLimit);



    int array[n];
    fill(n, array, bottomLimit, topLimit);

    sort(n, array);

    printf("A generált számok: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

void fill(int n, int array[], int bottomLimit, int topLimit) {
    for (int i = 0; i < n; i++) {
        int currentNum = rand() % (topLimit - bottomLimit + 1) + bottomLimit;
        if (contains(n, array, currentNum)) {
            i--;
            continue;
        }
        array[i] = currentNum;
    }
}

int contains(int n, int array[], int number) {
    for (int i = 0; i < n; i++) {
        if (array[i] == number) {
            return 1;
        }
    }
    return 0;
}

void sort(int n, int array[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}