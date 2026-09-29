/*
 * @file cb_05_dynamic_string.c
 * @brief dynamic string exercise
 * @author Jhayder Florez
 * @date 2026-09-27
 */

#include <stdio.h>
#include <stdlib.h>

// Function to print characters and their memory addresses
void print_array_char(char *arr_char) {
  printf("\ncharacter -> memory address\n");
  while (*arr_char != '\0') {
    printf("%c -> %p\n", *arr_char, (void *)arr_char);
    arr_char++;
  }
}

// Function for fill dynamic string
void fill_array_char(char *arr_char) {
  printf("Please enter some text: ");
  /*
  We use scanf to receive the text from the keyboard and store it in arr_char.
  The " %[^\n]" is a trick to tell scanf to read everything,
  even spaces, until the user presses the Enter key.
  */
  scanf(" %[^\n]", arr_char);
}

int main() {
  int max_size = 100;
  char *arr_char = (char *)calloc(max_size, sizeof(char));

  if (arr_char == NULL) {
    printf("Error: Could not get memory from the computer.\n");
    return 1;
  }
  fill_array_char(arr_char);
  print_array_char(arr_char);
  free(arr_char);
  arr_char = NULL;
  return 0;
}