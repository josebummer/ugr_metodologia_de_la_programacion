#include <iostream>
#include <cstring>
#include <fstream>
#include "imagen.h"
#include "pgm.h"
#include "byte.h"

Imagen::Imagen(){     //Constructor por defecto de la imagen
  nfilas=0;
  ncolumnas=0;        //Ponemos todos los valores a 0
  datos=0;
}

Imagen::Imagen(int filas, int columnas){      //Creamos una imagen con filas y columnas en negro
  datos=0;                                    //Ponemos los datos a 0
  crear(filas,columnas);                      //Creamos la imagen
}

void Imagen::crear(int filas, int columnas){        //Crear una imagen con filas y columnas indicadas
  if(filas>=0 && columnas>=0){                      //Si las filas y las columnas indicadas son mayores o iguales que 0...
    if(datos!=0){                                   //Si la imagen no esta vacia...
      delete [] datos;                              //Eliminamos la imagen
      datos=0;                                      //Ponemos los datos a 0
    }
    nfilas=filas;                                   //Damos el valor a las filas y las columnas
    ncolumnas=columnas;

    int tam=nfilas*ncolumnas;                       //Calculamos el tamaño completo del vecto
    datos=new byte [tam];                           //Creamos en memoria el vector con el tamaño calculado

    for(int i=0;i<tam;i++)                          //Recorremos la imagen y ponemos todos los elementos a 0
      datos[i]=0;
  }
}

int Imagen::filas() const{
  return nfilas;
}

int Imagen::columnas() const{
  return ncolumnas;
}

void Imagen::set(int y, int x, byte v){
  int i=y*ncolumnas+x;
  if(i<ncolumnas*nfilas)
    datos[i]=v;
}

byte Imagen::get(int y, int x) const{
  int i=y*ncolumnas+x;
  if(i<nfilas*ncolumnas)
    return datos[i];
}

void Imagen::setPos(int i, byte v){
  if(i<nfilas*ncolumnas)
    datos[i]=v;
}

byte Imagen::getPos(int i) const{
  if(i<nfilas*ncolumnas)
    return datos[i];
}

bool Imagen::leerImagen(const char nombreFichero[]){                        //Leemos una imagen con el nombre de ficero indicada
  TipoImagen info;
  info=infoPGM(nombreFichero,nfilas,ncolumnas);                             //Vemos la info de la imagen
  crear(nfilas,ncolumnas);
  if(info==IMG_PGM_BINARIO){                                                //Dependiendo de si es texto a binario leemos de una manera
    return leerPGMBinario(nombreFichero,datos,nfilas,ncolumnas);
  }
  else if(info==IMG_PGM_TEXTO){
    return leerPGMTexto(nombreFichero,datos,nfilas,ncolumnas);
  }
}

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario) const{        //Escribimos la imagen indicada
  if(esBinario)                                                                       //Si es binaria escribimos de una manera  si es de texto en otra
    return escribirPGMBinario(nombreFichero,datos,nfilas,ncolumnas);
  else
    return escribirPGMTexto(nombreFichero,datos,nfilas,ncolumnas);
}

Imagen Imagen::plano(int k){
  Imagen img;
  bool encendido;

  img.nfilas=nfilas;
  img.ncolumnas=ncolumnas;

  for(int i=0;i<ncolumnas*nfilas;i++){
    encendido=getbit(datos[i],k);
    if(encendido){
      img.datos[i]=0;
      on(img.datos[i],7);
    }
    else
      img.datos[i]=0;
  }
  return img;
}

bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){      //Nos va a devolver la imagen transformada en simbolos
  bool transformado=false;
  int elementos=strlen(grises);
  int posicion,pos=0,k;

  for(int i=0;i<maxlong;i++)                                //Inicializamos todos los valores por si la imagen es menor
    arteASCII[i]=0;

  if(maxlong>nfilas*ncolumnas){                            //Recorremos el vector completo para ir rellenandolo
    for(int i=0;i<nfilas;i++){
      for(int j=0;j<ncolumnas;j++){
        k=i*ncolumnas+j;
        posicion=datos[k]*elementos/256;                   //Calculamos el elemento de grises que pertenece a cada posicion de la imagen
        arteASCII[pos]=grises[posicion];                   //Escribimos el elemento en el vector
        pos++;
      }
      arteASCII[pos]='\n';
      pos++;
    }
    transformado=true;
  }
  return transformado;                                     //Devolvemos si la transformacion a sido posible
}

