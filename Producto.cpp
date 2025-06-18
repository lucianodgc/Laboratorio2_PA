
#include "Producto.h"

Producto::Producto() {}

Producto::~Producto() {}

string Producto::getCodProd(){return CodProd;}

string Producto::getNombre(){return Nombre;}

float Producto::getPrecio(){return Precio;}

int Producto::getStock(){return Stock;}

string Producto::getDescripcion(){return Descripcion;}

Cat Producto::getCategoria(){return Categoria;}