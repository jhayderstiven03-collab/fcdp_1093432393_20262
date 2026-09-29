/*
 * @file cb_04_pointer_swap.c
 * @brief exercise on swapping values ​​using pointers in C
 * @author Jhadyer Florez
 * @date 2026-09-27
 */
#include <stdio.h>

// Swap two integer values using pointers
void swap_pointer(int *number_a, int *number_b) {
  int temp = *number_a;
  *number_a = *number_b;
  *number_b = temp;
}

int main() {
  int number_a, number_b;

  printf("Enter number a: ");
  scanf("%d", &number_a);

  printf("\nEnter number b: ");
  scanf("%d", &number_b);

  swap_pointer(&number_a, &number_b);
  printf("\nChanged\nnumber a: %d\nnumber b: %d\n", number_a, number_b);

  return 0;
}