void Imagen::destruir(){                //Destruye una imagen
  if(datos!=0){                         //Si no esta vacia
    delete [] datos;                    //Eliminamos la imagen
    nfilas=ncolumnas=0;                 //Ponemos todos los datos a 0
    datos=0;
  }
}

bool Imagen::listaAArteASCII(const Lista celdas){       //Reibiendo una lista va a escribir distintos ficheros con la imagen y distintos elementos para cada una de ellas
  bool exito=false;

  if(celdas.longitud()>0){                              //Vemos si la lista tiene elementos
    string valor,nombre;
    char n='1';
    char arteASCII[4501];
    ofstream fichs;
    char grises[100],salida[100];

    for(int i=0;i<celdas.longitud();i++){               //Vamos recorriendo la lista
      valor=celdas.getCelda(i);
      strcpy(grises,valor.c_str());                     //Creamos el nombre de los ficheros
      nombre="ascii";
      nombre=nombre+n+".txt";
      fichs.open(strcpy(salida,nombre.c_str()));
      if(aArteASCII(grises, arteASCII, 4500))            //Creamos la imagen con la celda correspondiente de la lista
        fichs << arteASCII;                             //Lo metemos en un fichero
      else
        cout << "La conversion no ha sido posible" << endl;
      fichs.close();
      n++;
    }
    exito=true;
  }
  return exito;                                             //Devolvemos si la conversion a sido posible
}

Imagen::~Imagen(){        //Destructor de la clase
  destruir();             //Llamamos al metodo destruir
}

Imagen::Imagen(const Imagen &img){            //Constructor de copia de la imagen
  this->datos=0;                              //Ponemos los datos de la imagen interna a 0

  *this=img;                                  //igualamos la imagen interna a la imagen que queremos copiar
}

Imagen& Imagen::operator=(const Imagen &otra_imagen){         //Operador de igualdad
  if(otra_imagen.datos!=this->datos)                          //Si no son iguales...
    destruir();                                               //Destruimos la imagen interna

  crear(otra_imagen.nfilas,otra_imagen.ncolumnas);            //Creamos la imagen interna del mismo tamaño que la externa
  int tam=nfilas*ncolumnas;
    for(int i=0;i<tam;i++)                                    //Rellenamos la imagen interna con los datos de la externa
      datos[i]=otra_imagen.datos[i];

  return *this;                                               //Devolvemos la referencia a la imgen interna
}

Imagen Imagen::operator+(const Imagen &otra)const{            //Operador de suma
  int filas,columnas;
  if(this->filas()>=otra.nfilas)                              //Vemos cual de las dos imagenes tiene el numero de filas mas grande
    filas=this->filas();                                      //Seleccionamos ese numero como tamaño de la suma
  else
    filas=otra.nfilas;

  columnas=this->columnas()+otra.ncolumnas;                   //Sumamos el numero de columnas para darle valor a la suma

  Imagen resultado(filas,columnas);                           //Creamos la imagen suma con las filas y columnas calculadas

  int c=0;
  for(int i=0;i<this->filas();i++){                           //Metemos la primera imagen en la suma
    c=0;
    for(int j=0;j<this->columnas();j++){
      resultado.set(i,j,this->get(i,j));
      c++;
    }
  }

  for(int i=0;i<otra.filas();i++){                            //Metemos la segunda imagen seguidamente a la primera en la suma
    c=this->columnas();
    for(int j=0;j<otra.columnas();j++){
      resultado.set(i,c,otra.get(i,j));
      c++;
    }
  }

  return resultado;
}
