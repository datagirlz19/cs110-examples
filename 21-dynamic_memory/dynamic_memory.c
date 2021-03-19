/*

Dynamically Allocated Memory

* The heap
    * Area where dynamically allocated memory is stored
    * Memory in the heap is not associated with names, like stack variables
      are
    * Memory in the heap can only be accessed through pointers
* malloc()
    * Allocates memory on the heap and returns a pointer to the memory
    * The memory could be used to store an array, or a single value, or a
      structure instance
    * A pointer to a heap array uses array[i] syntax just like stack arrays
    * Prototype: void *malloc(size_t size)
        * size is the size of the area to allocate in bytes
        * void *
            * Generic pointer that is automatically cast to a pointer of a
              specific type on assignment
            * Cannot be dereferenced
        * When providing the size in bytes, use the sizeof() operator to find
          the size of the type you are using
          * malloc(10 * sizeof(int)) - Allocates enough storage for 10 ints
* free()
    * Deallocates heap memory
    * Prototype: void free(void *ptr)
        * Frees the memory pointed to by ptr
    * Memory leaks
        * If ptr is a pointer to heap memory, reassigning ptr to point to
          something else will not free the memory automatically. If ptr is
          automatically deallocated when a function returns, the heap memory
          will also not be deallocated
        * Heap memory that has no pointer pointing to it is inaccessible
          and cannot be freed until the program exits
* calloc()
    * void *calloc(size_t count, size_t size)
    * Allocates enough memory to store count items of size bytes each
    * Memory is initialized to 0
    * int *array = calloc(10, sizeof(int))
        * Create an array of 10 ints, initialized to 0

*/

#include <stdio.h>
#include <stdlib.h>

unsigned int *powers_of_2(size_t count);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <number of powers>\n", argv[0]);
        return 1;
    }

    size_t power_count = atoi(argv[1]);

    unsigned int *powers = powers_of_2(power_count);

    for (size_t i = 0; i < power_count; i++) {
        printf("%u\n", powers[i]);
    }

    free(powers);

    return 0;
}

unsigned int *powers_of_2(size_t count) {
    // malloc() dynamically allocates memory on the heap and returns a pointer
    // to that memory. The parameter for malloc() is the number of bytes we
    // want to allocate, so to allocate an array we need to multiply the number
    // of elements we want by the number of bytes each element needs.
    unsigned int *powers = malloc(count * sizeof(unsigned int));

    unsigned int power = 1;
    for (size_t i = 0; i < count; i++) {
        powers[i] = power;
        power *= 2;
    }

    return powers;
}
