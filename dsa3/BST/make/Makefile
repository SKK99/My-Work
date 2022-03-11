SRC=../src/
OBJ=../obj/
OUTPUT=../bin/
INCLUDE=../include/
CC=gcc
CFLOG=-g -Wall -c
OFLOG=-lm -o
IFLOG=-I
VAL=--tool=memcheck --leak-check=yes --show-reachable=yes

$(OUTPUT)bst: $(OBJ)bst_fun.o $(OBJ)bst_main.o
	$(CC) $(OFLOG) $(OUTPUT)bst $(OBJ)bst_fun.o $(OBJ)bst_main.o
$(OBJ)bst_fun.o: $(SRC)bst_fun.c $(INCLUDE)bst.h
	$(CC) $(CFLOG) $(SRC)bst_fun.c $(IFLOG) $(INCLUDE)
	mv bst_fun.o $(OBJ)
$(OBJ)bst_main.o: $(SRC)bst_main.c $(INCLUDE)bst.h
	$(CC) $(CFLOG) $(SRC)bst_main.c $(IFLOG) $(INCLUDE)
	mv bst_main.o $(OBJ)

clean:
	rm $(OBJ)bst_fun.o $(OBJ)bst_main.o $(OUTPUT)*
run: $(OUTPUT)bst
	$(OUTPUT)bst  
	
val: $(OUTPUT)bst
	valgrind $(VAL) $(OUTPUT)bst	
