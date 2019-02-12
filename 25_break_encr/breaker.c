#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// int max(int a, int b);
int decrypt(FILE * inputFile);

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: breaker inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int key = decrypt(f);
  printf("%d\n", key);
  if (fclose(f) != 0) {
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

// int max(int a, int b) {
//   return a > b ? a : b;
// }

/*
* input: a file stream
* output: a decrypt key
*/
int decrypt(FILE * inputFile) {
  int alphabetCnt[26] = {0};
  int max = 0;
  int tmpKey, curChar;
  char res = 'a';
  while ((curChar = fgetc(inputFile)) != EOF) {
    if (isalpha(curChar)) {
      tmpKey = tolower(curChar) - 'a';
      alphabetCnt[tmpKey]++;
      if (alphabetCnt[tmpKey] > max) {
        max = alphabetCnt[tmpKey];
        res = tolower(curChar);
      }
    }
  }
  return res - 'a';
}
