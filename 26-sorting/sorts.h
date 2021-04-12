#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>

/**
 * Helper function to create random arrays
 */
int *random_array(size_t size);

/**
 * Helper function to swap the value of two items
 */
void swap(int *value1, int *value2);

/**
 * Helper function to display an array on the terminal
 */
void display_array(const int *arrray, size_t size);
  
/**
 * Bubble Sort
 *  Takes an input array and the size of the array.
 *  The function returns the sorted array via the
 *  array pointer.
 */
void bubble_sort(int *array, size_t size);

/**
 * Selection Sort
 *  Takes an input array and the size of the array.
 *  The function returns the sorted array via the
 *  array pointer.
 */ 
void selection_sort(int *array, size_t size);

/**
 * Insertion Sort
 *  Takes an input array and the size of the array.
 *  The function returns the sorted array via the
 *  array pointer.
 */
void insertion_sort(int *array, size_t size);

#endif
