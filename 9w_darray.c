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

void da_clear(darray *self) {
    for (int i = 0; i < self->length; i++) {
        self->items[i] = 0;
        self->length = 0;
    }
}

void da_destroy(darray *self) {
    free(self->items);
    free(self);
}


int main() {
    darray *li = da_create();

    for (int i = 0; i < 21; i++) {
        da_append(li, i);
    }

    da_clear(li);
    da_destroy(li);

    return 0;
}