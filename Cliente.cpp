
#include "Cliente.h"

Cliente::Cliente(string const &nickname, string const &contraseña, Date const &fNacimiento,
DataDirec const &direccion, string const &ciudad) : Usuario(nickname, contraseña, fNacimiento),
direccion(direccion), ciudad(ciudad), compras(new List()) {}

Cliente::~Cliente() = default;

DataDirec Cliente::getDireccion() {return direccion;}

string Cliente::getCiudad() {return ciudad;}

ICollection* Cliente::getCompras() const {return compras;}

Compras* Cliente::crearCompra() {
    auto* comp = new Compras(0, Date());
    return comp;
}

void Cliente::agregarCompra(Compras *comp) const {
    Date const hoy = Date::obtenerFechaActual();
    ICollection* col = comp->getProductoCompras();
    Producto* prod = nullptr;
    IIterator* it;
    float montoFinal = 0;
    for (it = col->getIterator(); it->hasCurrent(); it->next()) {
        auto* pp = dynamic_cast<ProductoCompras*>(it->getCurrent());
        prod = pp->getProducto();
        montoFinal += prod->getPrecio() * pp->getCantidad();
    }
    comp->finalizarCompra(hoy, montoFinal);
    compras->add(comp);
    delete it;
    cout << "Compra concretada correctamente" << endl;
}