
#ifndef COMPRAS_H
#define COMPRAS_H

#include "Estructuras.h"
#include "Interfaces.h"

using namespace std;

class Compras: public ICollectible {
public:
    Compras();
    virtual ~Compras();
    Date getFCompra();
    float getMontoFinal();
private:
    Date FCompra;
    float MontoFinal;
    ICollection *ProdutoCompras;

};



#endif
