
#include "Producto.h"

Producto::Producto(int CodProd, string Nombre, float Precio, int stock, string Descripcion, Cat Categoria) {
    this->CodProd = CodProd;
    this->Nombre = Nombre;
    this->Precio = Precio;
    this->Stock = stock;
    this->Categoria = Categoria;
    this->Descripcion = Descripcion;
}

Producto::~Producto() {}

int Producto::getCodProd(){return CodProd;}

string Producto::getNombre(){return Nombre;}

float Producto::getPrecio(){return Precio;}

int Producto::getStock(){return Stock;}

string Producto::getDescripcion(){return Descripcion;}

Cat Producto::getCategoria(){return Categoria;}