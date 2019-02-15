#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

/*
* This function is just an interface implement.
* Output content will be the same is input
*/
char * computeOutputFileName(const char * inputName) {
  char * writeFileName = malloc((strlen(inputName) + 8) * sizeof(*writeFileName));
  strcpy(writeFileName, inputName);
  strcat(writeFileName, ".counts");
  return writeFileName;
}
