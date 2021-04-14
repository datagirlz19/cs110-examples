#include "stack.h"
#include <assert.h>
#include <stdio.h>


struct stack create_stack() {
    struct stack my_stack;

    // Start the top index at negative one
    //  since that is not a valid array position.
    my_stack.top = -1;
    my_stack.size = INIT_SIZE;
    my_stack.stack_data = malloc(INIT_SIZE * sizeof(char));

    if (my_stack.stack_data == NULL) {
        printf("Unable to allocate memory!\n");
        exit(ERROR_MEMORY);
    }

    return my_stack;
}


void push(struct stack *my_stack, char item) {
    // Stack is full so we need more room
    if (my_stack->top == my_stack->size - 1) {
        my_stack->size *= 2;
        my_stack->stack_data = realloc(my_stack->stack_data, my_stack->size * sizeof(char));
        if (my_stack->stack_data == NULL) {
            printf("Unable to re-allocate memory!\n");
            exit(ERROR_MEMORY);
        }
    }

    // Move the top of the stack to the next open
    //   element of the array.
    ++(my_stack->top);

    // Place the item onto the stack
    my_stack->stack_data[my_stack->top] = item;
}


char pop(struct stack *my_stack) {
    // We can't remove an element from an empty list
    assert(my_stack->top != -1);
    
    // Get the item from the stop of the stack
    char data = my_stack->stack_data[my_stack->top];

    // Move the top of the stack to the previous
    //  element in the array
    --(my_stack->top);
    
    return data;
}


bool is_stack_empty(const struct stack *my_stack) {
    return my_stack->top == -1;
}


void display_stack(const struct stack *my_stack) {
    // If the stack is empty there are no values
    //  to print
    if (my_stack->top == -1) {
        printf("Stack is Empty!\n");
    }
    else {
        // Print the elements of the stack starting
        //  with the top
        for (size_t i = 0; i <= my_stack->top; ++i) {
            printf("%c", my_stack->stack_data[my_stack->top - i]);
            if (i == 0) {
                printf(" -> TOP");
            }
            printf("\n");
        }
    }
}


void free_stack(struct stack *my_stack) {
    free(my_stack->stack_data);
}
