CFLAGS=-pedantic -std=gnu99 -Wall -Werror
test_getline: test_getline.c
	gcc -o test_getline $(CFLAGS) -g test_getline.c
incompatible_array: incompatible_array.c
	gcc -o incompatible_array $(CFLAGS) incompatible_array.c
str2int: str2int.c
	gcc -o str2int $(CFLAGS) str2int.c
dangling_pointer: dangling_pointer.c
	gcc -o dangling_pointer $(CFLAGS) dangling_pointer.c
clean:
	rm -f self_testing *.o *.c~ *.h~
