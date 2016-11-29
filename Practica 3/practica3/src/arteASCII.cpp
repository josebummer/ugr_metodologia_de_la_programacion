#include <iostream>
#include <string>
#include "imagen.h"

using namespace std;

int main(){
  const int MAX=100;
  Imagen origen;
  char grises[MAX],nombre[MAX];
  char arteASCII[4501];

  cout << "Introduce el nombre de la imagen: ";
  cin.getline(nombre,MAX);

  cout << "Introduce los caracteres a intercambiar: " << endl;
  cin.getline(grises,MAX);

  // Leer la imagen
  if (!origen.leerImagen(nombre)){
   cerr << "error leyendo " << nombre << "\n";
   return 1;
  }

  cout << "\nLa imagen en arte ASCII es:\n";
  if(origen.aArteASCII(grises, arteASCII, 4500))
      cout << arteASCII;
  else
      cout << "La conversi�n no ha sido posible" << endl;
}
