
#include "Vendedor.h"

Vendedor::Vendedor(string Nickname, string Contraseña, Date Fnacimiento, string RUT)
:Usuario(Nickname, Contraseña, Fnacimiento) {}

Vendedor::~Vendedor() {}

string Vendedor::getRUT() {return RUT;}