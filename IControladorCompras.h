
#ifndef ICONTROLADORCOMPRAS_H
#define ICONTROLADORCOMPRAS_H

using namespace std;

class IControladorCompras {
public:
    virtual void agregarProducto(string &CodProd, int Cantidad) = 0;

};

#endif
