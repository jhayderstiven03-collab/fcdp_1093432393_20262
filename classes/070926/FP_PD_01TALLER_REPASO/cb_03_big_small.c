#include <stdio.h>

int biggest_n(int a, int b, int c) {
  int biggerAB = (a > b) ? a : b;
  int biggerABC = (biggerAB > c) ? biggerAB : c;
  return biggerABC;
}

int smallest_n(int a, int b, int c) {
  int smallerAB = (a < b) ? a : b;
  int smallerABC = (smallerAB < c) ? smallerAB : c;
  return smallerABC;
}

int main() {
  int a, b, c, sml, bg;

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

  printf("ingrese el valor de c: ");
  if (scanf_s("%d", &c) != 1 || c <= 0) {
    printf("Error: Debe ingresar un numero entero positivo mayor a 0.\n");
    return 1;
  }

  printf("---Valores correspondientes---\n a=%d\n b=%d\n c=%d\n", a, b, c);

  bg = biggest_n(a, b, c);
  sml = smallest_n(a, b, c);

  printf("---Numero Mayor---\n %d\n---Numero Menor---\n %d", bg, sml);

  return 0;
}