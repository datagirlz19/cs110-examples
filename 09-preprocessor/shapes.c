// #include is a preprocessor directive. When the preprocessor sees this line
// it places the contents of stdio.h in place of this line.
#include <stdio.h>

#include "circle.h"
#include "cylinder.h"

int main() {
    double radius = 10.0;

    printf("The area of a circle with radius %lf is %lf\n", radius,
           circle_area(radius));

    double height = 5.0;

    printf("The volume of a cylinder with radius %lf and height %lf is %lf\n",
           radius, height, cylinder_volume(radius, height));

    return 0;
}
