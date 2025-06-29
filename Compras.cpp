
#include "Compras.h"

Compras::Compras(float montoFinal, Date fCompra) : FCompra(fCompra), MontoFinal(montoFinal) {productoCompras = new List();}

Compras::~Compras() = default;

Date Compras::getFCompra(){return FCompra;}

float Compras::getMontoFinal() const {return MontoFinal;}

void Compras::agregarProducto(Producto* producto, int cantidad) {
    auto* pp = new ProductoCompras(producto, cantidad);
    productoCompras->add(pp);
}

ICollection* Compras::getProductoCompras() const {return productoCompras;}

void Compras::finalizarCompra(const Date& fecha, float monto) {
    this->FCompra = fecha;
    this->MontoFinal = monto;
}