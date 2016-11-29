#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
  int nfilas=3,*ncolumnas;
  const char fijo[]= "MP";
  double **datos;
  ofstream fich;
  char texto[] = "# examen de MP hoooyy";
  char fichero[] = "probando.txt";

  ncolumnas=new int [nfilas];
  datos=new double* [nfilas];
  for(int i=0;i<nfilas;i++){
     ncolumnas[i]=i+2;
    datos[i]=new double [ncolumnas[i]];
  }
  for(int i=0;i<nfilas;i++)
    for(int j=0;j<ncolumnas[i];j++)
      datos[i][j]=i+j;
  fich.open(fichero);
  fich << fijo << endl;
  fich << texto << endl;
  fich << nfilas << endl;
  for(int i=0;i<nfilas;i++){
    fich.write((char*)&ncolumnas[i],sizeof(int));
    fich.write((char*)datos[i],sizeof(double)*ncolumnas[i]);
  }
  fich.close();

  for(int i=0;i<nfilas;i++)
    delete [] datos[i];
  delete [] datos;
  delete [] ncolumnas;
  return 0;
}
