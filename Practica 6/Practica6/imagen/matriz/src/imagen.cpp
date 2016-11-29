#include <iostream>
#include <cstring>
#include <fstream>
#include "imagen.h"
#include "pgm.h"
#include "byte.h"

Imagen::Imagen(){     //Constructor por defecto de la imagen
  nfilas=0;
  ncolumnas=0;        //Ponemos todos los valores a 0
  m=0;
}

Imagen::Imagen(int filas, int columnas){      //Creamos una imagen con filas y columnas en negro
  m=0;                                        //Ponemos los datos a 0
  crear(filas,columnas);                      //Creamos la imagen
}

void Imagen::crear(int filas, int columnas){      //Crear una imagen con filas y columnas indicadas
  if(filas>=0 && columnas>=0){                    //Si las filas y columnas son mayores o iguales que 0
    if(m!=0){                                     //Si no esta vacia la imagen
      delete [] m[0];                             //Eliminamos la imagen
      delete [] m;                                //Eliminamos el vector de punteros
      m=0;                                        //Ponemos la matriz a 0
    }
    nfilas=filas;                                 //Ponemos las filas y las columnas elegidas
    ncolumnas=columnas;

    m=new byte *[nfilas];                         //Creamos el vector de punteros
    m[0]=new byte [nfilas*ncolumnas];             //Creamos la imagen

    for (int i=1; i<nfilas;++i)                   //Recorremos el vector de m para seleccionar las filas
      m[i] = m[i-1]+ncolumnas;

    for(int i=0;i<nfilas;i++)                     //Recorremos la matriz completa y ponemos los elementos a 0
      for(int j=0;j<ncolumnas;j++)
        m[i][j]=0;
  }
}

int Imagen::filas() const{
  return nfilas;
}

int Imagen::columnas() const{
  return ncolumnas;
}

void Imagen::set(int x, int y, byte v){
  if(x<nfilas && y<ncolumnas)
    m[x][y]=v;
}

byte Imagen::get(int x, int y) const{
  if(x<nfilas && y<ncolumnas)
    return m[x][y];
}

void Imagen::setPos(int i, byte v){
  if(i<nfilas*ncolumnas)
    m[0][i]=v;
}

byte Imagen::getPos(int i) const{
  if(i<nfilas*ncolumnas)
    return m[0][i];
}

bool Imagen::leerImagen(const char nombreFichero[]){
  TipoImagen info;
  info=infoPGM(nombreFichero,nfilas,ncolumnas);
  crear(nfilas,ncolumnas);
  if(info==IMG_PGM_BINARIO){
    return leerPGMBinario(nombreFichero,m[0],nfilas,ncolumnas);
  }
  else if(info==IMG_PGM_TEXTO){
    return leerPGMTexto(nombreFichero,m[0],nfilas,ncolumnas);
  }
}

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario) const{
  if(esBinario)
    return escribirPGMBinario(nombreFichero,m[0],nfilas,ncolumnas);
  else
    return escribirPGMTexto(nombreFichero,m[0],nfilas,ncolumnas);
}

Imagen Imagen::plano(int k){
  Imagen img;
  bool encendido;

  img.nfilas=nfilas;
  img.ncolumnas=ncolumnas;

  for(int i=0;i<nfilas;i++)
    for(int j=0;j<ncolumnas;j++){
      encendido=getbit(m[i][j],k);
      if(encendido){
        img.m[i][j]=0;
        on(img.m[i][j],7);
      }
      else
        img.m[i][j]=0;
      }
  return img;
}

bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){      //Nos va a devolver la imagen transformada en simbolos
  bool transformado=false;
  int elementos=strlen(grises);
  int posicion,pos=0;

  for(int i=0;i<maxlong;i++)
    arteASCII[i]=0;

  if(maxlong>nfilas*ncolumnas){                            //Recorremos el vector completo para ir rellenandolo
    for(int i=0;i<nfilas;i++){
      for(int j=0;j<ncolumnas;j++){
        posicion=m[i][j]*elementos/256;                   //Calculamos el elemento de grises que pertenece a cada posicion de la imagen
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

void Imagen::destruir(){
  if(m!=0){                       //Si no esta vacia la matriz
    delete [] m[0];               //Eliminamos la imagen
    delete [] m;                  //Eliminamos el vector de punteros
  }
  m=0;
}

bool Imagen::listaAArteASCII(const Lista celdas){
  bool exito=false;

  if(celdas.longitud()>0){
    string valor,nombre;
    char n='1';
    char arteASCII[4501];
    ofstream fichs;
    char grises[100],salida[100];

    for(int i=0;i<celdas.longitud();i++){
      valor=celdas.getCelda(i);
      strcpy(grises,valor.c_str());
      nombre="ascii";
      nombre=nombre+n+".txt";
      fichs.open(strcpy(salida,nombre.c_str()));
      if(aArteASCII(grises, arteASCII, 4500))
        fichs << arteASCII;
      else
        cout << "La conversion no ha sido posible" << endl;
      fichs.close();
      n++;
    }
    exito=true;
  }
  return exito;
}

Imagen::~Imagen(){        //Destructor de la imagen
  destruir();             //Llamamos al metodo destruir
}

Imagen::Imagen(const Imagen &img){
  crear(img.nfilas,img.ncolumnas);

  *this=img;
}

Imagen& Imagen::operator=(const Imagen &otra_imagen){
  if(otra_imagen.m!=this->m)
    destruir();

  crear(otra_imagen.nfilas,otra_imagen.ncolumnas);
  for(int i=0;i<nfilas;i++)
    for(int j=0;j<ncolumnas;j++)
      m[i][j]=otra_imagen.m[i][j];

  return *this;
}

Imagen Imagen::operator+(const Imagen &otra)const{
  int filas,columnas;
  if(this->filas()>=otra.nfilas)
    filas=this->filas();
  else
    filas=otra.nfilas;

  columnas=this->columnas()+otra.ncolumnas;

  Imagen resultado(filas,columnas);

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
