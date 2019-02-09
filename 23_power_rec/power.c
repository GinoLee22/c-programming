#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);

/*
int main(void) {
  return EXIT_SUCCESS;
}
*/

unsigned power(unsigned x, unsigned y) {
  // special case
  if (x == 0 && y == 0) {
    return 1;
  }
  if (x == 0) {
    return 0;
  }
  // base case
  if (y == 0) {
    return 1;
  }
  // recursion
  return x * power(x, y - 1);
}
