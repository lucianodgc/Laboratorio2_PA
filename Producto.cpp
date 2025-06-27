
#include "Producto.h"

Producto::Producto(int CodProd, string const &Nombre, float Precio, int stock, string const &Descripcion,
Cat Categoria, Vendedor* vendedor) : CodProd(CodProd), Stock(stock), Precio(Precio), Nombre(Nombre),
Descripcion(Descripcion), Categoria(Categoria), vendedor(vendedor) {Comentarios = new OrderedDictionary();}

Producto::~Producto() = default;

int Producto::getCodProd() const {return CodProd;}

string Producto::getNombre() const {return Nombre;}

float Producto::getPrecio() const {return Precio;}

int Producto::getStock() const {return Stock;}

string Producto::getDescripcion() const {return Descripcion;}

Cat Producto::getCategoria() const {return Categoria;}

Vendedor* Producto::getVendedor() const {return vendedor;}