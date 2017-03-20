#
# temp makefile to test hash function
#

CC = gcc

CFLAGS =

OBJS = hash.o list.o main.o 

#list: list.o
#	$(CC) $(CFLAGS) list.o -o list

#list.o: list.c
#	$(CC) $(CFLAGS) -c list.c 

hash: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o hash 

main.o: main.c hash.h 
	$(CC) $(CFLAGS) -c main.c

hash.o: hash.c hash.h 
	$(CC) $(CFLAGS) -c hash.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

clean:
	rm -f hash list $(OBJS) 
