#
# Makefile for C-
# Using Lex and Yacc
#

CC = gcc

CFLAGS =

OBJS = y.tab.o lex.yy.o util.o main.o

cm: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o cm -ly -ll

main.o: main.c globals.h util.h scan.h parse.h
	$(CC) $(CFLAGS) -c main.c

util.o: util.c util.h globals.h y.tab.h
	$(CC) $(CFLAGS) -c util.c

lex.yy.c: cm.l
	flex cm.l

lex.yy.o: lex.yy.c globals.h util.h y.tab.h
	$(CC) $(CFLAGS) -c lex.yy.c

y.tab.c: cm.y
	yacc -d -v cm.y

y.tab.o: y.tab.c globals.h util.h scan.h parse.h
	$(CC) $(CFLAGS) -c y.tab.c

clean:
	rm -f cm $(OBJS) lex.yy.c y.tab.h y.tab.c y.output