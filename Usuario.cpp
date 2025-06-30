
#include "Usuario.h"

Usuario::Usuario(string const &Nickname, string const &Contraseña, Date const &Fnacimiento) : Nickname(Nickname), Contraseña(Contraseña),
Fnacimiento(Fnacimiento) {Comentarios = new OrderedDictionary();}

Usuario::~Usuario() = default;

string Usuario::getNickname() {return Nickname;}

Date Usuario::getNacimiento() {return Fnacimiento;}

IDictionary* Usuario::getComentarios() const {return Comentarios;}

void Usuario::eliminarComentario(Comentario* const &comen, IDictionary* &productos) {
    IIterator* it = nullptr;
    IDictionary* col = comen->getRespuestas();
    if (col != nullptr) {
        for (it = col->getIterator();it->hasCurrent();it->next()) {
            auto* comen1 = dynamic_cast<Comentario*>(it->getCurrent());
            eliminarComentario(comen1, productos);

        }
    }
    delete it;
    IKey* key = new Integer(comen->getID());
    Comentarios->remove(key);
    for (it = productos->getIterator();it->hasCurrent();it->next()) {
        auto* prod = dynamic_cast<Producto*>(it->getCurrent());
        col = prod->getComentarios();
        if (col->member(key)) {
            auto* comentario = dynamic_cast<Comentario*>(col->find(key));
            prod->eliminarComentario(comentario);
        }
    }
    delete comen;
    delete it;
    delete key;
}

Comentario* Usuario::nuevoComentario(string const &texto) const {
    Date const hoy = Date::obtenerFechaActual();
    auto* comen = new Comentario(texto, hoy);
    IKey* key = new Integer(comen->getID());
    Comentarios->add(key , comen);
    return comen;
}




