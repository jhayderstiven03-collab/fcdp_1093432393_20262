/*
 * @file omp_08_matrix_multiplication.c
 * @brief parallel square matrix multiplication NxN using OpenMP parallel for
 * @author Jhayder Stiven Florez
 * @date 2026-09-27
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define MIN 1
#define MAX 50

// Dynamic memory allocation for a 2D matrix
int **assign_memory(int fil, int col) {
  int **M = (int **)malloc(fil * sizeof(int *));
  if (M == NULL) {
    printf("ERROR al asignar memoria\n");
    return NULL;
  }
  for (int i = 0; i < fil; i++) {
    *(M + i) = (int *)malloc(col * sizeof(int));
    if (*(M + i) == NULL) {
      printf("ERROR al asignar memoria para las filas\n");
      return NULL;
    }
  }
  return M;
}

// Fill matrix with random integer values between MIN and MAX
void fill_matrix(int **M, int fil, int col) {
  for (int i = 0; i < fil; i++) {
    for (int j = 0; j < col; j++) {
      *(*(M + i) + j) = rand() % (MAX - MIN + 1) + MIN;
    }
  }
}

// matrix multiplication C = A * B using OpenMP parallel for
void multiply_matrix_par(int **A, int **B, int **C, int size) {
#pragma omp parallel for
  for (int i = 0; i < size; i++) {
    int tid =
        omp_get_thread_num(); // gets the thread´s number that is being used
    printf("Thread %d is calculating row %d\n", tid, i);

    for (int j = 0; j < size; j++) {
      int sum = 0;
      for (int k = 0; k < size; k++) {
        sum += *(*(A + i) + k) * *(*(B + k) + j);
      }
      *(*(C + i) + j) = sum;
    }
  }
}

// Free dynamically allocated memory for the matrix
void free_matrix(int **M, int fil) {
  for (int i = 0; i < fil; i++) {
    free(*(M + i));
  }
  free(M);
}

int main() {
  srand(time(NULL));

  int **A = assign_memory(N, N);
  int **B = assign_memory(N, N);
  int **C_par = assign_memory(N, N);

  if (A == NULL || B == NULL || C_par == NULL) {
    return 1;
  }

  fill_matrix(A, N, N);
  fill_matrix(B, N, N);

  // Measure parallel execution time
  double start_par = omp_get_wtime();
  multiply_matrix_par(A, B, C_par, N);
  double end_par = omp_get_wtime();
  double par_time = end_par - start_par;

  printf("Execution time:   %3f s\n", par_time);

  free_matrix(A, N);
  free_matrix(B, N);
  free_matrix(C_par, N);

  return 0;
}
