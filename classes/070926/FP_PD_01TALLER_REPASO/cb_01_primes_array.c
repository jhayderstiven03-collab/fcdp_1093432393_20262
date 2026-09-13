#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_VAL 1
#define MAX_VAL 100

bool es_primo(int n) {
  if (n <= 1)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;

  int limite = (int)sqrt(n);
  for (int i = 3; i <= limite; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void generar_arreglo_aleatorio(int *arr, int tam) {
  for (int i = 0; i < tam; i++) {
    arr[i] = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
  }
}

int contar_primos(const int *arr, int tam) {
  int contador = 0;
  for (int i = 0; i < tam; i++) {
    if (es_primo(arr[i])) {
      contador++;
    }
  }
  return contador;
}

int main() {
  int n;

  printf("Ingrese el tamano del arreglo: ");
  if (scanf_s("%d", &n) != 1 || n <= 0) {
    printf("Error: Debe ingresar un numero entero positivo mayor a 0.\n");
    return 1;
  }

  srand((unsigned int)time(NULL));

  int *arreglo = (int *)malloc(n * sizeof(int));
  if (arreglo == NULL) {
    printf("Error: No se pudo asignar memoria suficiente.\n");
    return 1;
  }

  generar_arreglo_aleatorio(arreglo, n);

  printf("\nArreglo generado:\n[ ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arreglo[i]);
  }
  printf("]\n");

  int cantidad_primos = contar_primos(arreglo, n);
  printf("\nCantidad de numeros primos encontrados: %d\n", cantidad_primos);

  free(arreglo);

  return 0;
}