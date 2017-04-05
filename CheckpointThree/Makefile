#
# Makefile for C-
# Using Lex and Yacc
#

CC = gcc

CFLAGS =

OBJS = symhash.o symlist.o y.tab.o lex.yy.o util.o main.o emit.o codegen.o

cm: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o cm -ly -ll

main.o: main.c globals.h util.h scan.h parse.h codegen.h
	$(CC) $(CFLAGS) -c main.c

util.o: util.c util.h globals.h y.tab.h
	$(CC) $(CFLAGS) -c util.c

symlist.o: symlist.c symlist.h 
	$(CC) $(CFLAGS) -c symlist.c

symhash.o: symhash.c symhash.h globals.h scan.h
	$(CC) $(CFLAGS) -c symhash.c

emit.o: emit.c emit.h globals.h
	$(CC) $(CFLAGS) -c emit.c

codegen.o: codegen.c globals.h symlist.h util.h emit.h codegen.h
	$(CC) $(CFLAGS) -c codegen.c

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
