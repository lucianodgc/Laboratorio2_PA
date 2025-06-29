
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

void Usuario::eliminarComentario(Comentario* comen, IDictionary*& productos) const {
    IDictionary* col = comen->getRespuestas();

    while (true) {
        if (col == nullptr) break;

        IIterator* it = col->getIterator();
        if (!it->hasCurrent()) {
            delete it;
            break;
        }

        Comentario* hijo = dynamic_cast<Comentario*>(it->getCurrent());
        delete it;

        eliminarComentario(hijo, productos);

        IKey* keyHijo = new Integer(hijo->getID());
        col->remove(keyHijo);
        delete keyHijo;
    }

    IKey* key = new Integer(comen->getID());
    Comentarios->remove(key);

    for (IIterator* it = productos->getIterator(); it->hasCurrent(); it->next()) {
        Producto* prod = dynamic_cast<Producto*>(it->getCurrent());
        if (prod == nullptr) continue;

        IDictionary* comentarios = prod->getComentarios();
        if (comentarios != nullptr && comentarios->member(key)) {
            Comentario* comentarioAEliminar = dynamic_cast<Comentario*>(comentarios->find(key));
            prod->eliminarComentario(comentarioAEliminar);
        }
    }

    delete key;
}