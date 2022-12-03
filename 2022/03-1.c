#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int MAX_LEN = 40;

void strncpy2(char *dest, char *src, size_t start, size_t end);

int main() {
    FILE *input;
    input = fopen("03-input", "r");
    //input = fopen("test-input", "r");

    char *items = NULL;
    size_t len;
    size_t lineSize = 80;
    size_t line;

    char firstPart[MAX_LEN];
    char secondPart[MAX_LEN];
    char dp;

    long p = 0;
    char *nul;
    while ((line = getline(&items, &lineSize, input)) != -1) {
        if ((nul = strchr(items, '\n')) != NULL) {
            *nul = '\0';
        }

        len = strlen(items);
        size_t n = len/2;

        strncpy(firstPart, items, n);
        strncpy2(secondPart, items, n, len);

        dp = *strpbrk(firstPart, secondPart);
        if (dp == '\0') break;

        // clear strings
        memset(firstPart, '\0', n);
        memset(secondPart, '\0', n);

        if (islower(dp)) {
            p += ((int)dp - (int)'a')+1;
            continue;
        }
        p += (int)dp - 38;
    }
    printf("%i\n", p);
}

void strncpy2(char *dest, char *src, size_t start, size_t end) {
    for (int i = start; i < end; i++) {
        dest[i-start] = src[i];
    }
}