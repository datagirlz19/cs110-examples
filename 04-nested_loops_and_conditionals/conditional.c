 /*
    Relational operators:
        <, >, <= , >=
    
    Equality operators:
        ==, !=
    
    Logical Operators:
        && - and
        || - or
        !  - not

        !x - This is 0 if x is nonzero and 1 if x is 0
 */

#include <stdio.h>

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%i", &num);

    // Using if, else, and else if
    if (num > 0) {
        printf("Your number is positive\n");
    }
    else if (num < 0) {
        printf("Your number is negative\n");
    }
    else {
        printf("Your number is zero\n");
    }

    // Test the numerical value of true and false
    if (num) {
        printf("Your number is considered true\n");
    }
    else {
        printf("Your number is considered false\n");
    }

    // Using logical operators
    if (num % 2 == 0 && num % 3 == 0) {
        printf("Your number is divisible by both 2 and 3\n");
    }

    return 0;
}