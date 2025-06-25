
#include "Producto.h"

Producto::Producto(int CodProd, string Nombre, float Precio, int stock, string Descripcion,
Cat Categoria, Vendedor* vendedor) : CodProd(CodProd), Nombre(Nombre), Precio(Precio), Stock(stock),
Descripcion(Descripcion), Categoria(Categoria), vendedor(vendedor) {Comentarios = new OrderedDictionary();}

Producto::~Producto() {}

int Producto::getCodProd(){return CodProd;}

string Producto::getNombre(){return Nombre;}

float Producto::getPrecio(){return Precio;}

int Producto::getStock(){return Stock;}

string Producto::getDescripcion(){return Descripcion;}

Cat Producto::getCategoria(){return Categoria;}

Vendedor* Producto::getVendedor() {return vendedor;}