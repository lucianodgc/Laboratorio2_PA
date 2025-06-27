
#ifndef COMPRAS_H
#define COMPRAS_H

#include "Estructuras.h"
#include "Interfaces.h"

using namespace std;

class Compras: public ICollectible {
public:
    Compras(float montoFinal);
    ~Compras() override;
    Date getFCompra();
    float getMontoFinal() const;
private:
    Date FCompra;
    float MontoFinal;
    ICollection* ProdutoCompras;

};



#endif
