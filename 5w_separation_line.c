#include <stdio.h>


// elválasztó vonal
void line(char c, int length);

int main() {

    printf("Hello\n");
    line('-', 40);
    printf("World\n");
    
    return 0;
}

void line(char c, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", c);
    }
    printf("\n");
}