#include <stdio.h>
#include <string.h>

// ---- FIBONACCI ----
void add(char *a, char *b, char *result);
char* fibonacci(int n);

int main() {
    for (int i = 1; i < 101; i++) {
        printf("%d: %s\n", i, fibonacci(i));
    }

    return 0;
}

void add(char *a, char *b, char *result) {
    int i = strlen(a) - 1, j = strlen(b) - 1, k = 0, carry = 0;
    char temp[128];

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry + (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
        temp[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    for (int i = 0; i < k; i++) {
        result[i] = temp[k - 1 - i];
        result[k] = '\0';
    }
}

char* fibonacci(int n ) {
    static char result[128];
    static char f1[128], f2[128];

    if (n == 0) return "0";
    if (n == 1) return "1";

    strcpy(f1, "0");
    strcpy(f2, "1");

    for (int i = 2; i <= n; i++) {
        add(f1, f2, result);
        strcpy(f1, f2);
        strcpy(f2, result);
    }

    return result;
}