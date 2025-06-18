
#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Interfaces.h"
#include "Usuario.h"
#include "Promocion.h"
#include <iostream>

using namespace std;



class Vendedor:public Usuario {
public:
    Vendedor();
    virtual ~Vendedor();
    string getRUT();
private:
    string RUT;
    IDictionary *Productos;
    ICollection *Promociones;
};



#endif
