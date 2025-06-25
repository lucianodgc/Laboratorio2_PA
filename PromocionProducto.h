
#ifndef PROMOCIONPRODUCTO_H
#define PROMOCIONPRODUCTO_H

#include "IControlador.h"
#include "Producto.h"

using namespace std;

class Promocion;

class PromocionProducto: public ICollectible {
public:
    PromocionProducto(Producto* Producto, int cantidadMinima);
    virtual ~PromocionProducto();
    Producto* getProducto();
    float getDescuento();
    int getCantidadMinima();
private:
	int CantMinima;
    float DescuentoPct;
    Promocion* Promocion;
    Producto* producto;
};



#endif
