/*

Random Numbers in C

- The C standard library provides a function rand()
    - Before calling rand() we should call srand() and pass it a seed value
    - Each different seed value will result in a different pseudo-random
      sequence
    - srand(time(NULL)) will seed the generator with the current time
    - rand() returns a number between 0 and RAND_MAX
        - We can get random numbers within a smaller range using modular
          arithmetic
        - We can get random numbers between 0 and 1 with
          rand() / (double)RAND_MAX

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Returns a pseudo-random number between 1 and 6. Call srand() before calling
// this function.
int roll_die();

int main() {
    printf("rand() will return a number between 0 and %i\n", RAND_MAX);

    // time(NULL) gives the time as the number of seconds since January 1, 1970
    int seed = time(NULL);
    srand(seed);
    printf("The generator is seeded with the value %i\n", seed);

    printf("The first 10 numbers in the sequence:\n");
    for (size_t i = 0; i < 10; i++) {
        printf("%i\n", rand());
    }

    printf("Simulating rolling a die 10 times:\n");
    for (size_t i = 0; i < 10; i++) {
        printf("%i ", roll_die());
    }
    printf("\n");

    return 0;
}

int roll_die() {
    return rand() % 6 + 1;
}
