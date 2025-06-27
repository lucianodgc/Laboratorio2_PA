
#ifndef PRODUCTOCOMPRAS_H
#define PRODUCTOCOMPRAS_H

#include "Producto.h"
#include "Compras.h"

using namespace std;



class ProductoCompras: public ICollectible {
public:
    ProductoCompras(int cantidad, bool enviado);
    ~ProductoCompras() override;
private:
	int Cantidad;
    bool Enviado;
    Producto *Productos;
    Compras *Compras;
};



#endif
