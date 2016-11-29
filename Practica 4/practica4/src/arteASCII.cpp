#include <iostream>
#include <fstream>
#include <cstring>
#include "imagen.h"

using namespace std;

int main(){
  const int MAX=100;
  string nomcompleto,salida;
  Imagen origen;
  ifstream fich;
  ofstream fichs;
  int elementos;
  char grises[MAX],nombre[MAX],caracteres[MAX];
  char arteASCII[4501];

  cout << "Introduce el nombre de la imagen: ";
  cin.getline(nombre,MAX);

  // Leer la imagen
  if (!origen.leerImagen(nombre)){
   cerr << "error leyendo " << nombre << "\n";
   return 1;
  }

  cout << "Introduce el nombre del fichero de caraceteres: ";
  cin.getline(caracteres,MAX);

  fich.open(caracteres);
  if(!fich){
    cerr << "Error al abrir el fichero." << endl;
    return 1;
  }

  cout << "Introduce el nombre de fichero de salida: ";
  cin >> salida;

  char n='1';
  fich.getline(grises,MAX); //omitimos la primera linea;
  fich >> elementos;
  fich.getline(grises,MAX); //saltamos de linea
  for(int i=0;i<elementos;i++){
    fich.getline(grises,MAX);
    nomcompleto=salida+n+".txt";
    fichs.open(strcpy(nombre,nomcompleto.c_str()));
    if(origen.aArteASCII(grises, arteASCII, 4500))
        fichs << arteASCII;
    else
        cout << "La conversion no ha sido posible" << endl;
    fichs.close();
    n++;
  }
  fich.close();
}
