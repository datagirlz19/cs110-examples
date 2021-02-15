#include <stdio.h>

int main() {
    double x, y;

    printf("Enter x: ");
    scanf("%lf", &x);
    
    printf("Enter y: ");
    scanf("%lf", &y);

    // You can specify how many decimal places of precision you want when you
    //  output a double or float value. Here we request to see 20.
    printf("x + y is %.20lf\n", x + y);

    return 0;
}