CC = gcc
CFLAGS = -g -Wall 
INCLUDEPATH = ./../include
SRCPATH = ./../src
OBJPATH = ./../obj
BINPATH = ./../bin
VFLAGS = v --tool=memcheck --leak-check=yes --show-reachable=yes
EXECS = $(BIN)final


$(BINPATH)/main: $(OBJPATH)/main.o $(OBJPATH)/function.o
	$(CC) $(CFLAGS) -o main $(OBJPATH)/main.o $(OBJPATH)/function.o
	mv main $(BINPATH)

$(OBJPATH)/main.o: $(SRCPATH)/main.c $(INCLUDEPATH)/header.h
	$(CC) $(CFLAGS) -c $(SRCPATH)/main.c -I $(INCLUDEPATH)/
	mv main.o $(OBJPATH)/

$(OBJPATH)/function.o: $(SRCPATH)/function.c $(INCLUDEPATH)/header.h
	$(CC) $(CFLAGS) -c $(SRCPATH)/function.c -I $(INCLUDEPATH)/
	mv function.o $(OBJPATH)/

clear:
	rm $(BINPATH)/main $(OBJPATH)/main.o $(OBJPATH)/function.o
	
valgrind:$(EXECS)
	valgrind $(VFLAGS) $(BINPATH)main
