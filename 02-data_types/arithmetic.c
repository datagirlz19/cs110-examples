#include <stdio.h>

int main() {
    int x = 5;
    int y = 6;
    int z = 2;

    // Cast (convert) the result of x + y to a double
    double result = (double)(x + y) / z;

    printf("%lf\n", result);
    
    return 0;
}