
#include "Cliente.h"

Cliente::Cliente(string Nickname, string Contraseña, Date Fnacimiento,
DataDirec Direccion, string Ciudad):Usuario(Nickname, Contraseña, Fnacimiento) {
    this->Ciudad = Ciudad;
    this->Direccion = Direccion;
}

Cliente::~Cliente() {}

DataDirec Cliente::getDireccion() {return Direccion;}

string Cliente::getCiudad() {return Ciudad;}