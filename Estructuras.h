#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H


#include <iostream>

using namespace std;

class Date {
public:
	Date(int dia, int mes, int año);
	Date();
	virtual ~Date();
	int getDia() const;
	int getMes() const;
	int getAño() const;
	string toString() const;
	static Date obtenerFechaActual();
	bool fechaEsMayorIgual(const Date& otraFecha) const;
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
	string toString() const;
	string getNomCalle() const;
	int getNroPuerta() const;
private:
	string NomCalle;
	int NroPuerta;
};

enum Cat{
	Ropa, Electrodomesticos, Otros
};

Cat stringToCat(const string& categoria);

#endif