
#include "PromocionProducto.h"
#include "Promocion.h"


PromocionProducto::PromocionProducto(Producto* Producto, int cantidadMinima)
    : producto(Producto), CantMinima(cantidadMinima) {}

PromocionProducto::~PromocionProducto() {}

Producto* PromocionProducto::getProducto() {return producto;}

float PromocionProducto::getDescuento() {return DescuentoPct;}

int PromocionProducto::getCantidadMinima() {return CantMinima;}