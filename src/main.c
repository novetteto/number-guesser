#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Read the Github README

int main(void)
{
    int play = 1;

    // Allocate max_tries and max_range to avoid reallocating them every loop iteration
    int max_tries;
    int max_range;

    srand(time(NULL));

    while (play == 1) {
        int guess = 0;
        int tries = 0;

        printf("\nPlease enter the max range of the number: ");
        scanf("%d", &max_range);

        printf("\nGenerating number from range %d....", max_range);

        int number = (rand() % max_range) + 1;

        printf("\nPlease enter the max tries for guessing: ");
        scanf("%d", &max_tries);

        printf("\nGood luck! Guess a number between 1 and %d, you have %d tries: ", max_range, max_tries);
        scanf("%d", &guess);

        tries++;

        while (guess != number && tries < max_tries) {
            if (tries == max_tries -1) {
                printf("\nYou have one last try: ");
                scanf("%d", &guess);
                tries++;
            } else {
                printf("\nWrong try again, remaining tries(%d): ", max_tries - tries);
                scanf("%d", &guess);
                tries++;
            }
        }

        char const *TRIES_WORD = tries > 1 ? "tries" :  "try";

        if (guess == number) {
            printf("\nCongrats! The number you guessed was correct!"
                   " you guessed it in %d %s!, the right number: %d", tries, TRIES_WORD, number);
        } else {
            printf("You lost, the number was %d.", number);
        }

        printf("\nDo you wish to play again?\nPress 1 if yes.2\nOtherwise press any number if no: ");
        scanf("%d", &play);

        if (play != 1) {
            play = 0;
        }
    }

    printf("Goodbye!\n");

    return 0;
}
