/*

Passing Arrays to Functions

* Arrays are not copied when passed to functions
    * Changing the value of an element in an array passed to a function changes
      the element in the original array
    * Use the keyword const if elements will not change
        * The compiler will complain if you accidentally write code that
          changes the value of an element
        * An array parameter marked as const communicates to people using the
          function that the function will not alter the array elements

* size_t
    * Unsigned integer type used to represent sizes
    * Wide enough range to represent the largest possible array on a system
    * Also an appropriate type to use for array indexes
    * Use %zu with printf() and scanf()

*/

#include <stdio.h>

// Returns the largest element in the given array with the given size. The
// array must have at least one element.
int max_value(const int array[], size_t size);

// After this function returns, each element at each index i of the given
// array will store i * i.
void fill_with_squares(int array[], size_t size);

// Prints each element of the given array. The elements will be separated by
// spaces in the output.
void print_array(const int array[], size_t size);

int main() {
    int array[] = {1, -1, 10, -50, 46, 3};

    printf("The largest element in the array is %i\n", max_value(array, 6));

    fill_with_squares(array, 6);

    printf("Here are the new contents of the array:\n");
    print_array(array, 6);
    printf("\n");

    return 0;
}

void fill_with_squares(int array[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = i * i;
    }
}

int max_value(const int array[], size_t size) {
    int max = array[0];

    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

void print_array(const int array[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%i ", array[i]);
    }
}
