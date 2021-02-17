#include <stdio.h>

void even_odd_array(int array[], size_t size);
void show_array(int array[], size_t size);

int main() {
    int array[] = {0, 1, 2, 3, 3, 4, 5, 6, 6, 3, 1, 2, 3};
    size_t size = 13;

    printf("Array before:\n");
    show_array(array, size);
    
    even_odd_array(array, size);
    printf("Array after:\n");
    show_array(array, size);


    return 0;
}

void show_array(int array[], size_t size) {
    for (int index = 0; index < size; ++index) {
        printf("%i ", array[index]);
    }
    printf("\n");
}

void even_odd_array(int array[], size_t size) {

    for (size_t index = 0; index < size; ++index) {
        if (array[index] % 2 == 0) {
            array[index] = 1;
        }
        else {
            array[index] = 0;
        }
    }
}
