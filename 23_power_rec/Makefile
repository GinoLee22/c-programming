CFLAGS = -pedantic -std=gnu99 -Wall -Werror
power: power.o test-power.o
	gcc $(CFLAGS) -o power.o test-power.o
%.o: %.c
	gcc $(CFLAGS) -c $<
clean:
	rm -f power *.o *.c~ *.h~
