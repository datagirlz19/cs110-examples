/*

Why use functions?
    * Organize code
    * Allow code reuse / avoid code duplication

Functions in C
    * Named blocks of code
    * Executed when they are called
    * 0 or more parameters
    * May return a value

Syntax
    <return type> <name> (<parameter list>) { <body> }

Function Parameters
    * Variables which are local to the function
        * Could have the same names as variables in other functions, but they
          are distinct
    * The function caller supplies arguments which are copied to the parameters

Abstraction
    * Distinction between external properties and internal details
    * You can use a function if you know what it does, even if you do not know
      how it does it
    * You can write a function even if you do not know the exact context in
      which it will be used

*/


#include <stdio.h>

// This is a function prototype which defines the return type, name, and
// parameter list, but not the body. This is all the information that the
// compiler needs to know about the function in order to determine valid calls
// to this function.
// The book declares prototypes within main(). More common practice is to
// define them above main()
unsigned long long calculate_triangle_number(unsigned long long n);

int main() {
    unsigned long long n;
    printf("Enter n: ");
    scanf("%llu", &n);

    // Calculate a single triangle number n 
    unsigned long long triangle_num = calculate_triangle_number(n);

    printf("The %lluth triangle number is %llu\n", n, triangle_num);

    unsigned long long triangle_number_sum = 0;

    // Calculate the sum of the first n triangle numbers
    for (unsigned long long i = 1; i <= n; i++) {
        triangle_number_sum += calculate_triangle_number(i);
    }

    printf("The sum of the first %llu triangle numbers is %llu\n", n,
           triangle_number_sum);

    return 0;
}

unsigned long long calculate_triangle_number(unsigned long long n) {
    return n * (n + 1) / 2;
}
