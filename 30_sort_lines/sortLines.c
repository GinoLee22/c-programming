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

void readAndPrintFiles(char *fileName);

int main(int argc, char ** argv) {
  if (argc == 1) {
    // read from stdin
  } else {      // read from files
    // for (int i = 1; i < argc; i++) {
    //   readAndPrintFiles(argv[i]);
    // }
    readAndPrintFiles("input.txt");
  }
  return EXIT_SUCCESS;
}

// error: return NULL
void readAndPrintFiles(char *fileName) {
  // 1st: open file
  FILE * f = fopen(fileName, "r");
  if (f == NULL) {
    perror("Fail to open read file");
    return;
  }
  // 2nd: read file
  char * lineBuffer = NULL;
  size_t lineBufferSize;
  while (getline(&lineBuffer, &lineBufferSize, f) >= 0) {
    sortData(&lineBuffer, lineBufferSize);
    printf("%s", lineBuffer);
  }
  free(lineBuffer);
  // 3rd: close file
  if (fclose(f) != 0) {
    perror("Fail to close read file");
    return;
  }
}
