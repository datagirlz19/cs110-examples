/*

Modules in C
    * Many programs are too complex to live in one file
    * Complex programs are organized into modules
    * A module containing main() is referred to as an entry point
    * A module in C that is not an entry point is typically divided into 2 files
        * Header file
            * Extension is .h
            * Contains the function prototypes for the module (the module's
              interface)
            * Reading a module's header file is sometimes enough to figure out
              how to use the functions in the module
        * Implementation file
            * Extension is .c
            * Contains the implementations of each function declared in the
              header

Compliling Modules
    * Typically each module is independently compiled into an object file
    * gcc can link object files together to form an executable
    * Compiling object files separately is advantageous because when a single
      implementation file is edited, only one object file needs to be
      re-compiled

make
    * Tool to automate compiling
    * Saves time and makes the compiling process less error prone
    * Rules for compiling are defined in a file named Makefile
    * The entire project can be compiled by typing make

*/

#include <stdio.h>
#include <stdbool.h>

#include "triangle.h"

void test_is_triangle(double side_a, double side_b, double side_c,
                      bool expected);

int main() {
    // all sides equal
    test_is_triangle(1, 1, 1, true);
    // a + b is slightly larger than c
    test_is_triangle(1.001, 2, 3, true);
    // a + c is slightly larger than b
    test_is_triangle(2, 3, 1.001, true);
    // a + b is slightly larger than c
    test_is_triangle(2, 1.001, 3, true);

    // a + b < c
    test_is_triangle(1, 2, 10, false);
    // a + b == c
    test_is_triangle(1, 2, 3, false);
    // a + c < b
    test_is_triangle(1, 5, 1, false);
    // a + c == b
    test_is_triangle(1, 2, 1, false);
    // b + c < a
    test_is_triangle(3, 1, 1, false);
    // b + c == a
    test_is_triangle(3, 2, 1, false);

    return 0;
}

void test_is_triangle(double side_a, double side_b, double side_c,
                      bool expected) {
    if (is_triangle(side_a, side_b, side_c) != expected) {
        printf("Tests failed for values %lf, %lf, %lf!\n", side_a, side_b,
               side_c);
    }
}
