#include <iostream>
#include <string>

using namespace std;

class Persona{
  string nombre;
  int edad;
  int estatura;
  Persona *pareja;
public:
  Persona(const string &nom, int anios, int centimetros);
  Persona(const string &nom, int anios, int centimetros, Persona *par);
  string GetNombre() const;
  void SetNombre(const string &nom);
  int GetEdad() const;
  void SetEdad(int anios);
  int GetEstatura() const;
  void SetEstatura(int centimetros);
  Persona* GetPareja() const;
  string NombrePareja() const;
  void SetPareja(Persona *par);
};

int main(){
  Persona pepe("Pepe",23,187),maria("Maria",20,170),roberto("Roberto",39,185),lola("Lola",38,177);
  pepe.SetPareja(&maria);
  maria.SetPareja(&pepe);
  roberto.SetPareja(&lola);
  lola.SetPareja(&pepe);

  maria=lola;

  cout << "La persona " << pepe.GetNombre() << " con " << pepe.GetEdad() << " años, tiene como pareja a --> " << pepe.NombrePareja() << endl;

  return(0);
}

Persona::Persona(const string &nom, int anios, int centimetros){
  nombre=nom;
  if(anios<0)
    edad=0;
  else
    edad=anios;
  if(centimetros<0)
    estatura=0;
  else
    estatura=centimetros;
  pareja=0;
}
Persona::Persona(const string &nom, int anios, int centimetros, Persona *par){
  nombre=nom;
  if(anios<0)
    edad=0;
  else
    edad=anios;
  if(centimetros<0)
    estatura=0;
  else
    estatura=centimetros;
  pareja=par;
}
string Persona::GetNombre() const{
  return nombre;
}
void Persona::SetNombre(const string &nom){
  if(nom!="")
    nombre=nom;
}
int Persona::GetEdad() const{
  return edad;
}
void Persona::SetEdad(int anios){
  if(anios>=0)
    edad=anios;
}
int Persona::GetEstatura() const{
  return estatura;
}
void Persona::SetEstatura(int centimetros){
  if(centimetros>=0)
    estatura=centimetros;
}
Persona* Persona::GetPareja() const{
  return pareja;
}
void Persona::SetPareja(Persona *par){
  if(par!=0)
    pareja=par;
}
string Persona::NombrePareja() const{
  return pareja->nombre;
}
