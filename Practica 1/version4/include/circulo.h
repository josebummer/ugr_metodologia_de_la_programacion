#ifndef _CIRCULO_H_
#define _CIRCULO_H_
#include "punto.h"

const double PI=3.1416;

struct Circulo {
    Punto centro; 
    double radio; 
};

void EscribirCirculo(const Circulo &p);
Circulo LeerCirculo();
double AreaCirculo(const Circulo &c);

#endif
