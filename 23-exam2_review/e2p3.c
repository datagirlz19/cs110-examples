#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

struct point {
    double x;
    double y;
};

double total_distance(const struct point *array, size_t size);
double distance(struct point p1, struct point p2);

int main() {
    size_t size = 0;
    size_t capacity = 1;
    struct point *array = malloc(capacity * sizeof(struct point));
    if (array == NULL) {
        printf("Failed to allocate memory!\n");
        return 1;
    }

    double value;
    int switch_value = 1;
    while (scanf("%lf", &value) == 1) {
        if (size == capacity) {
            capacity *= 2;
            array = realloc(array, capacity * sizeof(struct point));
            if (array == NULL) {
                printf("Failed to allocate memory!\n");
                return 1;
            }
        }

        // Swtch between reading in X and Y coordinates
        if (switch_value > 0) {
            array[size].x = value;
        }
        else {
            array[size].y = value;
            ++size;
        }

        switch_value *= -1;
    }

    if (size < 2 || switch_value < 0) {
        printf("Too few points or an odd number of values!\n");
        return 1;
    }
    
    printf("The total distance is: %lf\n", total_distance(array, size));

    free(array);

    return 0;
}

double total_distance(const struct point *array, size_t size) {
    double total = 0;
    for (size_t i = 0; i < size - 1; i++) {
        total += distance(array[i], array[i + 1]);
    }

    return total;
}

double distance(struct point p1, struct point p2) {
    double x_dist = p2.x - p1.x;
    double y_dist = p2.y - p1.y;
    return sqrt(x_dist * x_dist + y_dist * y_dist);
}
