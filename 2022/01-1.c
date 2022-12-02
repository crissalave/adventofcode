#include <stdio.h>
#include <string.h>
#include <strings.h>

void resetTmpNumber(char *number) {
    int len = strlen(number);

    for (int i = 0; i < len; i++) {
        number[i] = '\0';
    }
}

int main() {
    FILE *input = fopen("01-input", "r");
    char tmpStringNumber[6];
    int kcal;
    int totalKcal; // total calories of each elf
    int maxKcal; // greater calories value

    int i = 0;
    int breakLines = 0; // helper variable to count the special character 10 for new line
    while (1 && !feof(input)) {
        int c = getc(input);

        // end of line
        if (c == 10 && breakLines == 0) {
            // optional add null character at the of the string, but it is not necesary by the sscanf function
            // tmpStringNumber[i] = c;

            breakLines+= 1;
            sscanf(tmpStringNumber, "%i", &kcal); // convert string number to integer
            totalKcal += kcal;

            resetTmpNumber(tmpStringNumber); // delete all characters from the tmp string
            i = 0; // reset string index

            continue;
        }

        // blank line
        if (c == 10 && breakLines == 1) {
            breakLines = 0; // reset break lines

            // after each blank line check if the total calories is greater tha the previous
            if (totalKcal > maxKcal) maxKcal = totalKcal; 

            totalKcal = 0; // reset totalkcal
            continue;
        }

        // since none of the if statement are not executed there is no break lines
        breakLines = 0; 
        tmpStringNumber[i] = c;
        i++;
    }

    printf("Elf with most calories: %d \n", maxKcal);
    fclose(input);
    return 0;
}