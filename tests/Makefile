CC=gcc
CFLAGS = -g -Wall -std=c99

all: vector stack llist dllist bst

vector:	
	$(CC) ../src/vector.c vector_test.c -o vector $(CFLAGS)

stack:
	$(CC) ../src/stack.c stack_test.c -o stack $(CFLAGS)

llist:
	$(CC) ../src/llist.c llist_test.c -o llist $(CFLAGS)

dllist:
	$(CC) ../src/dllist.c dllist_test.c -o dllist $(CFLAGS)

bst:
	$(CC) ../src/bst.c bst_test.c -o bst -g $(CFLAGS)

clean:
	rm -f vector stack llist dllist bst
