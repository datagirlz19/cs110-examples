#include <stdio.h>

void print_triangle(unsigned int triangle_size);

int main() {
    unsigned int maximum_size;
    printf("Enter a maximum triangle size: ");
    scanf("%u", &maximum_size);
    
    for (unsigned int size = 1; size <= maximum_size; ++size) {
        print_triangle(size);
        printf("\n");
    }

    return 0;
}

void print_triangle(unsigned int triangle_size) {
    for (int row = 0; row < triangle_size; ++row) {
        for (int column = 0; column < row + 1; ++column) {
            printf("*");
        }
        printf("\n");
    }
}