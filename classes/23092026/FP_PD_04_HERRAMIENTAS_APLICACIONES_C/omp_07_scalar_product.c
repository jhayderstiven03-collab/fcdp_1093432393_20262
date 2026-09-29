/*
 * @file omp_07_scalar_product.c
 * @brief calculate scalar product between two vectors using OpenMP reduction
 * @author Jhayder Stiven Florez
 * @date 2026-09-27
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000000
#define MIN 1
#define MAX 50

// add an integer number between 1 to 50 in each position of the array
void fill_array(int *arr) {
  for (int i = 0; i < N; i++) {
    *(arr + i) = rand() % (MAX - MIN + 1) + MIN;
  }
}

// multiply each position from both arrays using OpenMP reduction
long long scalar_product(int *arra, int *arrb) {
  long long scalar = 0;

#pragma omp parallel reduction(+ : scalar)
  {
    int tid = omp_get_thread_num(); // gets the num of thread that is being used
    int num_threads =
        omp_get_num_threads(); // gets the total number of threads are used

    printf("Thread %d of %d is participating in the calculation.\n", tid,
           num_threads);

#pragma omp for
    for (int i = 0; i < N; i++) {
      int a = *(arra + i);
      int b = *(arrb + i);
      scalar += (long long)a * b;
    }
  }

  return scalar;
}

int main() {
  srand(time(NULL));

  int *arr1 = (int *)malloc(N * sizeof(int));
  if (arr1 == NULL) {
    printf("ERROR al asignar memoria para arr1\n");
    return 1;
  }

  int *arr2 = (int *)malloc(N * sizeof(int));
  if (arr2 == NULL) {
    printf("ERROR al asignar memoria para arr2\n");
    free(arr1);
    return 1;
  }

  fill_array(arr1);
  fill_array(arr2);

  double start_time = omp_get_wtime();

  long long scalar = scalar_product(arr1, arr2);

  double elapsed_time = omp_get_wtime() - start_time;

  printf("Scalar product = %lld\n", scalar);
  printf("Parallel execution time: %3f s\n", elapsed_time);

  free(arr1);
  free(arr2);

  return 0;
}
