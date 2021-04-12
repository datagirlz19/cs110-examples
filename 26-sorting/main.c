#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

/**
 * Helper function necessary for C's qsort to work
 * return negative if left < right
 * return 0 if left == right
 * return positive if left > right
 */
int compare(const void *left, const void *right);

int main() {
    // Bubble Sort
    {
        printf("Bubble Sort\n");
        int *array = random_array(10);
        display_array(array, 10);
        bubble_sort(array, 10);
        display_array(array, 10);
        free(array);
    }

    // Selection Sort
    {
        printf("Selection Sort\n");
        int *array = random_array(10);
        display_array(array, 10);
        selection_sort(array, 10);
        display_array(array, 10);
        free(array);
    }

    // Insertion Sort
    {
        printf("Insertion Sort\n");
        int *array = random_array(10);
        display_array(array, 10);
        insertion_sort(array, 10);
        display_array(array, 10);
        free(array);
    }

    // Built in C sort
    {   
        printf("Quick Sort\n");
        int *array = random_array(10);
        display_array(array, 10);

        /*
            qsort (Quick Sort) is a more efficient
            sort than what we have implemented, but
            for this C function we need to supply the
            array, the size of the array, the size of the
            elements the array holds, and lastly a function
            to compare the values to know which one is 
            "bigger" or "smaller".
        */
        qsort(array, 10, sizeof(int), compare);
        display_array(array, 10);

    }
}

int compare(const void *left, const void *right) {
    /*
        Looks weird right? Remember that we can't dereference
        a void pointer, so we first cast it to an int pointer
        (int *), and THEN we dereference that to get the value.
    */
    return *(int *)left - *(int *)right;
}