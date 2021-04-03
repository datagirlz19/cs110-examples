#include <stdio.h>
#include <stdlib.h>

// Recursive and Iterative Versions of Fibonacci
unsigned long long fibbo_recursive(int n);
unsigned long long fibbo_tail_recursive(unsigned long long prev,
                                        unsigned long long next,
                                        int n);
unsigned long long fibbo_iterative(int n);


int main(int argc, char **argv) {

    if (argc > 3 || argc < 2) {
        printf("Invalid number of args.\n");
        return 1;
    }

    // If we have three command line arguments we can pick the function to run
    //  i => iterative
    //  r (or any other letter) => recursive
    if (argc == 3) {
        if (argv[1][0] == 'i') {
            printf("Iterative: %lli\n", fibbo_iterative(atoi(argv[2])));
        }
        else if (argv[1][0] == 'r') {
            printf("Recursive: %lli\n", fibbo_recursive(atoi(argv[2])));
        }
        else if (argv[1][0] == 't') {
            printf("Tail Recursive: %lli\n", fibbo_tail_recursive(0, 1, atoi(argv[2])));
        }
        else {
            printf("Invalid option %c.\n", argv[1][0]);
            return 1;
        }
    }
    // If we only have two command line arguments we run both functions
    else {
        printf("Iterative: %lli\n", fibbo_iterative(atoi(argv[1])));
        printf("Tail Recursive: %lli\n", fibbo_iterative(atoi(argv[1])));
        printf("Recursive: %lli\n", fibbo_recursive(atoi(argv[1])));
    }

    return 0;
}

// Iterative Fibonacc is slightly more complex than
//   the recursive version, but performs consistently.
unsigned long long fibbo_iterative(int n) {
    unsigned long long current = 1;
    unsigned long long previous = 0;
    for (int i = 0; i < n; ++i) {
        unsigned long long temp = current;
        current += previous;
        previous = temp;
    }
    return previous;
}

/** Recursive Fibonacc is not ideal
 *    Larger numbers of n cause the process
 *    to take an unreasonable amount of time.
 *    ( At least this implementation ;) )
 */
unsigned long long fibbo_recursive(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        //Add the previous two values in the sequence together
        return fibbo_recursive(n - 1) + fibbo_recursive(n - 2);
}

/** A Tail Recursive Fibonacci performs very similar
 *   to the iterative version. What makes this "tail"
 *   recursive is that the recursice call is both the last
 *   statement in the function AND all the data necessary to
 *   perform the calculation for next recursive call is only passed
 *   as parameters. Notice difference between the two return
 *   statements in this version and the non-tail recusive
 *   version above. This version does not suffer the same
 *   problem of performing repeated and redundant calculations
 *   (see the tree of function calls from the slides).
 *   Additionally, since all the necessary data is passed within
 *   the parameters from one call to another, the computer can
 *   optimize the call stack by safely removing any recursive
 *   function calls that are not data dependent on subsequent calls.
 *  
 * You can read a brief discussion on tail recursion with additional
 *  examples here: https://www.geeksforgeeks.org/tail-recursion/
 */ 
unsigned long long fibbo_tail_recursive(unsigned long long prev,
                                        unsigned long long cur,
                                        int n) {
    if (n == 0)
        return prev;
    else if (n == 1)
        return cur;
    else {
        return fibbo_tail_recursive(cur, cur + prev, n-1);
    }   
}