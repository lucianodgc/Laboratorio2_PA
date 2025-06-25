
#include "Vendedor.h"

Vendedor::Vendedor(string Nickname, string Contraseña, Date Fnacimiento, string RUT)
: Usuario(Nickname, Contraseña, Fnacimiento), RUT(RUT) {Productos = new OrderedDictionary();}

Vendedor::~Vendedor() {}

string Vendedor::getRUT() {return RUT;}

void Vendedor::agregarProducto(Producto* p) {
    IKey* key = new Integer(p->getCodProd());
    Productos->add(key, p);
}

IDictionary* Vendedor::getProductos() {return Productos;}