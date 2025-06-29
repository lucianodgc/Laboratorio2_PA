
#include "Usuario.h"

Usuario::Usuario(string const &Nickname, string const &Contraseña, Date const &Fnacimiento) : Nickname(Nickname), Contraseña(Contraseña),
Fnacimiento(Fnacimiento) {Comentarios = new OrderedDictionary();}

Usuario::~Usuario() = default;

string Usuario::getNickname() {return Nickname;}

Date Usuario::getNacimiento() {return Fnacimiento;}

void Usuario::agregarComentario(int id, string texto, Date fComentario, Producto* producto, Usuario* usuario) const {
    auto* comen = new Comentario(id, texto, fComentario, producto, usuario);
    int codID = generarCodigoComentario();
    IKey* ik = new Integer(codID);
    Comentarios->add(ik , comen);
}

int Usuario::generarCodigoComentario() const {
    int maxID = 0;
    for (IIterator* it = Comentarios->getIterator(); it->hasCurrent(); it->next()) {
        auto* comen = dynamic_cast<Comentario *>(it->getCurrent());
        if (comen != nullptr && comen->getID() > maxID) {
            maxID = comen->getID();
        }
    }
    return maxID + 1;
}

IDictionary* Usuario::getComentarios() const {return Comentarios;}

void Usuario::eliminarComentario(int id) const {
    IKey* key = new Integer(id);
    if (!Comentarios->member(key)) {
        return;
    }
    auto* comen = dynamic_cast<Comentario*>(Comentarios->find(key));
    Producto* prod = comen->getProducto();
    prod->eliminarComentario(id);
    comen->eliminarRespuesta(id);
}
