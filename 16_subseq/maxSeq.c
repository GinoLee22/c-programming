#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);
size_t max(size_t size1, size_t size2);

/*
int main(void) {
  printf("***** Test of maxSeq() *****\n");

  // Note: can't have 0 length array with "gcc -std=c99 -pedantic" -> warning
  // int array0[] = {};
  // printf("\nThe answer of {} should be 0.\n");
  // printf("The test result is: %d\n", (int) maxSeq(array0, 0));

  int array1[] = {1};
  printf("\nThe answer of {1} should be 1.\n");
  printf("The test result is: %d\n", (int) maxSeq(array1, 1));

  int array2[] = {2, 1, 0};
  printf("\nThe answer of {2, 1, 0} should be 1.\n");
  printf("The test result is: %d\n", (int) maxSeq(array2, 1));

  int array3[] = {1, 2, 3, 3};
  printf("\nThe answer of {1, 2, 3, 3} should be 3.\n");
  printf("The test result is: %d\n", (int) maxSeq(array3, 4));

  int array4[] = {-3, -1, 0, 1, 2};
  printf("\nThe answer of {-3, -1, 0, 1, 2} should be 5.\n");
  printf("The test result is: %d\n", (int) maxSeq(array4, 5));

  int array5[] = {1, 2, 0, 1, 2, 3};
  printf("\nThe answer of {1, 2, 0, 1, 2, 3} should be 4.\n");
  printf("The test result is: %d\n", (int) maxSeq(array5, 6));


  int array6[] = {1, 1, 1, 1, 1, 1};
  printf("\nThe answer of {1, 1, 1, 1, 1, 1} should be 1.\n");
  printf("The test result is: %d\n", (int) maxSeq(array6, 6));
}
*/

size_t maxSeq(int * array, size_t n) {
  // corner case
  if (n <= 0) {
    return 0;
  }

  size_t longest = 1;
  size_t current_length = 1;
  for (int i = 1; i < n; i++) {
    if (array[i] > array[i - 1]) {
      current_length++;
    } else {
      longest = max(current_length, longest);
      current_length = 1;
    }
  }
  // longest at the end of sequence
  longest = max(current_length, longest);
  return longest;
}

size_t max(size_t size1, size_t size2) {
  return size1 > size2 ? size1 : size2;
}
