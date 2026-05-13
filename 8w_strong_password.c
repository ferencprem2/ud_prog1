#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // least 8 chars
    // one lowercase
    // one uppercase
    // contains number
    // special char [.,;']

    char *password = malloc(12 * sizeof(char));
    int length = rand() % 5 + 8;

    for (int i = 0; i < length; i++) {
        int type = rand() % 4;

        if (type == 0) {
            password[i] = 'a' + rand() % 26;
        } else if (type == 1) {
            password[i] = 'A' + rand() % 26;
        } else if (type == 2) {
            password[i] = '0' + rand() % 10;
        } else {
            char special_chars[] = ".,;'";
            password[i] = special_chars[rand() % 4];
        }
    }

    printf("Password: %s\n", password);
    free(password);

    return 0;
}