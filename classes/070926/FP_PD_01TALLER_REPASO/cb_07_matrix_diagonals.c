#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_VAL 1
#define MAX_VAL 100

void generate_random_matrix(int size, int matrix[size][size]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix[i][j] = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
    }
  }
}

void print_matrix(int size, const int matrix[size][size]) {
  printf("\nMatriz generada:\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%4d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int calculate_main_diagonal(int size, const int matrix[size][size]) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += matrix[i][i];
  }
  return sum;
}

int calculate_anti_diagonal(int size, const int matrix[size][size]) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += matrix[i][size - 1 - i];
  }
  return sum;
}

int main() {
  int size;
  printf("Ingrese el tamano de la matriz cuadrada: ");
  if (scanf_s("%d", &size) != 1 || size <= 0) {
    printf("Error: Debe ingresar un numero entero positivo mayor a 0.\n");
    return 1;
  }

  srand((unsigned int)time(NULL));

  int matrix[size][size];

  generate_random_matrix(size, matrix);
  print_matrix(size, matrix);

  int main_diagonal_sum = calculate_main_diagonal(size, matrix);
  int anti_diagonal_sum = calculate_anti_diagonal(size, matrix);

  printf("\nSuma de la diagonal principal: %d\n", main_diagonal_sum);
  printf("Suma de la diagonal secundaria: %d\n", anti_diagonal_sum);

  if (main_diagonal_sum > anti_diagonal_sum) {
    printf("La diagonal principal es mayor.\n");
  } else if (anti_diagonal_sum > main_diagonal_sum) {
    printf("La diagonal secundaria es mayor.\n");
  } else {
    printf("Ambas diagonales tienen la misma suma.\n");
  }

  return 0;
}
