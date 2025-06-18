
#include "Cliente.h"

Cliente::Cliente(string Nickname, string Contraseña, Date Fnacimiento,
DataDirec Direccion, string Ciudad):Usuario(Nickname, Contraseña, Fnacimiento) {}

Cliente::~Cliente() {}

DataDirec Cliente::getDireccion() {return Direccion;}

string Cliente::getCiudad() {return Ciudad;}