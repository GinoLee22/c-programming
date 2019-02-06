#include <stdio.h>
#include <stdlib.h>

int myatoi(const char * str) {
  /*
  * input: string of number in decimal
  * output: int
  */
  int value = 0;
  int sign = 1;
  // negative case
  if (*str == '-') {
    sign = -1;
    str++;
  }
  while (*str != '\0') {
    // skip not valid character
    if (*str - '0' < 0 || *str - '0' > 9) {
      str++;
      continue;
    }
    // TODO: need to work with overflow
    value *= 10;
    value += *str - '0';
    str++;
  }
  return sign * value;
}

int myatoiHex(const char * str) {
  /*
  * input: string of number in heximal
  * output: int
  */
  int value = 0;
  int sign = 1;
  int base = 10;
  // negative case
  if (*str == '-') {
    sign = -1;
    str++;
  }
  while (*str != '\0') {
    // skip not valid character
    if ((*str != 'A' && *str != 'B' && *str != 'C' && *str != 'D' && *str != 'E' && *str != 'F')
      && (*str - '0' < 0 || *str - '0' > 9)) {
      str++;
      continue;
    }

    value *= 16;
    if (*str - '0' >= 0 && *str - '0' <= 9) {
      value += *str - '0';
    } else {
      value += *str - 'A' + base;
    }
    str++;
  }
  return sign * value;
}

int main(void) {
  printf("***** test of myatoi(), decimal string -> integer *****\n");
  char const * str = "-12a345";
  int result = myatoi(str);
  printf("Correct result should be -12345.\n");
  printf("Test result is: %d.\n", result);

  printf("\n***** test of myatoiHex(), hex string -> integer *****\n");
  char const * strHex = "-AjjF";
  int resultHex = myatoiHex(strHex);
  printf("Correct result should be -175.\n");
  printf("Test result is: %d.\n", resultHex);

  // TODO: Question about design of 'strtol'. Why need to pass in the address of &ptr
  char strTest[30] = "2030300 This is test";
  char *ptr;
  long ret;

  ret = strtol(strTest, &ptr, 10);
  printf("The number(unsigned long integer) is %ld\n", ret);
  printf("ptr = %p\n", (void*)ptr);
  printf("*ptr =%csee it\n", *ptr);
  printf("String part is |%s|", ptr);
  return EXIT_SUCCESS;
}
