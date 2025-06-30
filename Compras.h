
#ifndef COMPRAS_H
#define COMPRAS_H

#include "Estructuras.h"
#include "Interfaces.h"
#include "ProductoCompras.h"

using namespace std;

class Compras: public ICollectible {
public:
    Compras(float montoFinal, Date const &fCompra);
    ~Compras() override;
    Date getFCompra();
    float getMontoFinal() const;
    ICollection* getProductoCompras() const;
    void agregarProducto(Producto* producto, int cantidad) const;
    void finalizarCompra(const Date& fecha, float montoFinal);

private:
    Date FCompra;
    float MontoFinal;
    ICollection* productoCompras;

};



#endif
