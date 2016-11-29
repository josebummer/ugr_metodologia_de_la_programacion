
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib


all: $(BIN)/testimagen $(BIN)/arteASCII2 $(BIN)/suma

$(BIN)/suma: $(LIB)/libimagen.a $(SRC)/suma.cpp
	g++ $(SRC)/suma.cpp -o $(BIN)/suma -limagen -I$(INC) -L$(LIB)

$(BIN)/testarteASCII: $(LIB)/libimagen.a $(SRC)/testarteASCII.cpp
	g++ $(SRC)/testarteASCII.cpp -o $(BIN)/testarteASCII -limagen -I$(INC) -L$(LIB)

$(BIN)/testimagen: $(LIB)/libimagen.a $(SRC)/testimagen.cpp
	g++ $(SRC)/testimagen.cpp -o $(BIN)/testimagen -limagen -I$(INC) -L$(LIB)

$(BIN)/arteASCII2: $(LIB)/libimagen.a $(SRC)/arteASCII2.cpp
	g++ $(SRC)/arteASCII2.cpp -o $(BIN)/arteASCII2 -limagen -I$(INC) -L$(LIB)

$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o
	ar rsv $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	g++ -c $(SRC)/byte.cpp -o $(OBJ)/byte.o -I$(INC)

$(OBJ)/lista.o: $(SRC)/lista.cpp $(INC)/lista.h
	g++ -c $(SRC)/lista.cpp -o $(OBJ)/lista.o -I$(INC)

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h $(INC)/lista.h
	g++ -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -I$(INC)/

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h $(INC)/imagen.h $(INC)/byte.h
	g++ -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -I$(INC)/

# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean:
	@echo "Limpiando..."
	rm $(OBJ)/*.o $(LIB)/lib*.a ./a*.txt

mrproper: clean
	rm $(BIN)/*
