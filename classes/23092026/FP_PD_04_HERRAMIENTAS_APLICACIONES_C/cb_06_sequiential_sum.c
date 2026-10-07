/*
 * @file cb_06_sequential_sum.c
 * @brief sum of elements from an array sequentialy
 * @author Jhayder Florez
 * @date 2026-09-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000000

// add an integer numbers in ech position of the array with a for
// loop
void fill_array(int *arr) {
  for (int i = 0; i < N; i++) {
    *(arr + i) = i + 1;
  }
}

// go through every array's position and adding them to a variable sum using
// long long values for the quantity
void sum(int *arr) {
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum = sum + *(arr + i);
  }
  printf("Sum: %lld\n", sum);
}

int main() {
  int *arr = (int *)calloc(N, sizeof(int));
  fill_array(arr);
  clock_t startTime = clock();
  sum(arr);
  double elapsedTime = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  printf("Sequential Time: %.3fsg\n", elapsedTime);
  return 0;
}