#include <iostream>
#include <cmath> 
#include "punto.h"
#include "circulo.h"

using namespace std;

void EscribirCirculo(const Circulo &p)
{
	cout << "El centro del circulo es: ";
	EscribirPunto(p.centro);
	cout << "El radio del circulo es: " << p.radio;
}

Circulo LeerCirculo()
{
	Punto centro;
	Circulo c;
	double radio;

	do{
		cout << "Introduce el valor del radio: ";
		cin >> radio;
	}while(radio<=0);

	cout << "Introduce los valores para el centro: " << endl;
	centro=LeerPunto();

	c.centro=centro;
	c.radio=radio;

	return c;
}

double AreaCirculo(const Circulo &c)
{
	return PI*pow(c.radio,2);
}
