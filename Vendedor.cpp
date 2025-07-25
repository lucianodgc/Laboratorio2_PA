
#include "Vendedor.h"
#include "Promocion.h"

Vendedor::Vendedor(string const &Nickname, string const &Contraseña,
Date const &Fnacimiento, string const &RUT)
: Usuario(Nickname, Contraseña, Fnacimiento), RUT(RUT) {
    Productos = new OrderedDictionary();
    Promociones = new OrderedDictionary();
}

Vendedor::~Vendedor() = default;

string Vendedor::getRUT() {return RUT;}

IDictionary* Vendedor::getProductos() const {return Productos;}

IDictionary* Vendedor::getPromociones() const {return Promociones;}

void Vendedor::agregarProducto(Producto* p) const {
    IKey* key = new Integer(p->getCodProd());
    Productos->add(key, p);
}

void Vendedor::agregarPromocion(Promocion* promo) const {
    IKey* key = new String(promo->getNombre().c_str());
    Promociones->add(key, promo);
}

Promocion* Vendedor::crearPromocion(string const &nombre, string const &descripcion,
Date const &fechaVencimiento, int descuento) const {
    auto* nueva = new Promocion(nombre, descripcion, fechaVencimiento, descuento);
    IKey* key = new String(nombre.c_str());
    Promociones->add(key, nueva);
    return nueva;
}
