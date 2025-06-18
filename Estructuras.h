#include <iostream>
using namespace std;

typedef struct Date {
	int anio;
	int mes;
	int dia;
};

struct DataDirec {
	string NomCalle;
    int NroPuerta;
};

typedef enum{
	Ropa, Electrodomesticos, Otros
}Cat;