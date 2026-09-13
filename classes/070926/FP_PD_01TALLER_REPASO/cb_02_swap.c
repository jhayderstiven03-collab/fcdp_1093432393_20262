/*
 *file
 */

#include <stdio.h>

void swap(int *number_a, int *number_b) {
  int temp = *number_a;
  *number_a = *number_b;
  *number_b = temp;
}

int main() {

  int a;
  int b;

  printf("ingrese el valor de a: ");
  if (scanf_s("%d", &a) != 1 || a <= 0) {
    printf("Error: Debe ingresar un numero entero positivo mayor a 0.\n");
    return 1;
  }

  printf("ingrese el valor de b: ");
  if (scanf_s("%d", &b) != 1 || b <= 0) {
    printf("Error: Debe ingresar un numero entero positivo mayor a 0.\n");
    return 1;
  }

  printf("valores iniciales. \na = %d \nb = %d \n", a, b);
  swap(&a, &b);
  printf("valores intercambiados. \na = %d \nb = %d", a, b);
  return 0;
}
