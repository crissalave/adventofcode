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

void hack(char oShape, char *mShape) {
    // to win
    if (*mShape == 'Z') {
        if (oShape == 'A' || oShape == 'B') {
            *mShape = oShape + 24;
            return;
        } 
        if (oShape == 'C') {
            *mShape = oShape + 21;
            return;
        }
    }
    // to lose
    if (*mShape == 'X') {
        if (oShape == 'B' || oShape == 'C') {
            *mShape = oShape + 22;
            return;
        }
        if (oShape == 'A') {
            *mShape = oShape + 25;
            return;
        }
    }
}

int playRound(char *line) {
    char oShape = *line;
    char mShape = *(line + 2);
    int osValue = oShape - 64;

    // when draw
    if (mShape == 'Y') return osValue + 3;

    // hack to win or loss
    hack(oShape, &mShape);

    int msValue = mShape - 87;
    int magicNumber = mShape - oShape;

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