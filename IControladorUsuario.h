
#ifndef ICONTROLADOR_H
#define ICONTROLADOR_H

#include <iostream>

#include "Cliente.h"
#include "Vendedor.h"

using namespace std;



class IControladorUsuario {
public:
    virtual ~IControladorUsuario() = default;
    virtual void altaCliente(string Nombre, string Contraseña,
    Date FNacimiento, DataDirec Direccion, string Ciudad) = 0;
    virtual void altaVendedor(string Nombre, string Contraseña,
    Date FNacimiento, string RUT) = 0;
    virtual void listarUsuarios() = 0;

};

#endif
