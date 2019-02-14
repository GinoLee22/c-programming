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

/*
* return 10 * 10 matrix by reading the input file
*/
void readMatrix(char matrix[10][10], char * fileName) {
  int row = 0, col = 0, size = 10;
  FILE * f = fopen(fileName, "r");
  int c;
  if (f == NULL) {
    // file error handling
    fprintf(stderr, "Error in opening files\n" );
    exit(EXIT_FAILURE);
  }
  // filling the matrix
  while ((c = fgetc(f)) != EOF) {
    // if (row == 9) {
    //   printf("%c\n", c);
    // }
    if (c == '\n') {
      // error handling: when there is new line -> col != 10
      if (col != size) {
        // printf("%c\n", c);
        // printf("row is %d\n", row);
        // printf("col is %d\n", col);
        fprintf(stderr, "Incorrect column number\n" );
        exit(EXIT_FAILURE);
      }
      row++;
      col = 0;
      continue;
    }
    if (row >= size) {
      // error handling: when the row exceed 10 with early jump out
      fprintf(stderr, "Incorrect row number\n" );
      exit(EXIT_FAILURE);
    }
    matrix[row][col] = (char)c;
    col++;
  }
  if (row != size) {
    // error handling: row not enough
    fprintf(stderr, "Incorrect row number\n" );
    exit(EXIT_FAILURE);
  }
  if (fclose(f) != 0) {
    // file error handling
    fprintf(stderr, "Error in closing files\n" );
    exit(EXIT_FAILURE);
  }
}

void printMatrix(char matrix[10][10]) {
  int size = 10;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, char ** argv) {
  char matrix[10][10];
  char * fileName = argv[1];
  readMatrix(matrix, fileName);
  rotate(matrix);
  printMatrix(matrix);
  // printf("%c\n", matrix[1][0]);
}
