#include <string>
#include <iostream>
#include <fstream>
#include "lista.h"

using namespace std;

Lista::Lista(){
  cabecera=0;
}

Lista::Lista(string valor){
  cabecera=new Celda;
  cabecera->datos=valor;
  cabecera->siguiente=0;
}

void Lista::destruir(){
  if(cabecera!=0){
    Celda *p;
    while(cabecera!=0){
      p=cabecera;
      cabecera=cabecera->siguiente;
      delete p;
    }
    cabecera=0;
  }
}

void Lista::insertar(string valor){
  if(cabecera==0){
    cabecera=new Celda;
    cabecera->datos=valor;
    cabecera->siguiente=0;
  }
  else{
    Celda *p,*nuevo;
    p=cabecera;
    while(p->siguiente!=0)
      p=p->siguiente;
    nuevo=new Celda;
    nuevo->datos=valor;
    nuevo->siguiente=0;

    p->siguiente=nuevo;
  }
}

string Lista::getCelda(int pos) const{
  string val="";
  if(cabecera!=0){
    int i=0;
    Celda *p=cabecera;

    while(i<pos && p->siguiente!=0){
      p=p->siguiente;
      i++;
    }
    if(i==pos)
      val=p->datos;
  }
  return val;
}

int Lista::longitud() const{
  int lon=0;
  if(cabecera!=0){
    Celda *p=cabecera;
    while(p!=0){
      p=p->siguiente;
      lon++;
    }
  }
  return lon;
}

bool Lista::leerLista(const char nombrefichero[]){
	// vaciar la lista
	destruir();

	// abrir fichero (y comprobar que se abrió correctamente)
	ifstream fin;
	fin.open(nombrefichero);
	if (!fin){
		return false;
	}

	string grises;
	int lineas;
	getline(fin, grises); //la primera linea se ignora
	fin >> lineas; //leo el numero de datos de grises
	getline(fin, grises); //leer salto de linea

	if (!fin){ //¿hubo error en las lecturas?
		return false;
	}

	int i = 0;
	getline(fin, grises); //leer cadena de caracteres
	while ((i < lineas) && fin){
		if (grises != ""){ // saltar líneas en blanco
			insertar(grises);
			i++;
		}
		getline(fin, grises); //leer cadena de caracteres
	}

	if (i < lineas){ //¿hubo error en las lecturas?
		destruir();
		return false;
	}

	fin.close();
	return true;
}
