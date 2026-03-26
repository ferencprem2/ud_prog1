#include <stdio.h>
#define BUFFER_SIZE 101

typedef char* string;

// ---- megadott leghosszabb szo ----

int strlen_m(string str);
int strcmp(const char* s1, const char* s2);

int main(void)
{
    char word[BUFFER_SIZE];
    int wordCount = 0;
    int longestLength = 0;

    printf("Adjon meg szavakat, '*' vegjelig!\n");

    while (1)
    {
        printf("Word: ");

        if (fgets(word, sizeof(word), stdin) == NULL)
        {
            break;
        }

        size_t length = strlen_m(word);

        if (length > 0 && word[length - 1] == '\n')
        {
            word[length - 1] = '\0';
            length--;
        }

        if (strcmp(word, "*") == 0)
        {
            break;
        }

        wordCount++;

        if ((int)length > longestLength)
        {
            longestLength = (int)length;
        }
    }

    printf("\n %d db szot adott meg. A leghosszabb szo %d karakter hosszu.\n", wordCount, longestLength);

    return 0;
}

int strlen_m(string ste){
    const char* s;

    for (s = ste; *s; s++);

    return (s - ste);
}

int strcmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}