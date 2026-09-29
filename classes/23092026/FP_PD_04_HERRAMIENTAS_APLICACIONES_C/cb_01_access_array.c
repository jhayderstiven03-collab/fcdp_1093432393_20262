/*
 * @file cb_01_access_array.c
 * @brief create a dinamic array and show its content
 * @author Jhayder Stiven Florez
 * @date 2026-09-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 10

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

// add an integer number between 1 to 10 in ech position of the array with a for
// loop
void fill_array(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    *(arr + i) = rand() % (MAX - MIN + 1) + MIN;
  }
}

int main() {
  srand(time(NULL));
  int size = 10;
  int *arr = (int *)malloc(size * sizeof(int));
  if (arr == NULL) {
    printf("ERROR al asignar memoria");
    return 1;
  }
  fill_array(arr, size);
  print_array(arr, size);

  return 0;
}