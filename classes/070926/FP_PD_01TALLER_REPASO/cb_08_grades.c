#include <stdio.h>

char get_letter_grade(double grade) {
  if (grade >= 90.0) {
    return 'A';
  } else if (grade >= 80.0) {
    return 'B';
  } else if (grade >= 70.0) {
    return 'C';
  } else if (grade >= 60.0) {
    return 'D';
  } else {
    return 'F';
  }
}

int main() {
  double grade;

  printf("Ingrese la nota numerica (0 a 100): ");
  if (scanf_s("%lf", &grade) != 1 || grade < 0.0 || grade > 100.0) {
    printf("Error: Debe ingresar una nota numerica valida entre 0 y 100.\n");
    return 1;
  }

  char letter_grade = get_letter_grade(grade);
  printf("La calificacion correspondiente es: %c\n", letter_grade);

  return 0;
}
