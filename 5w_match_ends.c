#include <stdio.h>

typedef char* string;
// match_ends

int match_ends(int n, string words[]);
int strlen(const char* str);

int main() {
    string words[] = {"aba", "xyz", "aa", "x", "bbb"};
    printf("%d", match_ends(5, words));
    return 0;
}

int strlen(const char* str) {
    const char* s;

    for (s = str; *s; s++);

    return (s - str);
}

int match_ends(int n, string words[]) {
    int count = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (words[i][0] == words[i][strlen(words[i]) - 1]) 
            count++; 
    }

    return count;
}