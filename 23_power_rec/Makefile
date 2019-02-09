CFLAGS=-pedantic -std=gnu99 -Wall -Werror
power: power.o test-power.o
	gcc -o power power.o test-power.o
%.o: %.c
	gcc $(CFLAGS) -c $<
clean:
	rm -f power *.o *.c~ *.h~
