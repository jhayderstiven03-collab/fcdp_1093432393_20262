#include <stdio.h>

int sum_digit(int a) {
  if (a == 0) {
    return 0;
  } else
    return (a % 10) + (sum_digit(a / 10));
}

int main() {
  int a;
  printf("ingrese un numero entero positivo: ");
  if (scanf_s("%d", &a) != 1 || a <= 0) {
    printf("Error: Debe ingresar un numero entero positivo mayor a 0.\n");
    return 1;
  }

  int sum = sum_digit(a);
  printf("La suma de sus digitos es: %d\n", sum);

  return 0;
}