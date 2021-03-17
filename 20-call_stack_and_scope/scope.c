/**
 * Scope Demonstration
 * 
 * SCOPE is an area of code where are variable is accessible by
 *  its name.
 * 
 * GLOBAL SCOPE
 * Variables delcared at the top of the program outside of
 *  any function have global scope. They are visible to
 *  all functions in the program. These should be used
 *  SPARINGLY.
 * 
 * LOCAL SCOPE
 * All variables declared within a function have local scope and are 
 *  only visible within the function. This include function parameters.
 * 
 * BLOCK SCOPE
 * Varaibles declared within loops, conditional statements, or within
 *  a block (curly braces) are only visible within the block.
 * 
 */ 
#include <stdio.h>

// Used for the assert statements
#include <assert.h>

// These global variables are visible to all functions
//  and unless const, are read AND write.
double acceleration = 9.8; // m/s^2
int start_time = 20; // seconds


double free_fall_velocity(int time);
void display_velocities(const int *time_array, int size);
void test_velocity_function();

int main() {

    // These variables have local scope
    //  only within the main() function
    size_t array_size = 5;
    int array[array_size];

    // The varible i has block scope within this for loop
    //  it is also accessible to any nested loops, conditions,
    //  or blocks within this for loop.
    for (int i = 0; i < array_size; ++i) {
        // The array varible can be used here because the
        //  array is declared outside of the loop, but within the
        //  main function.
        array[i] = 0;
    }

    // This variable i has local scope, but only to statements
    //  beneath its declaration. It is also completely different and
    //  unaffected by the variable i in the for loop above.
    int i = 0;

    while (i < array_size) {
        array[i] = start_time;
        start_time = start_time + (4 * i);
        ++i;
    }

    // Since i was declared outside of the while loop, the variable is still
    //  visible after the while loop and it maintains its value. 
    printf("The value of \"i\" is %i\n", i);

    // Also since start_time is a global variable and it was modified in the
    //  while loop, the value has now changed.
    printf("The value of \"start_time\" is %i\n", start_time);

    display_velocities(array, array_size);

    printf("Running Tests!\n");
    //  The program will stop running if any of the tests fail
    test_velocity_function();

    return 0;
}

double free_fall_velocity(int time) {
    // acceleration can be used here due to global scope.
    // time has local scope to this function only.
    return acceleration * time; 
}

// The parameters of this function have local scope in this function.
void display_velocities(const int *time_array, int size) {
    // NOTE: Although time_array provides access to the data
    //  reference by the variable array in main, the variable
    //  named array is NOT visible to this function.
    for (int i = 0; i < size; ++i) {
        printf("The free fall speed after %i seconds is: %lf m/s^2\n", 
                time_array[i], free_fall_velocity(time_array[i]));
    }
}

void test_velocity_function() {
    // Another neat thing about scope is you can create your own blocks without
    //  a conditional or looping structure. A great use for this is testing
    //  since you can copy and paste the block, change the values you are testing
    //  and the variable names can be the same since the scope is limited to the
    //  block where they are declared.
    {
        // Any variables you declar within curly braces have their scope
        //  limited to code within the same (or a nested) block
        int input_test = 5;
        double expected = 49;
        
        // This function assert will stop the program if the
        //  expression evaluates to false.
        assert(free_fall_velocity(input_test) == expected);
    }

    {
        int input_test = 2;
        double expected = 19.6;
        assert(free_fall_velocity(input_test) == expected);
    }
    
    {
        int input_test = 9;
        double expected = 88.2;
        assert(free_fall_velocity(input_test) == expected);
    }
}