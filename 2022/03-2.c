#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int MAX_LEN = 80;

char *findCommon(char *s1, char *s2, char *s3);

int main() {
    FILE *input;
    input = fopen("03-input", "r");
    //input = fopen("test-input", "r");

    char *items = NULL;
    size_t len;
    size_t lineSize = 100;
    size_t line;

    char a[MAX_LEN];
    char b[MAX_LEN];
    char c[MAX_LEN];
    char dp;
    char dp2;
    long p = 0;

    char *nul;
    int val;
    int count = 0;
    char *ids[] = {a, b, c};
    while ((line = getline(&items, &lineSize, input)) != -1) {
        if ((nul = strchr(items, '\n')) != NULL) {
            *nul = '\0';
        }

        len = strlen(items);

        if (count < 3) {
            strncpy(ids[count], items, len);
            count++;
            if (count < 3) continue;
        }

        dp = *findCommon(a, b, c);
        if (dp == '\0') break;

        // clear strings
        while (count > 0) {
            count--;
            memset(ids[count], '\0', len);
        }

        if (islower(dp)) {
            val = ((int)dp - (int)'a')+1;
            p += val;
            continue;
        }
        val = (int)dp - 38;
        p += val;
    }
    printf("%i\n", p);
}

char *findCommon(char *s1, char *s2, char *s3) {
    if (s1 == NULL || s2 == NULL || s3 == NULL) return NULL;

    char *p = NULL;
    char *buf;

    while (*s1) {
        buf = strchr(s2, *s1);
        if (buf) {
            if (strchr(s3, *buf)) return buf;
            s1++;
            continue;
        }
        s1++;
    }

    return NULL;
}