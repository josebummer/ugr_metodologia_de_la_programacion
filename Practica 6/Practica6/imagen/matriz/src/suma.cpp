#include <iostream>
#include <cstring>
#include "imagen.h"

using namespace std;

const int MAXLONG = 1000;

int main(int argc, char *argv[]){
  char ficheroImagen1[MAXLONG];
  char ficheroImagen2[MAXLONG];
  char ficheroImagen_salida[MAXLONG];
  char flag;
  Imagen origen1;
  Imagen origen2;
  Imagen resultado;

  if(argc==5){
    strcpy(ficheroImagen1,argv[1]);
    strcpy(ficheroImagen2,argv[2]);
    strcpy(ficheroImagen_salida,argv[3]);
    flag=*argv[4];
  }
  else{
    cerr << endl << "Uso:" << endl << "<Fichero_IMAGEN1> <Fichero_IMAGEN2> <FIchero_SALIDA> <FLAG> " << endl;
    return 1;
  }


  if (!origen1.leerImagen(ficheroImagen1)){
  cerr << "Error leyendo imagen " << ficheroImagen1 << endl;
  return 1;
  }

  if (!origen2.leerImagen(ficheroImagen2)){
  cerr << "Error leyendo imagen " << ficheroImagen2 << endl;
  return 1;
  }

  resultado=origen1+origen2;

  if(flag=='t')
    if (resultado.escribirImagen(ficheroImagen_salida, false))
      cout << "Guardado correctamente \n";
  	else{
  		cerr << "Error guardando la imagen\n";
  		return 1;
    }
  else if(flag=='b')
    if (resultado.escribirImagen(ficheroImagen_salida, true))
      cout << "Guardado correctamente \n";
    else{
      cerr << "Error guardando la imagen\n";
      return 1;
      }

  return 0;
}
