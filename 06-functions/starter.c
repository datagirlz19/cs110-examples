#include <stdio.h>

int main() {
    unsigned long long n;
    printf("Enter n: ");
    scanf("%llu", &n);

    unsigned long long sum = 0;

    for (unsigned long long x = 1; x <= n; ++x) {
        sum += x;
    }

    printf("The %lluth triangle number is %llu\n", n, sum);
}