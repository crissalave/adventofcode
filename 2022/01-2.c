#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

// data structures
typedef struct Elf {
    int calories;
    struct Elf *next;
    struct Elf *prev;
} Elf;

// constants
Elf *ELVES_LIST;
int ELFS_COUNT;

// function headers
void sort(Elf *LIST);
void getNumbers(FILE *input);

int main() {
    FILE *input = fopen("01-input", "r");
    ELVES_LIST = malloc(sizeof(Elf));

    getNumbers(input);

    sort(ELVES_LIST);

    fclose(input);
    return 0;
}

void resetTmpNumber(char *number) {
    int len = strlen(number);

    for (int i = 0; i < len; i++) {
        number[i] = '\0';
    }
}

void addElf(int totalCalories, Elf *LIST) {
    Elf *new = malloc(sizeof(Elf));

    new->calories = totalCalories;
    new->next = LIST->next;

    if (LIST->next != NULL)
        LIST->next->prev = new;

    LIST->next = new;
}

void getNumbers(FILE *input) {
    char tmpStringNumber[6];
    int kcal;
    int totalKcal; // total calories of each elf

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
            //if (totalKcal > maxKcal) maxKcal = totalKcal; 

            // save elf total calories in a double linked list
            addElf(totalKcal, ELVES_LIST);
            ELFS_COUNT+=1;

            totalKcal = 0; // reset totalkcal
            continue;
        }

        // since none of the if statement are not executed there is no break lines
        breakLines = 0; 
        tmpStringNumber[i] = c;
        i++;
    }

}

void saveIntoArray(Elf *LIST, int calories[]) {
    Elf *tmp = LIST->next;

    for (int i = 0; i < ELFS_COUNT; i++) {
        calories[i] = tmp->calories;
        tmp = tmp->next;

        if (tmp != NULL) free(tmp->prev);
    }
}

int getTopThreeCalories(int calories[])  {
    int total;

    for (int i = ELFS_COUNT - 1; i >= ELFS_COUNT - 3; i--) {
        total += calories[i];
    }

    return total;
}

void sort(Elf *LIST) {
    int calories[ELFS_COUNT];

    saveIntoArray(LIST, calories);

    // sort calories array with insertion sort
    for (int i = 1; i < ELFS_COUNT; i++) {
        int firstUnsortedElement = calories[i];
        int lastSortedElement = i - 1;

        while (lastSortedElement >= 0 && calories[lastSortedElement] > firstUnsortedElement) {
            calories[lastSortedElement + 1] = calories[lastSortedElement];
            lastSortedElement--;
        }

        calories[lastSortedElement + 1] = firstUnsortedElement;
    }

    int topThree = getTopThreeCalories(calories);
    printf("Total of top 3 elves calories: %i \n", topThree);
}