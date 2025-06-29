
#ifndef PRODUCTOCOMPRAS_H
#define PRODUCTOCOMPRAS_H

#include "Producto.h"
class Compras;

using namespace std;



class ProductoCompras: public ICollectible {
public:
    ProductoCompras(Producto* producto, int cantidad);
    ~ProductoCompras() override;
    int getCantidad() const;
    bool getEnviado() const;
    Producto* getProducto() const;
private:
	int Cantidad;
    bool Enviado;
    Producto* producto;
    Compras* compras;
};



#endif
