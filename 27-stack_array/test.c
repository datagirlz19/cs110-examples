/**
 * Simple program to test our stack
 *   Test:
 *     - Creation
 *     - Push
 *     - Pop
 *     - Display
 *     - Cleanup
 */ 
#include "stack.h"
#include <stdio.h>


int main() {
    // Create the stack
    struct stack my_stack = create_stack();

    // Push the letters A through L 
    for (size_t i = 0; i < 12; ++i) {
        push(&my_stack, 'A' + i);
    }
    display_stack(&my_stack);
    
    // Remove the top two items from the stack
    printf("Pop: %c\n", pop(&my_stack));
    printf("Pop: %c\n", pop(&my_stack));
    display_stack(&my_stack);

    // Add an additional item to the stack
    push(&my_stack, 'Z');
    display_stack(&my_stack);

    // Remove all items from the stack
    size_t stack_count = my_stack.top;
    for (size_t i = 0; i <= stack_count; ++i) {
        printf("Pop: %c\n", pop(&my_stack));        
    }
    display_stack(&my_stack);

    // Cleanup the memory for the stack
    free_stack(&my_stack);

    return 0;
}
