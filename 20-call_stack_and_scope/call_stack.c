#include <stdio.h>

double average(const int *numbers, size_t count);
int sum(int a, int b);

int main() {
  int array[3] = { 4, 10, 30 };
  printf("Average: %lf\n", average(array, 3));
  return 0;
}

double average(const int *numbers, size_t size) {
  int total = 0;
  for (size_t i = 0; i < size; ++i) {
    total = sum(total, numbers[i]);
  }
  return total / (double)size;
}  

int sum(int a, int b) {
  return a + b;
}