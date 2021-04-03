#include <stdio.h>


unsigned int triangle_number(unsigned int n);


int main() {
    unsigned int n = 4;

    printf("The %uth triangle number is %u\n",
           n, triangle_number(n));

    return 0;
}


unsigned int triangle_number(unsigned int n) {
    if (n == 0) {
        // base case
        return 0;
    }
    else {
        // Add n to the result of the next function call
        return n + triangle_number(n - 1);
    }
}
