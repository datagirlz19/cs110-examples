#include <stdio.h>

int main() {
    long int x, y;

    printf("Enter x: ");
    scanf("%li", &x);
    
    printf("Enter y: ");
    scanf("%li", &y);

    // Adding x and y here might result in overflow (or underflow for negative numbers)
    printf("x + y is %li\n", x + y);

    return 0;
}