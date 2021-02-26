/*
Structures

* Structures group together variables
    * A structure's variables are its members

* Defining structures
    * Defining a structure does not allocate any memory, it defines a new
    type which we can use throughout our program

* Declaring instances
    * Once a structure is defined, you can declare multiple instances of the
      structure
    * Each instance stores values for each of the members of the structure

* Accessing a structure instance's members
    * Use a . to access a member
    * pt.x and pt.y

*/

#include <stdio.h>
#include <math.h>

// This defines a structure that can be used anywhere in this program. There
// can be multiple instances of this structure in the program. This definition
// does not allocate memory to store actual values, it merely defines a type
// that can be used later to store values.
struct point {
    double x;
    double y;
};

// this structure can represent rectangles that are parallel to the x and y
// axes
struct rectangle {
    struct point lower_left;
    struct point upper_right;
};

double distance(struct point p1, struct point p2);

struct rectangle make_rectangle(struct point lower_left,
                                struct point upper_right);

void print_rectangle(struct rectangle rect);

int main() {
    struct point point1;

    point1.x = 5.2;
    point1.y = -3.4;

    struct point point2 = {10.7, 2.8};

    double dist = distance(point1, point2);

    printf("The distance between the two points is %lf\n", dist);

    struct rectangle rect = make_rectangle(point1, point2);

    print_rectangle(rect);

    return 0;
}

double distance(struct point p1, struct point p2) {
    double x_distance = p2.x - p1.x;
    double y_distance = p2.y - p1.y;

    return sqrt(x_distance * x_distance + y_distance * y_distance);
}

struct rectangle make_rectangle(struct point lower_left,
                                struct point upper_right) {
    struct rectangle rect;

    rect.lower_left = lower_left;
    rect.upper_right = upper_right;

    return rect;
}

void print_rectangle(struct rectangle rect) {
    printf("Lower left point: (%lf, %lf)\n", rect.lower_left.x,
           rect.lower_left.y);
    printf("Upper right point: (%lf, %lf)\n", rect.upper_right.x,
           rect.upper_right.y);
}
