
#ifndef PROMOCIONPRODUCTO_H
#define PROMOCIONPRODUCTO_H

#include "Promocion.h"

using namespace std;



class PromocionProducto {
public:
    PromocionProducto();
    virtual ~PromocionProducto();
private:
	int CantMinima;
    float DescuentoPct;
    Promocion* misPromociones;
};



#endif
