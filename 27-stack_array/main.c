/**
 * Program to ensure that an expression has matching
 *   opening and closing parentheses.
 * 
 * Examples:
 *  ()       - valid
 *  ()()(()) - valid
 *  (        - invalid
 *  )        - invalid
 *  (()      - invalid
 *  ())      - invalid
 */ 
#include "stack.h"
#include <stdio.h>
#include <stdbool.h>


int main() {
    // Create a stack
    struct stack expr_stack = create_stack();

    // Assume the expression is valid
    bool valid_expression = true;

    // Read input from standard input
    char ch;
    while((ch = getchar()) != EOF) {
        // If we have an open parenthesis we push it to
        //   the stack
        if (ch == '(') {
            push(&expr_stack, ch);
        }
        // If we have a closing parenthesis...
        else if (ch == ')') {
            /**
             * If the stack is empty our expression either:
             *   - starts with a closing parenthesis
             *   - has an extra closing parenthesis
             */
            if (is_stack_empty(&expr_stack)) {
                valid_expression = false;
                break;
            }
            // We remove one of the open parentheses
            else {
                pop(&expr_stack);
            }
        }
    }

    /**
     * After processing all of the parentheses
     *  if the stack is empty there is a closing
     *  parenthesis for each open parenthesis.
     */
    if (is_stack_empty(&expr_stack) && valid_expression) {
        printf("Valid Expression\n");
    }
    // We have an extra opening parenthesis and the
    //  expression is not valid.
    else {
        printf("Invalid Expression\n");
    }

    free_stack(&expr_stack);

    return 0;
}