
#ifndef PRODUCTOCOMPRAS_H
#define PRODUCTOCOMPRAS_H

#include "Producto.h"
#include "Compras.h"

using namespace std;



class ProductoCompras: public ICollectible {
public:
    ProductoCompras();
    virtual ~ProductoCompras();
private:
	int Cantidad;
    bool Enviado;
    Producto *Productos;
    Compras *Compras;
};



#endif
