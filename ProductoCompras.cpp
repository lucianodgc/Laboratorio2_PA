
#include "ProductoCompras.h"

ProductoCompras::ProductoCompras(Producto* producto, int cantidad) : Cantidad(cantidad),
Enviado(NULL), producto(producto), compras(nullptr) {}

ProductoCompras::~ProductoCompras() = default;

int ProductoCompras::getCantidad() const {return Cantidad;}

bool ProductoCompras::getEnviado() const {return Enviado;}

Producto* ProductoCompras::getProducto() const {return producto;}