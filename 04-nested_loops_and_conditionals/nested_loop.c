#include <stdio.h>

int main() {
    /*
        Prints out all x y pairs using digits 0-3
        (NOTE: The grid layout below is for compactness
          the actual output will be one long column)
        0, 0   1, 0   2, 0   3, 0
        0, 1   1, 1   2, 1   3, 1
        0, 2   1, 2   2, 2   3, 2
        0, 3   1, 3   2, 3   3, 3
    */
    for (int x = 0; x < 4; ++x) {
        for (int y = 0; y < 4; ++y) {
            printf("%i, %i\n", x, y);
        }
    }

    /*
        Print a "square" or asterisks
        ****
        ****
        ****
        ****
    */
    int square_size = 5;
    for (int row = 0; row < square_size; ++row) {
        for (int column = 0; column < square_size; ++column) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}