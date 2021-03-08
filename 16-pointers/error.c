/*
    Code example illustrating how and why you may want to return
    a value from a function using the return statement, and also
    produce a result that is returned via pointer from a function.
*/

#include <stdio.h>

/**
 * 
 * Computes the sum of a sequence of positive numbers
 * 
 * preconditions:
 *  size - must be > 0
 *  array - must contain only positive numbers
 * postcondidtions:
 *  sum - returned via pointer will be the sum of all numbers in
 *          the array
 *  function will return an error value 0 if the array contains
 *      negative values or the size is <= 0. A value of 1 will be
 *      returned when the function succeeds.
 */
int sequence_sum(const int array[], size_t size, unsigned *sum);

int main() {

    // Will use sum for all calculations
    unsigned sum;

    // Normal condition (SUCCESS)
    int array[] = {1, 2, 3, 4};
    size_t size = 4;
    
    if (sequence_sum(array, size, &sum)) {
        printf("Sum is: %i\n", sum);
    }
    else {
        printf("ERROR!\n");
    }

    // Negative value in array (FAIL)
    int negative_array[] = {1, 2, -3};
    size_t negative_size = 4;

    if (sequence_sum(negative_array, negative_size, &sum)) {
        printf("Sum is: %i\n", sum);
    }
    else {
        printf("ERROR!\n");
    }
    
    // Bad array size (FAIL)
    int error_size_array[] = {1};
    size_t empty_size = 0;

    if (sequence_sum(error_size_array, empty_size, &sum)) {
        printf("Sum is: %i\n", sum);
    }
    else {
        printf("ERROR!\n");
    }
}

int sequence_sum(const int array[], size_t size, unsigned *sum) {
    // Error State
    if (!(size > 0))
        return 0; 

    *sum = 0;
    for (size_t i = 0; i < size; ++i) {
        // Error State
        if (array[i] < 0)
            return 0;

        *sum += array[i];
    }

    // No errors
    return 1;
}

