
#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "Interfaces.h"
#include "IControladorUsuario.h"

using namespace std;



class ControladorUsuario:public IControladorUsuario {
public:
    ControladorUsuario();
    virtual ~ControladorUsuario();
private:
    IDictionary* Cliente;
    IDictionary* Vendedor;
};



#endif
