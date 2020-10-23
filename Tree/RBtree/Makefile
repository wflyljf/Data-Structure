all:rbtree-test

CFLAGS=-g -O0 -Wall

rbtree-test:rbtree-test.o rbtree.o

rbtree.o:rbtree.h rbtree.c

rbtree-test.o:rbtree-test.c

.PHONY:clean

clean:
	rm *.o rbtree-test
