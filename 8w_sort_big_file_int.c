#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i) {
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) 
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }

}

int main()
{
    FILE *file = fopen("millions.txt", "r");

    if (file == NULL)
    {
        printf("Hiba! Nem sikerült megnyitni az input.txt fájlt!\n");
        return 1;
    }

    int capacity = 100;
    int *numbers = malloc(capacity * sizeof(int));

    int count = 0;
    int value;

    while (fscanf(file, "%d", &value) == 1)
    {
        if (count == capacity)
        {
            capacity *= 2;
            int *tmp = realloc(numbers, capacity * sizeof(int));
            if (tmp == NULL)
            {
                printf("Hiba! Nem sikerült újraallokálni a memóriát!\n");
                free(numbers);
                fclose(file);
                return 1;
            }
            numbers = tmp;
        }
        numbers[count++] = value;
    }
    fclose(file);

    heapSort(numbers, count);

    printf("\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %d \n", i, numbers[i]);
    }


    free(numbers);
    return 0;
}