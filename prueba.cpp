#include <iostream>
#include <cstring>

using namespace std;

void DejarPrimeraPalabra(char c[]){
  int i=0;

  while(c[i]!=' ' && c[i]!='\t' && i<strlen(c))
    i++;

  if(i!=strlen(c))
    c[i]='\0';
}

int main(){
  char texto[50];

  cout << "Introduce una linea: ";
  cin.getline(texto,50);

  cout << "\nLa linea es: " << texto << endl;

  DejarPrimeraPalabra(texto);
  cout << "\nLa linea ahora es: " << texto << endl;
}
