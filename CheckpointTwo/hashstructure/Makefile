#
# temp makefile to test hash function
#

CC = gcc

CFLAGS =

OBJS = hash.o main.o list.o

hash: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o hash 

main.o: main.c hash.h
	$(CC) $(CFLAGS) -c main.c

hash.o: hash.c hash.h 
	$(CC) $(CFLAGS) -c hash.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

clean:
	rm -f hash $(OBJS) 
