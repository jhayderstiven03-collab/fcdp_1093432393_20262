/*
 * @file cb_02_sum_array.c
 * @brief Sum of element from an array
 * @author Jhayder Stiven Florez
 * @date 2026-09-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 50

// add an integer number between 1 to 10 in ech position of the array with a for
// loop
void fill_array(int *arr, int size) {

  for (int i = 0; i < size; i++) {
    *(arr + i) = rand() % (MAX - MIN + 1) + MIN;
  }
}

// pirnt any elements from an array going through every position of it
void print_array(int *array, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      printf("%d]\n", *(array + i));
      break;
    }
    printf("%d, ", *(array + i));
  }
}

// go through every array's position and adding them to a variable sum
int sum_array(int *arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += *(arr + i);
  }
  return sum;
}

int main() {
  srand(time(NULL));
  int suma = 0;
  int size = 10;
  int *arr = (int *)malloc(size * sizeof(int));
  if (arr == NULL) {
    printf("ERROR al asignar memoria");
    return 1;
  }
  fill_array(arr, size);
  print_array(arr, size);
  suma = sum_array(arr, size);
  printf("La suma de los elementos del arreglo es = %d\n", suma);

  return 0;
}