#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);
void run_check(unsigned x, unsigned y, unsigned expected_ans, int case_number);

int main(void) {
  /* test:
    0 ^ 0 -> 1
    0 ^ 1 -> 0, 0 ^ 2 -> 0
    1 ^ 0 -> 1, 2 ^ 0 -> 1
    1 ^ 1 -> 1, 1 ^ 2 -> 1
    2 ^ 3 -> 8
    -1 ^ 2 -> 1
  */
  run_check(0, 0, 1, 1);
  run_check(0, 1, 0, 2);
  run_check(0, 2, 0, 3);
  run_check(1, 0, 1, 4);
  run_check(2, 0, 1, 5);
  run_check(1, 1, 1, 6);
  run_check(1, 2, 1, 7);
  run_check(2, 3, 8, 8);
  run_check(2, 30, 1073741824, 9);
  run_check(-1, 2, 1, 10);
  return EXIT_SUCCESS;
}

void run_check(unsigned x, unsigned y, unsigned expected_ans, int case_number) {
  unsigned test_ans = power(x, y);
  if (test_ans == expected_ans) {
    printf("Correct!\n");
  } else {
    printf("Wrong! Fail case number: %d\n", case_number);
    exit(EXIT_FAILURE);
  }
}
