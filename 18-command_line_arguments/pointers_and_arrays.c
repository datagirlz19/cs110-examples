#include <stdio.h>

void print_array(int *array, size_t size);

int main() {
    size_t size = 4;
    int array[] = {10, -3, 14, 2};

    printf("The first element is %i\n", *array);
    // *(array + 1) is equivalent to array[1]. We always want to use array[1]
    // in practice
    printf("The second element is %i\n", *(array + 1));

    print_array(array, size);

    return 0;
}

void print_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%i\n", array[i]);
    }
}
