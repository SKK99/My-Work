CC=gcc
CFLAGS= -c -g -Wall
VFLAGS= --tool=memcheck --leak-check=yes --show-reachable=yes
SRC=../src/
OBJ=../obj/
BIN=../bin/
INCLUDE=-I../include/
HEADER=../include/


$(BIN)main: $(OBJ)main.o $(OBJ)functions.o
	$(CC) $(OBJ)* -o $(BIN)main

$(OBJ)main.o: $(SRC)main.c $(HEADER)header.h
	$(CC) $(CFLAGS) $(SRC)main.c $(INCLUDE)
	mv main.o $(OBJ)
$(OBJ)functions.o: $(SRC)functions.c $(HEADER)header.h
	$(CC) $(CFLAGS) $(SRC)functions.c $(INCLUDE)
	mv functions.o $(OBJ)

valgrind:
	valgrind $(VFLAGS) $(BIN)main $(INPUT) $(OUTPUT)
clean: 
	rm $(BIN)*
	rm $(OBJ)*

