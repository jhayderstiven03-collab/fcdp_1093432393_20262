#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PASSING_GRADE 60.0

typedef struct {
  int id;
  char name[50];
  double grades[3];
  double average;
} Student;

double calculate_student_average(const double grades[3]) {
  return (grades[0] + grades[1] + grades[2]) / 3.0;
}

void read_students(Student *students_list, int count) {
  for (int i = 0; i < count; i++) {
    printf("\n--- Registro de Estudiante %d ---\n", i + 1);
    printf("Ingrese ID: ");
    while (scanf_s("%d", &students_list[i].id) != 1) {
      printf("ID invalido. Intente nuevamente: ");
      while (getchar() != '\n')
        ;
    }

    printf("Ingrese Nombre: ");
    scanf_s("%s", students_list[i].name, (unsigned int)sizeof(students_list[i].name));

    for (int j = 0; j < 3; j++) {
      printf("Ingrese Nota %d (0 a 100): ", j + 1);
      while (scanf_s("%lf", &students_list[i].grades[j]) != 1 ||
             students_list[i].grades[j] < 0.0 || students_list[i].grades[j] > 100.0) {
        printf("Nota invalida. Ingrese un valor entre 0 y 100: ");
        while (getchar() != '\n')
          ;
      }
    }

    students_list[i].average = calculate_student_average(students_list[i].grades);
  }
}

void display_averages(const Student *students_list, int count) {
  printf("\n================ RESUMEN DE ESTUDIANTES ================\n");
  for (int i = 0; i < count; i++) {
    printf("ID: %d | Nombre: %s | Promedio: %.2lf\n", students_list[i].id,
           students_list[i].name, students_list[i].average);
  }
}

void display_passing_students(const Student *students_list, int count) {
  printf("\n================ ESTUDIANTES APROBADOS ================\n");
  bool has_passing_students = false;
  for (int i = 0; i < count; i++) {
    if (students_list[i].average >= PASSING_GRADE) {
      printf("ID: %d | Nombre: %s | Promedio: %.2lf (APROBADO)\n", students_list[i].id,
             students_list[i].name, students_list[i].average);
      has_passing_students = true;
    }
  }

  if (!has_passing_students) {
    printf("Ningun estudiante alcanzo la nota minima aprobatoria (%.1lf).\n",
           PASSING_GRADE);
  }
}

int main() {
  int count;

  printf("Ingrese la cantidad de estudiantes a registrar: ");
  if (scanf_s("%d", &count) != 1 || count <= 0) {
    printf("Error: Debe ingresar un numero entero positivo mayor a 0.\n");
    return 1;
  }

  Student *students = (Student *)malloc(count * sizeof(Student));
  if (students == NULL) {
    printf("Error: No se pudo asignar memoria para los estudiantes.\n");
    return 1;
  }

  read_students(students, count);
  display_averages(students, count);
  display_passing_students(students, count);

  free(students);

  return 0;
}
