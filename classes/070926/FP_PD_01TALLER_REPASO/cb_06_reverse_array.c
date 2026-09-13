#include <stdio.h>

void reverse_arr(int *array, int lenght) {
  int *begin = array;
  int *end = array + lenght - 1;
  int temp;

  while (begin < end) {
    temp = *begin;
    *begin = *end;
    *end = temp;

    begin++;
    end--;
  }
}

void print_array(int *array, int lenght) {
  printf("[");
  for (int i = 0; i < lenght; i++) {
    if (i == (lenght - 1)) {
      printf("%d]\n", *(array + i));
    } else {
      printf("%d, ", *(array + i));
    }
  }
}

int main() {

  int lenght;
  printf("ingrese el tamano del arreglo\n");
  if (scanf_s("%d", &lenght) != 1 || lenght <= 0) {
    printf("Debe ingresar un numero entero mayor a 0\n");
    return 1;
  }

  int array[lenght];

  for (int i = 0; i < lenght; i++) {
    printf("Ingrese el elemento %d: ", i + 1);
    if (scanf_s("%d", &array[i]) != 1) {
      printf("Debe ingresar un numero entero valido\n");
      return 1;
    }
  }

  reverse_arr(array, lenght);

  print_array(array, lenght);

  return 0;
}