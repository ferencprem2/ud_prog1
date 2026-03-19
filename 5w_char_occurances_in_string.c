#include <stdio.h>

typedef char* string;
// karakter előfordulásainak a száma egy sztringben

int char_count(string s, char c);
size_t strlen(const char *str);

int main() {

    printf("%d", char_count("Abba", 'b'));
    return 0;
}

int char_count(string s, char c) {
    int count = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == c) count++;
    }

    return count;
}

size_t strlen(const char *str) {
    const char *s;

    for (s = str; *s; s++);

    return (s - str);
}