#include <stdio.h>
#include <stdlib.h>

int max(int input1, int input2) {
  if (input1 > input2) {
    return input1;
  } else {
    return input2;
  }
}

void squares(int size1, int x_offset, int y_offset, int size2) {
  //compute the max of size1 and (x_offset + size2).  Call this w

  //compute the max of size1 and (y_offset + size2).  Call this h

  //count from 0 to h. Call the number you count with y

    //count from 0 to w. Call the number you count with x

      //check if  EITHER
      //    ((x is between x_offset  and x_offset +size2) AND 
      //     y is equal to either y_offset OR y_offset + size2 - 1 )
      //  OR
      //    ((y is between y_offset and y_offset + size2) AND
      //     x is equal to either x_offset OR x_offset + size2 -1)
      // if so, print a *

      //if not,
      // check if EITHER
      //    x is less than size1 AND (y is either 0 or size1-1)
      // OR
      //    y is less than size1 AND (x is either 0 or size1-1)
      //if so, print a #

      //else print a space
    //when you finish counting x from 0 to w, 
    //print a newline
  int w = max(size1, x_offset + size2);
  int h = max(size1, y_offset + size2);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if ((i >= y_offset && i < y_offset + size2 && (j == x_offset || j == x_offset + size2 - 1))
	  || (j >= x_offset && j < x_offset + size2 && (i == y_offset || i == y_offset + size2 - 1))) {
	printf("%c", '*');
      } else if ((i >= 0 && i < size1 && (j == 0 || j == size1 - 1)) ||
		  (j >= 0 && j < size1 && (i == 0 || i == size1 - 1))) {
	printf("%c", '#');
      } else {
	printf(" ");
      }
    }
    printf("\n");
  }
}
