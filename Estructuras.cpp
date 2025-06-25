#include "Estructuras.h"
#include <ctime>

Date::Date(int d, int m, int a) : dia(d), mes(m), año(a) {}
Date::Date(){}
Date::~Date() {}

int Date::getDia() {return dia;}
int Date::getMes() {return mes;}
int Date::getAño() {return año;}

string Date::toString() {return to_string(dia) + "/" + to_string(mes) + "/" + to_string(año);}

Date Date::obtenerFechaActual() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    return Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}

bool Date::fechaEsMayorIgual(const Date& otraFecha) {
    if (this->año > otraFecha.año) return true;
    if (this->año < otraFecha.año) return false;

    if (this->mes > otraFecha.mes) return true;
    if (this->mes < otraFecha.mes) return false;

    return this->dia >= otraFecha.dia;
}


DataDirec::DataDirec(const string& nomCalle, int nroPuerta) : NomCalle(nomCalle), NroPuerta(nroPuerta) {}
DataDirec::DataDirec() {}
DataDirec::~DataDirec() {}
string DataDirec::toString() {return "Nombre Calle: " + NomCalle + ", NroPuerta: " + to_string(NroPuerta);}
string DataDirec::getNomCalle() {return NomCalle;}
int DataDirec::getNroPuerta() {return NroPuerta;}

Cat stringToCat(const string& categoria) {
    if (categoria == "ropa" || categoria == "Ropa" || categoria == "ROPA") return Ropa;
    if (categoria == "electrodomesticos" || categoria == "Electrodomesticos" ||
        categoria == "ELECTRODOMESTICOS") return Electrodomesticos;
    if (categoria == "otros" || categoria == "Otros" || categoria == "OTROS") return Otros;

    cout << "\nCategoría inválida, usando Otros por defecto." << endl;
    return Otros;

}
