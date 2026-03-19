#include <stdio.h>

typedef char* string;

// karakter utolsó előfordulásának a helye egy sztringben

int rfind_char(string s, char c);
size_t strlen(const char *str);

int main() {

    printf("%d", rfind_char("Abba", 'b'));
    return 0;
}

int rfind_char(string s, char c) {
    int lastIndex = -1;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == c) lastIndex = i;
    }

    return lastIndex;
}

size_t strlen(const char *str) {
    const char *s;

    for (s = str; *s; s++);

    return (s - str);
}
