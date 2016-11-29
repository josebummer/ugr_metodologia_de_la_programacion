
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib


all: $(BIN)/arteASCII $(BIN)/testarteASCII $(BIN)/testplano $(BIN)/testimagen

$(BIN)/arteASCII: $(LIB)/libimagen.a $(SRC)/arteASCII.cpp
	g++ $(SRC)/arteASCII.cpp -o $(BIN)/arteASCII -limagen -I$(INC) -L$(LIB)

$(BIN)/testarteASCII: $(LIB)/libimagen.a $(SRC)/testarteASCII.cpp
	g++ $(SRC)/testarteASCII.cpp -o $(BIN)/testarteASCII -limagen -I$(INC) -L$(LIB)

$(BIN)/testplano: $(LIB)/libimagen.a $(SRC)/testplano.cpp
	g++ $(SRC)/testplano.cpp -o $(BIN)/testplano -limagen -I$(INC) -L$(LIB)

$(BIN)/testimagen: $(LIB)/libimagen.a $(SRC)/testimagen.cpp
	g++ $(SRC)/testimagen.cpp -o $(BIN)/testimagen -limagen -I$(INC) -L$(LIB)

$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o
	ar rsv $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	g++ -c $(SRC)/byte.cpp -o $(OBJ)/byte.o -I$(INC)

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	g++ -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -I$(INC)/

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h $(INC)/imagen.h $(INC)/byte.h
	g++ -c $(SRC)/pgm.cpp -o $(OBJ)/pgm.o -I$(INC)/

# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean:
	@echo "Limpiando..."
	rm $(OBJ)/*.o $(LIB)/lib*.a

mrproper: clean
	rm $(BIN)/*
