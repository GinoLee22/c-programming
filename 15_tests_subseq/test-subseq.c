#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(void) {
  int array0[] = {};
  if (maxSeq(array0, 0) != 0) {
    printf("Failed on {}\n");
    exit(EXIT_FAILURE);
  }

  int array1[] = {1};
  if (maxSeq(array1, 1) != 1) {
    printf("Failed on 1\n");
    exit(EXIT_FAILURE);
  }

  int array2[] = {2, 1, 0};
  if (maxSeq(array2, 3) != 1) {
    printf("Failed on 2,1,0\n");
    exit(EXIT_FAILURE);
  }
  
  int array3[] = {1,2,3,3};
  if (maxSeq(array3, 4) != 3) {
    printf("Failed on 1,2,3,3\n");
    exit(EXIT_FAILURE);
  }

  int array4[] = {-3, -1, 0, 1, 2};
  if (maxSeq(array4, 5) != 5) {
    printf("Failed on -3,-1,0,1,2\n");
    exit(EXIT_FAILURE);
  }

  int array5[] = {1, 2, 0, 1, 2, 3};
  if (maxSeq(array5, 6) != 4) {
    printf("Failed on 1,2,0,1,2,3\n");
    exit(EXIT_FAILURE);
  }

  int array6[] = {1, 1, 1, 1, 1, 1};
  if (maxSeq(array6, 6) != 1) {
    printf("Failed on 1,1,1,1,1,1\n");
    exit(EXIT_FAILURE);
  }
  
  return EXIT_SUCCESS;
}
