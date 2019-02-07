#include <stdio.h>
#include <stdlib.h>

void rotate(char matrix[10][10]) {
  int size = 10;
  // 1st: flip horizontally
  int ptrLeft, ptrRight;
  char tmp;
  for (int i = 0; i < size; i++) {
    ptrLeft = 0;
    ptrRight = size - 1;
    // swap
    while (ptrLeft < ptrRight) {
      tmp = matrix[i][ptrLeft];
      matrix[i][ptrLeft] = matrix[i][ptrRight];
      matrix[i][ptrRight] = tmp;
      ptrLeft++;
      ptrRight--;
    }
  }
  // 2nd: flip diagonally
  int new_x, new_y;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      new_x = size - 1 - j;
      new_y = size - 1 - i;
      // swap
      tmp = matrix[i][j];
      matrix[i][j] = matrix[new_x][new_y];
      matrix[new_x][new_y] = tmp;
    }
  }
}

// void printMatrix(char matrix[5][5]) {
//   int size = 5;
//   for (int i = 0; i < size; i++) {
//     for (int j = 0; j < size; j++) {
//       printf("%c ", matrix[i][j]);
//     }
//     printf("\n");
//   }
// }

// int main(void) {
//   char matrix[5][5] = {{'1', '2', '3', '4', '5'},
//                        {'6', '7', '8', '9', 'A'},
//                        {'B', 'C', 'D', 'E', 'F'},
//                        {'G', 'H', 'I', 'J', 'K'},
//                        {'L', 'M', 'N', 'O', 'P'}};
//   printf("Original Matrix is: \n");
//   printMatrix(matrix);
//   rotate(matrix);
//   printf("Current Matrix is: \n");
//   printMatrix(matrix);
// }
