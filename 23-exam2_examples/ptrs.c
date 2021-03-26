/**
 * Cheatsheet Guide for Pointers
 * 
 * If you run this code through C Tutor
 * you can visualize how the code runs and how the pointers work.
 * Just use the link below and paste in the code.
 * http://pythontutor.com/c.html#mode=edit
 */
#include <stdio.h>

// Struct declaration
struct point {
    double x;
    double y;
};

// Function prototypes
void testfun(int *i);
void testfun2(int *array, size_t size);

int main() {

    // Automatic variable for a primative type
    //  A variable is most interested in the value it holds.
    int test = 10;
    
    // No dereferencing is necessary for accesing the value
    printf("varaiable: %i\n", test);
    test = 40;
    printf("varaiable: %i\n", test);

    // Automatic pointer variable
    //  The pointer is most interested in the address of
    //  memory (RAM) where something is stored.
    // The address of operator (&) is necessary for the statement
    //  below because the pointer wants to know WHERE in memory the
    //  variable test is located (it's address).
    // Remember that the type of ptr_to_test is an int *, that
    //  is not dereferencing when you are declaring a pointer.
    int *ptr_to_test = &test; 

    // Now that our pointer is declared and initialized with an
    //  an address in memory, we can acces the value using the
    //  dereference operator *.
    printf("ptr: %i\n", *ptr_to_test);
    // If we do not dereference a pointer, we just get the address
    //  which will be some random large value.
    printf("ptr address: %zu\n", ptr_to_test);
    
    // If a pointer references (points to) a variable, when we
    //  modify the value using the dereference operator it will
    //  also change the value when we use the variable.
    *ptr_to_test = 20;
    printf("variable: %i\n", test);

    // If a function has a pointer parameter, we can pass
    //  the address of a variable to the pointer.
    //  This will allow the pointer parameter in the function
    //  to reference the variable (remember that & gives the address
    //  of a variable).
    testfun(&test);
    // Alternatively if you already have a pointer, you can simply send that
    //  along to the function.
    testfun(ptr_to_test);
    // If the pointer parameter in the function is not const, changes you make
    //  to the value by deferencing the pointer will change the variable holding
    //  the value.
    printf("variable: %i\n", test);

    // Instatiation of a struct
    //  The variable z now holds an instance of a struct of type struct point in memory.
    //  We can addess is members using the . operator.
    struct point z;
    z.x = 1;
    z.y = 2;

    // This is a pointer to a struct point type.
    struct point *ptr_to_z;

    // We can make the pointer reference (point to) the struct z using
    //  the address operator.
    ptr_to_z = &z;
    
    // To access the struct memebers we can use the -> operator which
    //  gives us access to the structs memebers without having to use the
    //  dereference operator (behind the scenes it does the dereferencing
    //  for us). This is the preferred method accessing struct members from
    //  a pointer.
    ptr_to_z->x = 200;
    ptr_to_z->y = 50;

    // Arrays are already pointers!
    // They point to the first address of the contiguous chunk of memory that
    //  holds the array values.
    int array[10] = {1,2,3};
    
    // We generally do not use the dereferencing operator with arrays
    //  because we have the subscript operator [] (brackets) to access
    //  the values at each element/position in the array
    printf("Value of array[1]: %i\n", array[1]);
    
    // When we pass an array to a function we are passing a pointer.
    //  If the function does not have const in front of the pointer
    //  parameter, we can modify the array's contents.
    testfun2(array, 10);
    printf("Value of array[1]: %i\n", array[1]);

    return 0;
}   

// Note that the int * (pointer to an int) to reference out array
//   can be access exactly the same way as it was in main(). No
//   special syntax required.
void testfun2(int *array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        array[i] = 40;
    }
}

// Access the value of a pointer that does not point to an
//   array, but a single value (int, double, float, etc.)
//   will use the dereference operator to access the value
//   that is located at the address that the pointer holds.
// NOTE: If this were a struct, we would use -> to access the
//   members (like the example in main())
void testfun(int *i) {
    printf("From function: %i\n", *i);
    *i = 500;
}