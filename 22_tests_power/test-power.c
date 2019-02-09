#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);
void run_check(unsigned x, unsigned y, unsigned expected_ans);

int main(void) {
  /* test:
    0 ^ 1 -> 1, 0 ^ 2 -> 1
    1 ^ 0 -> 1, 2 ^ 0 -> 1
    1 ^ 1 -> 1, 1 ^ 2 -> 1
    2 ^ 3 -> 8
  */
  run_check(0, 1, 1);
  run_check(0, 2, 1);
  run_check(1, 0, 1);
  run_check(2, 0, 1);
  run_check(1, 1, 1);
  run_check(1, 2, 1);
  run_check(2, 3, 8);
  return EXIT_SUCCESS;
}

void run_check(unsigned x, unsigned y, unsigned expected_ans) {
  unsigned test_ans = power(x, y);
  if (test_ans == expected_ans) {
    printf("Correct!\n");
  } else {
    printf("Wrong!\n");
    exit(EXIT_FAILURE);
  }
}
