
#include "ProductoCompras.h"

ProductoCompras::ProductoCompras(int cantidad, bool enviado) : Cantidad(cantidad), Enviado(enviado),
Productos(nullptr), Compras(nullptr) {}

ProductoCompras::~ProductoCompras() = default;
