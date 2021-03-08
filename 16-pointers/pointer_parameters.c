/*

Pointer Function Parameters

- The address of a variable is passed to a function through a pointer parameter
- The function can change the data pointed to by the pointer
- This is another way to achieve multiple return values
    - Rather than returning values through the return mechanism, we can
      change the values of variables outside the function, effectively
      returning those values

*/

#include <stdio.h>

// Calculate both the square and cube of x, and return them via pointers
void square_and_cube(int x, int *square_pointer, int *cube_pointer);

// Calculate the sum and average of an array of integers and return the values
// via pointer.
void sum_and_average(const int array[], size_t size, int *sum, double *average);

int main() {
    int x = 10;

    int square;
    int cube;

    square_and_cube(x, &square, &cube);

    printf("%i squared is %i, %i cubed is %i\n", x, square, x, cube);

    int array[] = {1, 2, 3, 4};
    size_t size = 4;

    int sum;
    double average;

    sum_and_average(array, size, &sum, &average);

    printf("sum: %i\n", sum);
    printf("average: %lf\n", average);

    return 0;
}

void sum_and_average(const int array[], size_t size, int *sum, double *average) {
    *sum = 0;
    for (size_t i = 0; i < size; i++) {
        *sum = *sum + array[i];
    }
    *average = *sum / (double)size;
}

void square_and_cube(int x, int *square_pointer, int *cube_pointer) {
    *square_pointer = x * x;
    *cube_pointer = x * x * x;
}
