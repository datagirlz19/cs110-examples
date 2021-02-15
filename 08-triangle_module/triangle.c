#include "triangle.h"

bool is_triangle(double side_a, double side_b, double side_c) {
    return side_a + side_b > side_c &&
           side_a + side_c > side_b &&
           side_b + side_c > side_a;
}
