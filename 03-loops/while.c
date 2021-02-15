#include <stdio.h>

int main() {
    int countdown = 10;

    while (countdown > 0) {
        printf("%i\n", countdown);
        
        /* 
            Could also subtract by one using:
                countdown -= 1
                --countdown (this is called pre-decrement)
                countdown-- (this is called post-decrement) 
        */
        countdown = countdown - 1;
    }

    printf("Blastoff!\n");

    printf("The final value of countdown is %i\n", countdown);

    return 0;
}