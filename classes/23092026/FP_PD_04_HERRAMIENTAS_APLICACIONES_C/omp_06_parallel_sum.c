/*
 * @file omp_06_parallel_sum.c
 * @brief calculate sum of array elements in parallel using OpenMP reduction
 * @author Jhayder Florez
 * @date 2026-09-27
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000000000

// add an integer number between 1 to 10 in ech position of the array with a for
// loop
void fill_array(int *arr) {
  for (int i = 0; i < N; i++) {
    *(arr + i) = i + 1;
  }
}

// go through every array's position and adding them to a variable local_sum
// using OpenMP for parallel procces and long long values for the quantity
void sum(int *arr, long long *result_sum) {
  long long local_sum = 0;
#pragma omp parallel for reduction(+ : local_sum)
  for (int i = 0; i < N; i++) {
    local_sum = local_sum + *(arr + i);
  }
  *result_sum = local_sum;
}

int main() {
  int *arr = (int *)calloc(N, sizeof(int));
  if (arr == NULL) {
    printf("Error: Could not allocate memory.\n");
    return 1;
  }
  fill_array(arr);
  long long total_sum = 0;
  double start_time = omp_get_wtime();
  sum(arr, &total_sum);
  double elapsed_time = omp_get_wtime() - start_time;
  printf("Parallel Time: %.3f seconds\n", elapsed_time);
  printf("The sum is equal to %lld\n", total_sum);
  free(arr);
  arr = NULL;

  return 0;
}