#include <stdio.h>

int main() {
    int even_integers[10];

    for (int i = 0; i < 10; ++i) {
        even_integers[i] = i * 2;
    }

    printf("The elements of even_integers are:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%i\n", even_integers[i]);
    }

    int array_sum = 0;

    for (int i = 0; i < 10; ++i) {
        array_sum += even_integers[i];
    }

    printf("The sum of the first 10 even integers starting at 0 is %i\n",
           array_sum);
    
    // Creates array of size 3 containing values 1, 2, 3
    int initialized_array[] = {1, 2, 3};

    // Creates array of size 10 where first three elements are 1,2,3
    //  and the remaning 7 elements are 0.
    int another_initialized[10] = {1, 2, 3};

    // This declares and initializes an array of 10 zeros
    int zero_array[10] = {0};

    // Can use a variable for the size of an array, but you then cannot use an
    //  initializer in this case
    int size = 100;
    int array_with_one_hundred_elements[size];

    int array_of_three[3];
    printf("Enter 3 integers to store in an array: ");

    for (int i = 0; i < 3; ++i) {
        scanf("%i", &array_of_three[i]);
    }

    printf("Here are the contents of the array:\n");

    for (int i = 0; i < 3; ++i) {
        printf("%i\n", array_of_three[i]);
    }

    return 0;
}