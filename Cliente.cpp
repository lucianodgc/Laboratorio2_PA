
#include "Cliente.h"

Cliente::Cliente(string const &Nickname, string const &Contraseña, Date const &Fnacimiento,
DataDirec const &Direccion, string const &Ciudad) : Usuario(Nickname, Contraseña, Fnacimiento),
Direccion(Direccion), Ciudad(Ciudad), compras(new List()) {}

Cliente::~Cliente() = default;

DataDirec Cliente::getDireccion() {return Direccion;}

string Cliente::getCiudad() {return Ciudad;}

Compras* Cliente::crearCompra() const {
    auto* comp = new Compras(0, Date());
    return comp;
}

void Cliente::agregarCompra(Compras *comp) const {
    Date const hoy = Date::obtenerFechaActual();
    ICollection* col = comp->getProductoCompras();
    Producto* prod = nullptr;
    float montoFinal = 0;
    for (IIterator* it = col->getIterator(); it->hasCurrent(); it->next()) {
        auto* pp = dynamic_cast<ProductoCompras*>(it->getCurrent());
        prod = pp->getProducto();
        montoFinal += prod->getPrecio() * pp->getCantidad();
    }
    comp->finalizarCompra(hoy, montoFinal);
    compras->add(comp);
    cout << "Compra concretada correctamente" << endl;
}