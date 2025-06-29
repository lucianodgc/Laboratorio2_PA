
#ifndef PROMOCIONPRODUCTO_H
#define PROMOCIONPRODUCTO_H

#include "Producto.h"

using namespace std;

class Promocion;

class PromocionProducto: public ICollectible {
public:
    PromocionProducto(Producto* Producto, int cantidadMinima);

    ~PromocionProducto() override;
    Producto* getProducto() const;
    int getCantidadMinima() const;
private:
	int CantMinima;
    Promocion* promocion;
    Producto* producto;
};



#endif
