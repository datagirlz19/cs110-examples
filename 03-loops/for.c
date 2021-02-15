#include <stdio.h>

int main() {
    int countdown;

    for (countdown = 10; countdown > 0; --countdown) {
        printf("%i\n", countdown);
    }
    
    printf("Blastoff!\n");

    printf("The final value of countdown is %i\n", countdown);
    return 0;
}