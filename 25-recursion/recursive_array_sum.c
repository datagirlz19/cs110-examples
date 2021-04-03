#include <stdio.h>

int array_sum(int *array, size_t size);

int main() {
    int array[4] = {1, 2, 3, 4};

    printf("The sum of the array elements is %i\n",
           array_sum(array, 4));

   return 0;
}

int array_sum(int *array, size_t size) {
    if (size == 1) {
        // base case. we could also check for size == 0 and return 0 if we
        // wanted to support empty arrays
        return array[0];
    }
    else {
        // we can get the sum of the entire array by adding the last element
        // to the sum of all the other elements
        return array[size - 1] + array_sum(array, size - 1);
    }
}
