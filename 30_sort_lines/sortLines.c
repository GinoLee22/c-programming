#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

char ** readFile(char * fileName, int * outputSize);
char ** readStdin(int * outputSize);
char ** readFromStream(FILE * stream, int * outputSize);
void printStringArray(char ** stringArray, int stringArraySize);

int main(int argc, char ** argv) {
  if (argc == 1) {    // read from stdin
    int stdinOutputSize = 0;
    char ** stdinOutput = readStdin(&stdinOutputSize);
    sortData(stdinOutput, stdinOutputSize);
    printStringArray(stdinOutput, stdinOutputSize);
    // free allocated memory
    for (int j = 0; j < stdinOutputSize; j++) {
      free(stdinOutput[j]);
    }
    free(stdinOutput);
  } else {            // read from files
    for (int i = 1; i < argc; i++) {
      int fileOutputSize = 0;
      char ** fileOutput = readFile(argv[i], &fileOutputSize);
      sortData(fileOutput, fileOutputSize);
      printStringArray(fileOutput, fileOutputSize);
      // free allocated memory
      for (int j = 0; j < fileOutputSize; j++) {
	free(fileOutput[j]);
      }
      free(fileOutput);
    }
  }
  return EXIT_SUCCESS;
}

char ** readStdin(int * outputSize) {
  return readFromStream(stdin, outputSize);
}

// error: return NULL. outputSize = 0 initially
char ** readFile(char * fileName, int * outputSize) {
  // 1st: open file
  FILE * f = fopen(fileName, "r");
  if (f == NULL) {
    perror("Fail to open read file");
    return NULL;
  }
  // 2nd: read file
  char ** output = readFromStream(f, outputSize);
  // 3rd: close file
  if (fclose(f) != 0) {
    perror("Fail to close read file");
    return NULL;
  }
  return output;
}
/*
* generic function that read from FILE* (file or stdin)
*/
char ** readFromStream (FILE * stream, int * outputSize) {
  char ** output = NULL;
  char * lineBuffer = NULL;
  size_t lineBufferSize = 0;
  while (getline(&lineBuffer, &lineBufferSize, stream) >= 0) {
    output = realloc(output, (*outputSize + 1) * sizeof(*output));
    output[*outputSize] = lineBuffer;
    (*outputSize)++;
    lineBuffer = NULL;
  }
  free(lineBuffer);
  return output;
}

void printStringArray(char ** stringArray, int stringArraySize) {
  for (int i = 0; i < stringArraySize; i++) {
    printf("%s", stringArray[i]);
  }
}
