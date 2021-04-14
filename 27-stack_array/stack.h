#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>

#define INIT_SIZE 10
#define ERROR_MEMORY 1

/**
 * Stack struct to hold all the data for
 *   our stack data structure.
 * top: is the index where
 * size: is the size of the
 */
struct stack {
    size_t top;
    size_t size;
    char *stack_data;
};


/**
 * Create and initialize a stack for use
 *   The stack begins with a size of INIT_SIZE
 */ 
struct stack create_stack();


/**
 * Push an item to the top of the stack
 *   this adds a new item to the stack
 */
void push(struct stack *my_stack, char item);


/**
 * Pop an item off of the top of the stack
 *   this removes an item from the stack and
 *   retruns the value
 * Precondition:
 *   The stack must NOT be empty
 * Postcondition:
 *   Stack will have one less item or be empty
 */
char pop(struct stack *my_stack);


/**
 * Print the stack contents to the terminal
 *   Stack contents will be printed starting
 *   from the element at the top of the stack
 *   and working our way "down".
 */
void display_stack(const struct stack *my_stack);


/**
 * A function to indicate if an stack is empty
 * Postcondition:
 *   returns true if the stack is empty and false
 *   otherwise    
 */ 
bool is_stack_empty(const struct stack *my_stack);


/**
 * Cleanup and free the memory from a stack
 *   Since we are managing this data structure
 *   we will provide a way to clean it up properly
 *   so the users do not have to worry about this.
 */ 
void free_stack(struct stack *my_stack);


#endif
