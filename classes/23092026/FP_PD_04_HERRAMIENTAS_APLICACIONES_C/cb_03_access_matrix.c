/*
 * @file cb_03_access_matrix.c
 * @brief create a dinamic matrix and show its content
 * @author Jhayder Stiven Florez
 * @date 2026-09-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 50

// Print matrix elements in row and column layout using pointer arithmetic
void print_matrix(int **M, int col, int fil) {
  printf("[\n");
  for (int i = 0; i < fil; i++) {
    for (int j = 0; j < col; j++) {
      if (j == col - 1) {
        printf("%4d\n", *(*(M + i) + j));
      } else {
        printf("%4d", *(*(M + i) + j));
      }
    }
    if (i == fil - 1) {
      printf("]\n");
    };
  }
}

// Fill matrix with random integer values between MIN and MAX using pointer
// arithmetic
void fill_matrix(int **M, int col, int fil) {
  for (int i = 0; i < fil; i++) {
    for (int j = 0; j < col; j++) {
      *(*(M + i) + j) = rand() % (MAX - MIN + 1) + MIN;
    }
  }
}

// Dynamic memory allocation for a 2D matrix (array of pointers)
int **assign_memory(int col, int fil) {
  int **M = (int **)malloc(fil * sizeof(int *));
  for (int i = 0; i < fil; i++) {
    *(M + i) = (int *)malloc(col * sizeof(int));
  }
  return M;
}

// Free dynamically allocated memory for all rows and the row pointers
void free_matrix(int **M, int fil) {
  for (int i = 0; i < fil; i++) {
    free((*(M + i)));
  }
  free(M);
}

int main() {
  srand(time(NULL));
  int fil = 3;
  int col = 3;
  int **Matrix = assign_memory(col, fil);
  fill_matrix(Matrix, col, fil);
  print_matrix(Matrix, col, fil);
  free_matrix(Matrix, fil);
}