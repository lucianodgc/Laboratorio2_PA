
#include "Producto.h"
#include "Usuario.h"

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

IDictionary* Producto::getComentarios() const {return Comentarios;}

void Producto::agregarComentario(int id, string texto, Date fComentario, Producto* producto, Usuario* usuario) const {
    auto* comen = new Comentario(id, texto, fComentario, producto, usuario);
    IKey* key = new Integer(id);
    Comentarios->add(key , comen);
    delete key;
}

int Producto::generarCodigoComentario() const {
    int maxID = 0;
    for (IIterator* it = Comentarios->getIterator(); it->hasCurrent(); it->next()) {
        auto* comen = dynamic_cast<Comentario *>(it->getCurrent());
        if (comen != nullptr && comen->getID() > maxID) {
            maxID = comen->getID();
        }
    }
    return maxID + 1;
}

void Producto::eliminarComentario(int id) const {
    IKey* key = new Integer(id);
    if (!Comentarios->member(key)) {
        return;
    }
    Comentarios->remove(key);
    delete key;
}
