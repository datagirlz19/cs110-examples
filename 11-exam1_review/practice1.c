#include <stdio.h>

unsigned int count(const int array[], size_t size, int target_num);

int main() {
    int array[] = {0, 1, 2, 3, 3, 4, 5, 6, 6, 3, 1, 2, 3};
    int number_to_find = 3;
    size_t size = 13;

    printf("The number %i appears %i time(s)!\n", 
            number_to_find, count(array, size, number_to_find));

    return 0;
}

unsigned int count(const int array[], size_t size, int target_num) {
    int count = 0;

    for (size_t index = 0; index < size; ++index) {
        if (target_num == array[index]) {
            count += 1;
        }
    }

    return count;
}
