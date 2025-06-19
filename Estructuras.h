#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H


#include <iostream>

using namespace std;

class Date {
public:
	Date(int dia, int mes, int año);
	Date();
	virtual ~Date();
	int getDia();
	int getMes();
	int getAño();
	string toString();
private:
	int dia;
	int mes;
	int año;
};

class DataDirec {
public:
	DataDirec(const string& nomCalle, int nroPuerta);
	DataDirec();
	virtual ~DataDirec();
	string toString();
	string getNomCalle();
	int getNroPuerta();
private:
	string NomCalle;
	int NroPuerta;
};

enum Cat{
	Ropa, Electrodomesticos, Otros
};


#endif