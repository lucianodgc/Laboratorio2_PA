#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H


#include <iostream>

using namespace std;

struct Date {
	int anio;
	int mes;
	int dia;
};

struct DataDirec {
	string NomCalle;
    int NroPuerta;
};

typedef enum Cat{
	Ropa, Electrodomesticos, Otros
};

#endif