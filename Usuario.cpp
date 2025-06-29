
#include "Usuario.h"

Usuario::Usuario(string const &Nickname, string const &Contraseña, Date const &Fnacimiento) : Nickname(Nickname), Contraseña(Contraseña),
Fnacimiento(Fnacimiento) {Comentarios = new OrderedDictionary();}

Usuario::~Usuario() = default;

string Usuario::getNickname() {return Nickname;}

Date Usuario::getNacimiento() {return Fnacimiento;}

Comentario* Usuario::nuevoComentario(string texto) const {
    Date const hoy = Date::obtenerFechaActual();
    auto* comen = new Comentario(texto, hoy);
    IKey* ik = new Integer(comen->getID());
    Comentarios->add(ik , comen);
    return comen;
}

IDictionary* Usuario::getComentarios() const {return Comentarios;}

void Usuario::eliminarComentario(Comentario* comen, IDictionary* &productos) const {

    IDictionary* col = comen->getRespuestas();
    if (col != nullptr) {
        for (IIterator* it = col->getIterator();it->hasCurrent();it->next()) {
            auto* comen1 = dynamic_cast<Comentario*>(it->getCurrent());
            eliminarComentario(comen1, productos);
        }
    }
    IKey* key = new Integer(comen->getID());

    Comentarios->remove(key);
    for (IIterator* it = productos->getIterator();it->hasCurrent();it->next()) {
        auto* prod = dynamic_cast<Producto*>(it->getCurrent());
        IDictionary *col = prod->getComentarios();
        bool esta = col->member(key);
        if (esta) {
            auto* comen = dynamic_cast<Comentario*>(col->find(key));
            prod->eliminarComentario(comen);
        }
    }
    delete key;
}
