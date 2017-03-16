#
# temp makefile to test hash function
#

CC = gcc

CFLAGS =

OBJS = hash.o main.o entry.o

hash: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o hash 

main.o: main.c hash.h
	$(CC) $(CFLAGS) -c main.c

hash.o: hash.c hash.h 
	$(CC) $(CFLAGS) -c hash.c

entry.o: entry.c entry.h
	$(CC) $(CFLAGS) -c entry.c

clean:
	rm -f hash $(OBJS) 
