/*
Escriba una función que reciba una cadena de caracteres, una posición de
inicio I y una longitud L, y que nos devuelva la subcadena que comienza en
I y tiene tamaño L. Nota: Si la longitud es demasiado grande (se sale de la
cadena original), se devolverá una cadena de menor tamaño.
*/
#include <iostream>
#include <cstring>

using namespace std;

void Subcadena(const char c[], int i, int l, char r[]){
  if(i<strlen(c)){
    int pos=0;

    while(c[i]!='\0' && l>0){
        r[pos]=c[i];
        i++;
        pos++;
        l--;
    }
    r[pos]='\0';
  }
  else
    r[0]='\0';
}

int main(){
  char cad[50],res[50];
  int i,l;

  cout << "Introduce una cadena: ";
  cin.getline(cad,50);

  cout << "La cadena es: " << cad << endl;

  cout << "\nIntroduce la posicion desde donde empieza la subcadena: ";
  cin >> i;

  cout << "Introduce la longitud de la subcadena: ";
  cin >> l;

  Subcadena(cad,i,l,res);

  cout << "\nLa subcadena obtenida es: " << res << endl;
}
