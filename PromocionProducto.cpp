
#include "PromocionProducto.h"


PromocionProducto::PromocionProducto(Producto* Producto, int cantidadMinima)
: CantMinima(cantidadMinima), promocion(nullptr), producto(Producto) {}

PromocionProducto::~PromocionProducto() = default;

Producto* PromocionProducto::getProducto() const {return producto;}

int PromocionProducto::getCantidadMinima() const {return CantMinima;}
