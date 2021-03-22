/*

This program simply reads as many integers from standard input as it can, and
then prints the integers out. The integers are stored in a dynamically allocated
array which grows as needed when it runs out of space.

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // The number of elements that have been placed into the array
    size_t size = 0;
    // The total number of elements that the array can currently hold
    size_t capacity = 1;

    int *array = malloc(capacity * sizeof(int));

    // malloc() will return NULL if it was unable to allocate memory. NULL is a
    // special value used to indicate that a pointer points to nothing. If you
    // try to dereference a pointer that has the value NULL you will get a
    // segmentation fault.
    if (array == NULL) {
        printf("Unable to allocate memory\n");
        return 1;
    }

    // If scanf() is asked to read a single integer, it will return 1 if it was
    // able to read an integer, it will return 0 if there was more data from
    // standard input but it was not an integer, and it will return EOF if
    // standard input reaches EOF. So by looping while scanf() returns 1, we
    // will read all the integers we can until there is input that is not an
    // integer, or EOF is reached.
    int input;
    while (scanf("%i", &input) == 1) {
        // We need to grow the array if the number of elements in the array is
        // equal to the current capacity
        if (size == capacity) {
            // We double the capacity each time we grow so that we don't call
            // realloc() many times if the array gets large
            capacity *= 2;
            // We need to assign the return value of realloc() back to the
            // variable array, because the address of the array may have changed
            array = realloc(array, capacity * sizeof(int));
            // Like with malloc(), realloc() might return NULL if it was unable
            // to allocate memory
            if (array == NULL) {
                printf("Unable to realloc to a new capacity of %zu\n",
                       capacity);
                return 1;
            }

            printf("Resized array to have capacity %zu\n", capacity);
        }

        // Since size is the number of elements we have currently placed into
        // the array, it will also always been the index at which to place the
        // next element
        array[size] = input;
        size++;
    }

    // By using realloc() here we shrink the array down to the appropriate size
    // if the capacity is larger than the size
    array = realloc(array, size * sizeof(int));

    // Print out all the elements in the array
    for (size_t i = 0; i < size; i++) {
        printf("%i\n", array[i]);
    }

    // We are now done with the array, so we can free it
    free(array);

    return 0;
}
