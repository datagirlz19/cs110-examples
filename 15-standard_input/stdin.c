/*

Standard Input (stdin)

* Stream of data available to the program
* scanf() and getchar() both read from standard input
* Keyboard input
    * Usually when a program is running in the terminal, input from the keyboard
      is sent to the program's stdin
    * New keyboard input is not available from stdin until the user presses
      enter
* Input from files
    * The contents of a file can also be used as a program's stdin
    * Command line syntax: ./program < filename
        * The contents of filename will be used as stdin for program
        * If < is reversed to > the output will be written to the file,
          overwriting anything that was there
* Blocking
    * A function that reads from stdin (like scanf()) will block (pause
      execution) until new data is available from stdin
* EOF (end of file)
    * When there is no more data available from stdin, the special EOF value
      is returned from scanf() and getchar()
    * EOF is an int (usually -1)
    * When stdin comes from a file and there is no more data in the file, we
      have reached EOF
    * ctrl+d sends EOF in the terminal

*/

#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    return 0;
}
