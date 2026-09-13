#include <stdio.h>
#include <stdlib.h>

void read_elements(double *array, int count) {
  for (int i = 0; i < count; i++) {
    printf("Ingrese el valor para el elemento %d: ", i + 1);
    while (scanf_s("%lf", &array[i]) != 1) {
      printf("Entrada invalida. Ingrese un numero real valido: ");
      while (getchar() != '\n');
    }
  }
}

double calculate_sum(const double *array, int count) {
  double total_sum = 0.0;
  for (int i = 0; i < count; i++) {
    total_sum += array[i];
  }
  return total_sum;
}

int main() {
  int count;

  printf("Ingrese el numero de elementos del arreglo: ");
  if (scanf_s("%d", &count) != 1 || count <= 0) {
    printf("Error: Debe ingresar un numero entero positivo mayor a 0.\n");
    return 1;
  }

  double *dynamic_array = (double *)malloc(count * sizeof(double));
  if (dynamic_array == NULL) {
    printf("Error: No se pudo asignar memoria dinamica.\n");
    return 1;
  }

  read_elements(dynamic_array, count);

  double total_sum = calculate_sum(dynamic_array, count);
  printf("\nLa suma total de los elementos es: %.2lf\n", total_sum);

  free(dynamic_array);

  return 0;
}
