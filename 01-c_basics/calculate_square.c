#include <stdio.h>

int main() {
    printf("Enter an integer n: ");

    int n;
    scanf("%i", &n);

    int n_squared = n * n;

    printf("%i squared in %i\n", n, n_squared);

    return 0;
}