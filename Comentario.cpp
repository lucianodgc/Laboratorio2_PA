
#include "Comentario.h"

Comentario::Comentario(int id, string texto, Date fComentario, Producto* producto, Usuario* usuario)
: ID(id), Texto(texto), FComentario(fComentario), producto(producto), usuario(usuario){Respuestas = new OrderedDictionary;}

Comentario::~Comentario() = default;

int Comentario::getID() const {return ID;}

string Comentario::getTexto(){return Texto;}

Date Comentario::getFComentario(){return FComentario;}

Producto* Comentario::getProducto() const {return producto;}

Usuario* Comentario::getUsuario() const {return usuario;}

IDictionary* Comentario::getRespuestas() const {return Respuestas;}

void Comentario::agregarRespuesta(int id, string texto, Date fComentario, Producto* prod, Usuario* usuario) const {
    auto* comen = new Comentario(id, texto, fComentario, prod, usuario);
    IKey* ik = new Integer(id);
    Respuestas->add(ik , comen);
}

void Comentario::eliminarRespuesta(int id) const {
    IKey* key;
    for (IIterator* it = Respuestas->getIterator(); it->hasCurrent(); it->next()) {
        key = new Integer(id);
        auto* resp = dynamic_cast<Comentario*>(Respuestas->find(key));
        int id2 = resp->getID();
        resp->eliminarRespuesta(id2);
        Producto* prod = resp->getProducto();
        prod->eliminarComentario(id2);
        Usuario* us = resp->getUsuario();
        us->eliminarComentario(id2);
    }
}
