/*
 * @file cb_08_matrix_multiplication.c
 * @brief sequential square matrix multiplication NxN
 * @author Jhayder Stiven Florez
 * @date 2026-09-27
 */

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

// Print matrix elements in row and column layout
void print_matrix(int **M, int fil, int col) {
  printf("[\n");
  for (int i = 0; i < fil; i++) {
    for (int j = 0; j < col; j++) {
      printf("%4d", *(*(M + i) + j));
    }
    printf("\n");
  }
  printf("]\n");
}

//  matrix multiplication C = A * B
void multiply_matrix_seq(int **A, int **B, int **C, int size) {
  for (int i = 0; i < size; i++) {
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
  int **C = assign_memory(N, N);

  if (A == NULL || B == NULL || C == NULL) {
    return 1;
  }

  fill_matrix(A, N, N);
  fill_matrix(B, N, N);

  clock_t start_time = clock();
  multiply_matrix_seq(A, B, C, N);
  double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

  printf("Matrix multiplication completed (%dx%d).\n", N, N);
  printf("execution time: %3fsg\n", elapsed_time);

  free_matrix(A, N);
  free_matrix(B, N);
  free_matrix(C, N);

  return 0;
}
