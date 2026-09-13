#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Generates and returns a random number within the given range.
 */
int choose_random_number(int min_limit, int max_limit)
{
    return rand() % (max_limit - min_limit + 1) + min_limit;
}

/*
 * Runs the guessing game.
 */
void play_game(void)
{
    const int min_number = 1;
    const int max_number = 100;

    int secret_number = choose_random_number(min_number, max_number);
    int user_guess;
    int attempt_count = 0;

    while (1)
    {
        printf("Type your guess: ");

        // Receive user guess.
        if (scanf("%d", &user_guess) != 1 || getchar() != '\n')
        {
            printf("Please enter a valid number.\n");

            // Clear invalid input from the input buffer.
            while (getchar() != '\n');

            continue;
        }

        attempt_count++;

        if (user_guess > secret_number)
        {
            printf("Too high!\n");
        }
        else if (user_guess < secret_number)
        {
            printf("Too low!\n");
        }
        else
        {
            printf("That's right! You did it in %d attempts!\n", attempt_count);
            break;
        }
    }
}

int main(void)
{
    // Seed the random number generator using the current time.
    srand(time(NULL));

    printf("I chose a number between 1 and 100. Try guessing!\n");

    // Start the game.
    play_game();

    return 0;
}
