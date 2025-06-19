#include "Estructuras.h"

Date::Date(int d, int m, int a) : dia(d), mes(m), año(a) {}
Date::Date(){}
Date::~Date() {}

int Date::getDia() {return dia;}
int Date::getMes() {return mes;}
int Date::getAño() {return año;}

string Date::toString() {return to_string(dia) + "/" + to_string(mes) + "/" + to_string(año);}


DataDirec::DataDirec(const string& nomCalle, int nroPuerta) : NomCalle(nomCalle), NroPuerta(nroPuerta) {}
DataDirec::DataDirec() {}
DataDirec::~DataDirec() {}
string DataDirec::toString() { return NomCalle + "-" + to_string(NroPuerta); }
string DataDirec::getNomCalle() { return NomCalle; }
int DataDirec::getNroPuerta() { return NroPuerta; }