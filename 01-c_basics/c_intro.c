// This is a line comment. Anything that comes after // is ignored by the compiler (gcc)

/*
    This is a block comment.
    Anything between the symbols will be ignored by the compiler and
    can span multiple lines.
*/

// The line below is used to include the library file stdio.h and gives access
//  to functions like printf(). The stdio.h is a part of the C standard library.
#include <stdio.h>

// Execution of a C program starts in the main() function.
//  The book uses int main(void) but the void is optional (and it's redundant in this case).
int main() {

    // Variables require a type and the types cannot change.
    // Variables store values in memory (RAM).
    // This following statement declars a variable x with a type of int and
    //  initializes x to the value 5.
    int x = 5;

    // A variable's value can change.
    x = 10;

    // Declares a variable y with type float. The value of y is unintialized
    //  this means the value is unknown (undefined) and can be any valid float variable.
    float y;

    // This is an initialization of because this is the first time y is assigned a value.
    y = 20.5;

    // Display text to the terminal window
    // We can print strings and variable.
    // The %i conversion specification is used to specify that we want to substitute that for
    //  an integer value and %f for float
    printf("x is %i\n", x);
    printf("y is %f\n", y);

    printf("Enter a new value for x: ");

    // scanf() reads input from the user.
    // We specifically want an integer (because of the %i).
    // To store the value in x we need to use &x.
    // Do not use "\n" for scanf().
    scanf("%i", &x);

    printf("x is now: %i\n", x);

    // By convention returning 0 means everything ran okay. Non-zero values are used for errors.
    return 0;
}

