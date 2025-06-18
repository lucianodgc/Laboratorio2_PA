
#ifndef CONTROLADORCOMPRAS_H
#define CONTROLADORCOMPRAS_H

#include "Interfaces.h"
#include "IControladorCompras.h"
#include <iostream>

using namespace std;



class ControladorCompras:public IControladorCompras {
public:
    ControladorCompras();
    virtual ~ControladorCompras();
    void agregarProducto(string &CodProd, int Cantidad);
private:
    IDictionary* Compras;
};



#endif
