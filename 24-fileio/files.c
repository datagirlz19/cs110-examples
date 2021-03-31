/*

Files

* File - a named sequence of bytes stored on a file storage device
* The name of a file is also called its path
    * Full path - unambiguous full name of a file
        /Users/dguarnera/Desktop/file.c
    * Relative path - path relative to the current working directory
        file.c
    * Working directory
        * The current directory in the terminal, or the directory you have
          open in Finder or Windows Explorer
        * Every running program has a working directory
    * File Extension
        * A suffix of a file name that indicates its type
        * Usually delimited from the rest of the filename with a .
            file.c - extension is .c
        * Used by programs and operating systems to determine how to interpret
          the file
* Storage devices - hard drives, solid state drives, thumb drives, Blu-Ray
                    discs, etc.
* Files in C
    * C standard library provides functions for working with files
    * Files must be opened by name before reading or writing
        * fopen(<filename>, <mode>)
            * The filename and the mode are strings (type const char *)
            * Modes
                * "r" - read
                * "w" - write
                * "a" - append
                * There are more, but we will just use these
            * Returns a pointer to a FILE structure
                * To open a file named file.c for reading:
                    FILE *fp = fopen("file.c", "r");
                * Returns NULL if the file could not be opened
        * fclose(FILE *file_pointer) - closes a file
        * fgetc(FILE *file_pointer) - reads a character from a file
        * fscanf() and fprintf() work like scanf() and printf(), but also take a
          FILE pointer as the first argument

This example program prints out the contents of the file input.txt, writes
2 lines to the file output.txt, and appends a line to the file append.txt.
The file input.txt must exist.

*/

#include <stdio.h>

int main() {
    // Open input.txt in read mode
    FILE *fp = fopen("input.txt", "r");

    // If input.txt does not exist, or if there was some other issue when
    // opening the file (such as insufficient privileges), then fopen() will
    // have returned NULL
    if (fp == NULL) {
        printf("Could not open input.txt\n");
        return 1;
    }

    // Read and print each character in the input file
    int c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    fclose(fp);

    // Open output.txt in write mode. If the file already exists, its contents
    // will be overwritten
    FILE *fp_to_write = fopen("output.txt", "w");

    if (fp_to_write == NULL) {
        printf("Error opening output.txt\n");
        return 1;
    }

    // While a file is open in write mode, subsequent calls to fprintf() will
    // keep writing additional data to the file, so both of these lines will
    // be written to the file.
    fprintf(fp_to_write, "Hello file! How are you?\n");
    fprintf(fp_to_write, "I hope you are well\n");

    fclose(fp_to_write);

    // Open append.txt in append mode. The contents of the file will not be
    // overwritten. Writing using this file pointer will append data to the
    // file
    FILE *fp_to_append = fopen("append.txt", "a");

    if (fp_to_append == NULL) {
        printf("Error opening append.txt\n");
        return 1;
    }

    // This line will be appended to the existing contents of the file
    fprintf(fp_to_append, "Here is a line to append!\n");

    fclose(fp_to_append);

    // Open numbers.txt in read mode
    FILE *numbers_fp = fopen("numbers.txt", "r");

    if (numbers_fp == NULL) {
        printf("Error opening numbers.txt\n");
        return 1;
    }

    // Read as many integers from the file as possible using fscanf(), and
    // print them out as they are read
    int input;
    while (fscanf(numbers_fp, "%i", &input) == 1) {
        printf("%i\n", input);
    }

    fclose(numbers_fp);

    return 0;
}
