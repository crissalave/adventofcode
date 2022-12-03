#include <stdio.h>
#include <stdlib.h>

int totalScore;

void readLines(FILE *input);

int main() {
    FILE *input;
    input = fopen("02-input", "r");

    readLines(input);

    printf("Your total socre is: %i \n", totalScore);
}

int playRound(char *line) {
    char oShape = *line;
    char mShape = *(line + 2);
    int msValue = mShape - 87;
    int magicNumber = mShape - oShape;

    // when draw
    if (magicNumber == 23) return msValue + 3;
    // when I win
    if (magicNumber == 24 || magicNumber == 21) return msValue + 6;
    // when I loss
    return msValue;
}

void readLines(FILE *input) {
    char *buf = NULL;
    size_t size = 4;
    size_t ch;

    while ((ch = getline(&buf, &size, input)) != -1) {
        totalScore += playRound(buf);
    }
}