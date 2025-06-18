
#ifndef CONTROLADORCOMPRAS_H
#define CONTROLADORCOMPRAS_H

#include "Interfaces.h"
#include "IControladorCompras.h"

using namespace std;



class ControladorCompras:public IControladorCompras {
public:
    ControladorCompras();
    virtual ~ControladorCompras();
private:
    IDictionary* Compras;
};



#endif
