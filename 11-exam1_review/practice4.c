#include <stdio.h>

void play_fizz_buzz(unsigned int rounds);

int main() {
    unsigned int game_rounds;
    printf("How many rounds of fizz buzz? ");
    scanf("%u", &game_rounds);
    
    play_fizz_buzz(game_rounds);
    
    return 0;
}

void play_fizz_buzz(unsigned int rounds) {
    for (unsigned int current_round = 1; current_round <= rounds; ++current_round) {
        
        // The number is not a multiple of 3 or 5
        if (current_round % 5 != 0 && current_round % 3 != 0) {
            printf("%i\n", current_round);
            // The continue skips the rest of this iteration
            continue;
        }
       
        // The number is a multiple of 3
        if (current_round % 3 == 0) {
            printf("fizz ");
        }
       
        // The number is a multiple of 5
        if (current_round % 5 == 0) {
            printf("buzz");
        }

        printf("\n");
    }
}
