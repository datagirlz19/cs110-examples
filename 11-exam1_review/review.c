#include <stdio.h>
#include <limits.h>

int main() {
    // declared, but not initialized, value is unknown (undefined)
    int i;
    // declared and initialized to 10
    unsigned int ui = 10;
    unsigned long ul;
    float f;
    double d;
    size_t size = 5;

    printf("The max int value is %i and the min is %i\n", INT_MAX, INT_MIN);

    // %zu is the format specification for size_t
    printf("float uses %zu bytes\n", sizeof(float));
    printf("double uses %zu bytes\n", sizeof(double));

    // the expression 10 / 3 evaluates to 3, which is assigned to i
    i = 10 / 3;

    // this will assign 3 to d, which would see as 3.000000 after conversion
    d = 10 / 3;

    // this will result in an approximation of 3 1/3 assigned to d
    d = 10.0 / 3;

    // this is the remainder after dividing 10 by 3, which is 1
    ui = 10 % 3;

    // generate the numbers 0 through 9
    for (int x = 0; x < 10; x++) {
        printf("%i ", x);
    }
    printf("\n");

    if (i == 3) {
        printf("yep\n");
    }

    // initializes an array of all zeros, since using an initialization list
    // that shorter than the size of the array causes the rest of the values
    // to be padded with zeros
    int array[5] = {0};

    // access every element of an array named array with size size
    for (size_t i = 0; i < size; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");

    // could cause a segmentation fault, or assign to an area of memory
    // outside the array
    array[5] = 10;

    return 0;
}
