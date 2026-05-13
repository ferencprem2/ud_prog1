#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    int length;
    int capacity;
} darray;

darray *da_create() {
    darray *list = malloc(sizeof(darray));
    list->length = 0;
    list->capacity = 2;
    list->items = malloc(list->capacity * sizeof(int));

    return list;
}

void da_append(darray *self, int data) {
    if (self->length == self->capacity) {
        self->items = realloc(self->items, self->capacity * 2 * sizeof(int));
        self->capacity *= 2;
    }

    self->items[self->length] = data;
    self->length++;
}

void da_destroy(darray *self) {
    free(self->items);
    free(self);
}

int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main() {
    FILE *file = fopen("millions.txt", "r");
    if (file == NULL) {
        printf("Hiba! Nem sikerult megnyitni a millions.txt fajlt!\n");
        return 1;
    }

    darray *numbers = da_create();

    int value;
    while (fscanf(file, "%d", &value) == 1) {
        da_append(numbers, value);
    }
    fclose(file);

    qsort(numbers->items, numbers->length, sizeof(int), cmp_int);

    for (int i = 0; i < numbers->length; i++) {
        printf("%d\n", numbers->items[i]);
    }

    da_destroy(numbers);
    return 0;
}
