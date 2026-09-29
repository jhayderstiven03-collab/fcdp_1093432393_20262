/*
 * @file cb_07_scalar_product.c
 * @brief calculate scalar product between two vectors
 * @author Jhayder Stiven Florez
 * @date 2026-09-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000000
#define MIN 1
#define MAX 50

// add an integer number between 1 to 10 in ech position of the array with a for
// loop
void fill_array(int *arr) {

  for (int i = 0; i < N; i++) {
    *(arr + i) = rand() % (MAX - MIN + 1) + MIN;
  }
}

// multiply each position from both arrays
long long scalar_product(int *arra, int *arrb) {
  long long scalar = 0;
  for (int i = 0; i < N; i++) {
    int a = *(arra + i);
    int b = *(arrb + i);
    scalar += (a * b);
  }
  return scalar;
}

int main() {
  int *arr1 = (int *)malloc(N * sizeof(int));
  if (arr1 == NULL) {
    printf("ERROR al asignar memoria");
    return 1;
  }
  int *arr2 = (int *)malloc(N * sizeof(int));
  if (arr2 == NULL) {
    printf("ERROR al asignar memoria");
    return 1;
  }
  fill_array(arr1);
  fill_array(arr2);

  clock_t start_time = clock();
  long long scalar = scalar_product(arr1, arr2);

  printf("Resultado = %lld\n", scalar);

  double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

  printf("sequential time: %3fsg\n", elapsed_time);

  free(arr1);
  free(arr2);

  return 0;
}