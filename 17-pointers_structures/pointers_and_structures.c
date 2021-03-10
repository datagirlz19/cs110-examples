/*

Pointers to Structures

- One reason to pass a pointer to a structure to a function is to avoid copying
  the structure
    - Best practice is to use const if the function will not change the
      structure's members
- Accessing a structure instance's members via pointer
    - Syntax: p->x accesses the member x of the structure instance pointed to by
      p
    - This syntax is shorthand for (*s).p

Compile with: gcc pointers_and_structures.c -lm
Run with: ./a.out

*/


#include <stdio.h>
#include <math.h>

struct point {
    double x;
    double y;
};

/*
Given a pointer to a struct point structure instance, set its x and y members
to be the provided values.
*/
void initialize_point(struct point *point, double x, double y);

/*
Print a point with the format (x,y). The point is passed via pointer.
*/
void print_point(const struct point *point);

/*
Calculate the distance and slope between two points. The points are passed
via pointers, and the distance and slope are return via pointers.
*/
void distance_and_slope(const struct point *p1, const struct point *p2,
                        double *distance, double *slope);

int main() {
    struct point p1;
    struct point p2;

    initialize_point(&p1, 1.0, 2.5);
    initialize_point(&p2, 2.0, 5.0);

    double distance, slope;

    distance_and_slope(&p1, &p2, &distance, &slope);

    printf("The distance between ");
    print_point(&p1);
    printf(" and ");
    print_point(&p2);
    printf("\nis %lf. The slope is %lf\n", distance, slope);

    return 0;
}

void distance_and_slope(const struct point *p1, const struct point *p2,
                        double *distance, double *slope) {
    double x_distance = p2->x - p1->x;
    double y_distance = p2->y - p1->y;

    *distance = sqrt(x_distance * x_distance + y_distance * y_distance);
    *slope = y_distance / x_distance;
}

void print_point(const struct point *point) {
    printf("(%lf,%lf)", point->x, point->y);
}

void initialize_point(struct point *point, double x, double y) {
    point->x = x;
    point->y = y;
}
