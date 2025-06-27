#include "Estructuras.h"
#include <ctime>

Date::Date(int d, int m, int a) : dia(d), mes(m), año(a) {}
Date::Date () {}
Date::~Date() = default;

int Date::getDia() const {return dia;}
int Date::getMes() const {return mes;}
int Date::getAño() const {return año;}

string Date::toString() const {return to_string(dia) + "/" + to_string(mes) + "/" + to_string(año);}

Date Date::obtenerFechaActual() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    return {now->tm_mday, now->tm_mon + 1, now->tm_year + 1900};
}

bool Date::fechaEsMayorIgual(const Date& otraFecha) const {
    if (this->año > otraFecha.año) return true;
    if (this->año < otraFecha.año) return false;

    if (this->mes > otraFecha.mes) return true;
    if (this->mes < otraFecha.mes) return false;

    return this->dia >= otraFecha.dia;
}


DataDirec::DataDirec(string const &nomCalle, int nroPuerta) : NomCalle(nomCalle), NroPuerta(nroPuerta) {}
DataDirec::DataDirec() {}
DataDirec::~DataDirec() = default;
string DataDirec::toString() const {return "Nombre Calle: " + NomCalle + ", NroPuerta: " + to_string(NroPuerta);}
string DataDirec::getNomCalle() const {return NomCalle;}
int DataDirec::getNroPuerta() const {return NroPuerta;}

Cat stringToCat(const string& categoria) {
    if (categoria == "ropa" || categoria == "Ropa" || categoria == "ROPA") return Ropa;
    if (categoria == "electrodomesticos" || categoria == "Electrodomesticos" ||
        categoria == "ELECTRODOMESTICOS") return Electrodomesticos;
    if (categoria == "otros" || categoria == "Otros" || categoria == "OTROS") return Otros;

    cout << "\nCategoría inválida, usando Otros por defecto." << endl;
    return Otros;

}
