/*

Pointers

- A pointer is a variable that stores an address (a number which is a location
  in memory, or RAM)
- Through a pointer, a value can be accessed indirectly by its address rather
  than by its original name
- Declare pointers with the type of the data it will point to and an *
- Pointer to an int
    - Several syntax options:
        - int *p;
        - int* p;
        - int * p;
    - Assign the address of variable i to p:
        p = &i;
    - Declare a pointer p and make it point to i:
        int *p = &i;
    - Dereferencing
        - Access the data located at the address stored by a pointer
            *p = 5;
        - If p is a pointer to i, *p is the value of i

*/

#include <stdio.h>

int main() {
    int x;
    // Using the & operator gets the address of a variable. When we call
    // scanf() like this, we are allowing scanf() to access x using its address
    scanf("%i", &x);

    int *pointer_to_x = &x;

    printf("x: %i\n", x);
    // This also prints the value of x, because dereferencing the pointer to x
    // gives us the value of x
    printf("*pointer_to_x: %i\n", *pointer_to_x);
    // This prints the address of x
    printf("pointer_to_x: %zu\n", pointer_to_x);

    return 0;
}
