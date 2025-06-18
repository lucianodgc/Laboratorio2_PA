
#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "Interfaces.h"
#include "IControladorUsuario.h"

using namespace std;



class ControladorUsuario:public IControladorUsuario {
public:
    ControladorUsuario();
    virtual ~ControladorUsuario();
    void altaCliente(string Nombre, string Contraseña,Date FNacimiento,
    DataDirec Direccion, string Ciudad);
    void altaVendedor(string Nombre, string Contraseña,
    Date FNacimiento, string RUT);
    void listarUsuarios();
private:
    IDictionary* Usuarios;
};



#endif
