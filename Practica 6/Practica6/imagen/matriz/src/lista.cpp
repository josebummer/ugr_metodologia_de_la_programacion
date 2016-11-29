#include <fstream>
#include "lista.h"

Lista::Lista(){
  cabecera=0;         //Inicializamos la cabecera a 0
}

Lista::Lista(string valor){   //Creamos una lista con 1 unico valor
  cabecera=new Celda;         //Creamos una Celda en memoria y cabecera apunta a ella
  cabecera->datos=valor;      //Metemos el valor del string en la cabecera
  cabecera->siguiente=0;      //Ponemos el siguiente a 0 para poner fin a esta lista
}

void Lista::destruir(){                     //Destructor de la lista
  if(cabecera!=0){                          //Comprobamos si la celda no esta vacia y si no esta vacia continuamos
    Celda *p;                               //Si no esta vacia creamos una celda
    while(cabecera!=0){                     //Mientras la lista tenga elementos...
      p=cabecera;                           //Ponemos la celda creada a donde apunta cabecera para no perder la lista
      cabecera=cabecera->siguiente;         //Pasamos al siguiente valor de la lista
      delete p;                             // Eliminamos la celda anterior y seguimos eliminando celdas
    }
    cabecera=0;                             //Si esta vacia nos aseguramos poniendo el valor 0 a cabecera
  }
}

void Lista::insertar(string valor){         //Insertamos un valor a la lista
  if(cabecera==0){                          //Si la lista esta vacia...
    cabecera=new Celda;
    cabecera->datos=valor;                  //Relizamos el proceso de crear la primera celda como en el constructor
    cabecera->siguiente=0;
  }
  else{                                     //Si la lista no esta vacia...
    Celda *p,*nuevo;
    p=cabecera;                             //Creamos una celda para recorrer la lista y otra que sera la que añadiremos a la lista
    while(p->siguiente!=0)                  //Mientras no termine la lista...
      p=p->siguiente;                       //Avanzamos hasta llegar al final de la lista
    nuevo=new Celda;
    nuevo->datos=valor;                     //Creamos la celda que vamos a añadir
    nuevo->siguiente=0;

    p->siguiente=nuevo;                     //La añadimos a la lista
  }
}

string Lista::getCelda(int pos) const{          //Nos devolvera el contenido de una celda
  string val="";                                //Creamos un string vacio que en el caso de no existir sera lo que devuelva
  if(cabecera!=0){                              //Si la lista no esta vacia...
    int i=0;
    Celda *p=cabecera;                          //Creamos una celda para recorrer la lista

    while(i<pos && p->siguiente!=0){            //Mientras la lista tenga elementos y no hayamos llegado a la posicion indicada...
      p=p->siguiente;                           //Vamos pasando hasta llegar o a la posicion o al final de la lista
      i++;
    }
    if(i==pos)                                  //Comprobamos si hemos llegado a la posicion que queremos
      val=p->datos;                             //Si hemos llegado a la posicion, ponemos la informacion en la variable a devolver
  }
  return val;                                   //Devolvemos el string
}

int Lista::longitud() const{      //Nos devuelve la longitud de la lista
  int lon=0;
  if(cabecera!=0){
    Celda *p=cabecera;            //Si la lista no esta vacia creamos una celda para recorrerla
    while(p!=0){
      p=p->siguiente;             //Vamos avanzando hasta llegar al final y contando las celdas
      lon++;
    }
  }
  return lon;                     //Devolvemos el numero de celdas
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

Lista::~Lista(){      //Destructor de la lista
  destruir();         //Llamamos al metodo de destruir
}

Lista::Lista(const Lista &l){       //Constructor de copia
  this->cabecera=0;                 //Ponemos la cabecera a 0
  *this=l;                          //Igualamos la nueva lista a la lista de la que queremos copiar el contenido
}

Lista& Lista::operator=(const Lista &otra_lista){       //Operador de igualdad
  if(otra_lista.cabecera!=cabecera)                     //Si las dos listas no son iguales...
      destruir();                                       //Destruimos la lista
  Celda *p=otra_lista.cabecera;                         //Creamos una celda para recorrer la lista externa

  cabecera=0;                                           //Ponemos a 0 la cabecera de la lista interna

  while(p!=0){                                          //Mientras la lista externa tenga elementos
    insertar(p->datos);                                 //Insertamos las celdas en la lista interna
    p=p->siguiente;                                     //Vamos avanzando de celda
  }
  return *this;                                         //Devolvemos la referencia de la lista interna
}

Lista Lista::operator+(const string &cad){      //Operador sumatorio
  Lista resultado;                              //Cremos la lista que vamos a devolver

  resultado=*this;                              //Igualamos la lista a devolver con la lista interna
  resultado.insertar(cad);                      //Insertamos el string a la lista resultante

  return resultado;                             //Devolvemos la lista
}
