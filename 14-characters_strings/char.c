/*

* char
    * A type that stores a single character
    * A literal char is surrounded by single quotes
    * Input and output
        * Use %c with printf() and scanf()
        * Use putchar() to print a single character
        * Use getchar() to read a single character
    * Escape characters with a backslash (\)
        * '\n' is a newline
        * '\t' is a tab
    * One byte in size
        * 8 bits
        * 2^8 = 256 different values
        * Can only represent English characters, certain characters with
          accent marks, punctuation marks, numbers, and some other special
          characters
*/

#include <stdio.h>

int main() {
    char character = 'c';

    printf("%c\n", character);

    putchar(character);
    putchar(character);
    putchar(character);

    putchar('\n');

    char user_input = getchar();

    putchar(user_input);
    putchar('\n');

    return 0;
}
