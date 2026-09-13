#include <stdbool.h>
#include <stdio.h>

long long factorial(int a) {
  int fact = 1;
  for (int i = 2; i <= a; i++) {
    fact = fact * i;
  }
  return fact;
}

bool is_even(long long a) {
  if (a % 2 == 0) {
    return true;
  }
  return false;
}

int main() {

  int a;
  printf("ingrese un numero entero positivo: ");
  if (scanf_s("%d", &a) != 1 || a <= 0) {
    printf("Error: Debe ingresar un numero entero positivo mayor a 0.\n");
    return 1;
  } else if (a > 16) {
    printf("Error: Debe ingresar un numero entero positivo menor a 17.\n");
    return 1;
  }

  printf("Tu numero es %d\n", a);

  long long fact = factorial(a);
  printf("El factorial es: %lld\n", fact);

  if (is_even(fact)) {
    printf("Este numero es par");
  } else {
    printf("Este numero no es par");
  }

  return 0;
}