
#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Interfaces.h"
#include "Usuario.h"
#include "Promocion.h"
#include "Producto.h"
#include <iostream>

using namespace std;



class Vendedor:public Usuario {
public:
    Vendedor(string Nickname, string Contraseña, Date Fnacimiento, string RUT);
    virtual ~Vendedor();
    string getRUT();
    void Vendedor::agregarProducto(Producto* p);
private:
    string RUT;
    IDictionary *Productos;
    ICollection *Promociones;
};



#endif
