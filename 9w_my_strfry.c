#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef char* string;

void my_strfry(char *s);


int main() {
    srand(time(NULL));

    char s[] = "Hello World";   

    printf("%s\n", s);

    my_strfry(s);

    printf("%s\n", s);

    return 0;
}


void my_strfry(char *s) {
    int len = strlen(s);
    for (int i = len - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}