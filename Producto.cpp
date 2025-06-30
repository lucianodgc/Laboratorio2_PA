
#include "Producto.h"
#include "Usuario.h"
#include "Comentario.h"

int Producto::ultimoCodProd = 0;

Producto::Producto(string const &Nombre, float Precio, int stock, string const &Descripcion,
Cat Categoria, Vendedor* vendedor) : CodProd(++ultimoCodProd), Stock(stock), Precio(Precio), Nombre(Nombre),
Descripcion(Descripcion), Categoria(Categoria), prodComp(nullptr), vendedor(vendedor) {Comentarios = new OrderedDictionary();}

Producto::~Producto() = default;

int Producto::getCodProd() const {return CodProd;}

string Producto::getNombre() const {return Nombre;}

float Producto::getPrecio() const {return Precio;}

int Producto::getStock() const {return Stock;}

string Producto::getDescripcion() const {return Descripcion;}

Cat Producto::getCategoria() const {return Categoria;}

Vendedor* Producto::getVendedor() const {return vendedor;}

IDictionary* Producto::getComentarios() const {return Comentarios;}

ProductoCompras* Producto::getProdComp() const {return prodComp;}

void Producto::agregarProdCompra(ProductoCompras* prodComp) {this->prodComp = prodComp;}

void Producto::agregarComentario(Comentario* &comen) const {
    int idComen= comen->getID();
    IKey* key = new Integer(idComen);
    Comentarios->add(key , comen);
    delete key;
}

void Producto::eliminarComentario(Comentario* const &comen) const {
    IKey* key = new Integer(comen->getID());
    Comentarios->remove(key);
    delete key;
}
