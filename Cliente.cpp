
#include "Cliente.h"

Cliente::Cliente(string const &Nickname, string const &Contraseña, Date const &Fnacimiento,
DataDirec const &Direccion, string const &Ciudad) : Usuario(Nickname, Contraseña, Fnacimiento),
Direccion(Direccion), Ciudad(Ciudad), compras(new List()) {}

Cliente::~Cliente() = default;

DataDirec Cliente::getDireccion() {return Direccion;}

string Cliente::getCiudad() {return Ciudad;}

void Cliente::crearCompra(float montoFinal, Date fCompra) const {
    auto* comp = new Compras(montoFinal, fCompra);
    compras->add(comp);
}

