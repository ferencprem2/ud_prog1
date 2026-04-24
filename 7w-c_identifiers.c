#include <stdio.h>
#include <string.h>

typedef char* string;

int isAlphanumeric(string str);
int isValidFirstChar(string str);


int main() {
    
    char str[100];
    printf("Adj meg stringeket '*' végjelig!: \n");
    do
    {
        printf("Input: ");
        fgets(str, 100, stdin);
        str[strcspn(str, "\n")] = '\0';

        printf("\n");
        if (strlen(str) < 1) {
            printf("NO\n");
            continue;
        }

        if (!isValidFirstChar(str)) {
            printf("NO\n");
            continue;
        
        }


        if (!isAlphanumeric(str)) {
            printf("NO\n");
            continue;
        }


        printf("YES\n");

    } while (strcmp(str, "*\n") != 0);
    

    

    return 0;
}

int isAlphanumeric(string str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= '0' && str[i] <= '9'))) {
            return 0; 
        }
    }
    return 1;
}

int isValidFirstChar(string str) {
    char firstChar = str[0];
    return (firstChar >= 'a' && firstChar <= 'z') || (firstChar >= 'A' && firstChar <= 'Z') || firstChar == '_';
}