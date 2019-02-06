#include <stdio.h>
#include <stdlib.h>
// Still broken
int * initArray(int howLarge) {
  int myArray[howLarge];
  for (int i = 0; i < howLarge; i++) {
    myArray[i] = i;
  }
  return myArray;
  // int * p = myArray;
  // return p;
}

void printArray(int array[], int size) {
  printf("[ ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("]\n");
}

int main(void) {
  int howLarge = 5;
  printArray(initArray(howLarge), howLarge);
}
