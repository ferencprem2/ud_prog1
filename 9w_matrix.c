#include <stdio.h>
#include <stdlib.h> 

#define DIM 6
void print_matrix(int matrix[DIM][DIM]);

int main() {
    int matrix[DIM][DIM] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}
    };
    
    print_matrix(matrix);
    return 0;
}

void print_matrix(int matrix[DIM][DIM]) {
    for (int i = 0; i < DIM; i++) {
        printf("%d", matrix[i][DIM - i - 1]);
        printf("\n");
    }
}