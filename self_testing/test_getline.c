#include <stdio.h>
#include <stdlib.h>

int main (void) {
  size_t sz = 0 ;
  char * line = NULL;
  getline(&line, &sz, stdin);
  printf("%d\n", (int)sz);
  free(line);          // comment OR uncomment this line for Valgrind test
}
