#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "sorts.h"

int *random_array(size_t size) {
    srand(time(NULL));
    int *array = malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Unable to allocate memory!\n");
        exit(1);
    }

    for (size_t i = 0; i < size; ++i) {
        array[i] = rand() % 21;
    }

    return array;
}

void swap(int *value1, int *value2) {
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

void display_array(const int *array, size_t size) {
    for(size_t i = 0; i < size; ++i) {
        printf("%i ", array[i]);
    }
    printf("\n");
}

/**
 * Bubble sort locally sorts pair of items in the array.
 *  The large values "bubble up" to the end of the array.
 *  A small optimization is that the algorithm can stop
 *  when no values have been swapped.
 */
void bubble_sort(int *array, size_t size) {

    for (size_t i = 0; i < size - 1; ++i) {
        bool swapped = false;
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) { 
                swap(&array[j], &array[j + 1]);
                swapped = true;
            }
        }
        
        /**
         * If we didn't swap any values, everything is
         *   already sorted, so we can break (quit) the
         *   loop early.
        */
        if (!swapped) {
            break;
        }
    }
}

/**
 * Selection Sort finds the smallest values in the array.
 *   It then checks to make sure that there are no smaller
 *   values in the rest of the array. When the smallest value
 *   is found, it is placed at the beginning of the array. This 
 *   process repeats moving the next smallest element in the
 *   array by one each iteration making the front of the
 *   array become a sorted portion that expands each iteration.
 */ 
void selection_sort(int *array, size_t size) {

    for (size_t i = 0; i < size - 1; ++i) {
        // Find the index of the smallest element in the unsorted
        //  portion of the array.
        size_t minimum_value_index = i;
        for (size_t j = i + 1; j < size; ++j) {
            if (array[j] < array[minimum_value_index]) {
                minimum_value_index = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(&array[minimum_value_index], &array[i]);
    }
}

/**
 * Insertion Sort starts by assuming the first element is already sorted.
 *  The next element is then compared to that sorted value. If the next 
 *  element is greater than the "sorted element" it stays where it is. If
 *  it happens to be smaller, the sorted values are all shifted over to the right
 *  to make room for the value to be "inserted" in the correct spot.
 */  
void insertion_sort(int *array, size_t size) {

    for (size_t i = 1; i < size; ++i)
    {
        int value = array[i];
        size_t j = i - 1;
 
        /* 
            Shift the elements to the right making room for the
            value we are trying to place in the correct location.
        */
        while (j >= 0 && array[j] > value) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = value;
    }
}