/*

Command Line Arguments

- Example command: ./program
    - 1 argument, the string "./program"
- Another example command: gcc program.c
    - 2 arguments: "gcc" and "program.c"
- When a command is run on the command line it contains 1 or more arguments
- The operating system places these arguments into an array of strings which
  we can access
    - A string is an array of char, so its type is char *
    - We receive the command line arguments as an array of strings (array of
      pointers to char)
        - This array's variable has type char **
        - To access the arguments we have to use a different prototype for
          main()
        - int main(int argc, char **argv)
        - argc is the number of arguments, argv is the array of pointers to
          strings
        - The operating system passes these to main() for us

*/

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    printf("Here are the command line arguments:\n");
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    printf("\n");

    printf("Here are the individual characters from argv[0]:\n");
    size_t length = strlen(argv[0]);
    for (size_t i = 0; i < length; i++) {
        printf("%c\n", argv[0][i]);
    }

    return 0;
}
