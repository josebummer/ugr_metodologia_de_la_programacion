BIN = bin
OBJ = obj
LIB = lib
SRC = src

bin/central : $(OBJ)/central.o $(LIB)/libformas.a
	g++ -o $(BIN)/central $(OBJ)/central.o -L$(LIB)/ -lformas

lib/libformas.a: $(OBJ)/punto.o $(OBJ)/circulo.o
	ar rsv $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o


obj/punto.o: $(SRC)/punto.cpp include/punto.h
	g++ -c $(SRC)/punto.cpp -o $(OBJ)/punto.o -Iinclude/

obj/central.o: $(SRC)/central.cpp include/circulo.h include/punto.h
	g++ -c $(SRC)/central.cpp -o $(OBJ)/central.o -Iinclude/


obj/circulo.o: $(SRC)/circulo.cpp include/circulo.h include/punto.h
	g++ -c $(SRC)/circulo.cpp -o $(OBJ)/circulo.o -Iinclude/

clean:
	@echo "Limpiando..."
	rm $(OBJ)/*.o $(LIB)/lib*.a

mrproper: clean
	rm $(BIN)/central
