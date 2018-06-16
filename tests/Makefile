CC=gcc
CFLAGS = -g -Wall -std=c99

all: vector stack llist dllist

vector:	
	$(CC) ../src/vector.c vector_test.c -o vector $(CFLAGS)

stack:
	$(CC) ../src/stack.c stack_test.c -o stack $(CFLAGS)

llist:
	$(CC) ../src/llist.c llist_test.c -o llist $(CFLAGS)

dllist:
	$(CC) ../src/dllist.c dllist_test.c -o dllist $(CFLAGS)

clean:
	rm -f vector stack llist dllist 
