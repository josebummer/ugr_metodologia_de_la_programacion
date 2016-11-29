#include <iostream>
#include <cstring>
#include "imagen.h"
#include "pgm.h"
#include "byte.h"

using namespace std;

Imagen::Imagen(){
  nfilas=0;
  ncolumnas=0;
}

Imagen::Imagen(int filas, int columnas){
  crear(filas,columnas);
}

void Imagen::crear(int filas, int columnas){
  if(filas>=0 && columnas>=0){

    nfilas=filas;
    ncolumnas=columnas;

    for(int i=0;i<ncolumnas*nfilas;i++)
      datos[i]=0;
  }
}

int Imagen::filas(){
  return nfilas;
}

int Imagen::columnas(){
  return ncolumnas;
}

void Imagen::set(int y, int x, byte v){
  int i=y*ncolumnas+x;
  if(i<ncolumnas*nfilas)
    datos[i]=v;
}

byte Imagen::get(int y, int x){
  int i=y*ncolumnas+x;
  if(i<nfilas*ncolumnas)
    return datos[i];
}

void Imagen::setPos(int i, byte v){
  if(i<nfilas*ncolumnas)
    datos[i]=v;
}

byte Imagen::getPos(int i){
  if(i<nfilas*ncolumnas)
    return datos[i];
}

bool Imagen::leerImagen(const char nombreFichero[]){
  TipoImagen info;
  info=infoPGM(nombreFichero,nfilas,ncolumnas);
  if(info==IMG_PGM_BINARIO && nfilas*ncolumnas<MAXPIXELS){
    return leerPGMBinario(nombreFichero,datos,nfilas,ncolumnas);
  }
  else if(info==IMG_PGM_TEXTO && nfilas*ncolumnas<MAXPIXELS){
    return leerPGMTexto(nombreFichero,datos,nfilas,ncolumnas);
  }
}

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){
  if(esBinario)
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

bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){
  bool transformado=false;
  int elementos=strlen(grises);
  int posicion,pos=0,k;

  for(int i=0;i<maxlong;i++)
    arteASCII[i]=0;

  if(maxlong>nfilas*ncolumnas){
    for(int i=0;i<nfilas;i++){
      for(int j=0;j<ncolumnas;j++){
        k=i*ncolumnas+j;
        posicion=datos[k]*elementos/256;
        arteASCII[pos]=grises[posicion];
        pos++;
      }
      arteASCII[pos]='\n';
      pos++;
    }
    transformado=true;
  }
  return transformado;
}
