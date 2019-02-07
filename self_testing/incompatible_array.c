#include <stdio.h>
#include <stdlib.h>

// void printArray(int ** arr, int width, int height) {
void printArray(int arr[][3], int width, int height) {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      printf("%d\n", arr[i][j]);
    }
  }
}

int main(void) {
  int data[3][3] = {{0, 1, 2},
                    {3, 4, 5},
                    {6, 7, 8}};
  printArray(data, 3, 3);
  // printArray((int**)data, 3, 3);        // wrong fix
  printf("address is %p\n", (void*)data[0]);
  printf("address is %p\n", (void*)data[1]);
  printf("%d\n", data[0]);
  printf("%d\n", data[0][1]);
  return EXIT_SUCCESS;
}
