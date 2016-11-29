BIN = bin
OBJ = obj
LIB = lib
SRC = src
INC = include

bin/main : $(OBJ)/main.o $(OBJ)/bloqueLed.o
	g++ -o $(BIN)/main $(OBJ)/main.o $(OBJ)/bloqueLed.o

obj/main.o: $(INC)/bloqueLed.h $(SRC)/main.cpp
	g++ -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)

obj/bloqueLed.o: $(INC)/bloqueLed.h $(SRC)/bloqueLed.cpp
	g++ -c $(SRC)/bloqueLed.cpp -o $(OBJ)/bloqueLed.o -I$(INC)

clean:
	@echo "Limpiando..."
	rm $(OBJ)/*.o

mrproper: clean
	rm $(BIN)/main
