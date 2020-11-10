all:b-tree-test

CFLAGS=-g -O0 -Wall

b-tree-test:b-tree-test.o b-tree.o

b-tree.o:b-tree.h b-tree.c

b-tree-test.o:b-tree-test.c

.PHONY:clean

clean:
	rm *.o b-tree-test
