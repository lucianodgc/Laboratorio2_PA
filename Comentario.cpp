
#include "Comentario.h"

int Comentario::ultimoID = 0;

Comentario::Comentario(string texto, Date fComentario)
    : ID(++ultimoID), Texto(texto), FComentario(fComentario) { Respuestas = new OrderedDictionary; }

Comentario::~Comentario() = default;

int Comentario::getID() const {return ID;}

string Comentario::getTexto(){return Texto;}

Date Comentario::getFComentario(){return FComentario;}

IDictionary* Comentario::getRespuestas() const {return Respuestas;}

void Comentario::agregarRespuesta(Comentario* comen) const {
    string texto = comen->getTexto();
    Date fComentario = comen->getFComentario();
    auto* comentario = new Comentario(texto, fComentario);
    IKey* ik = new Integer(comen->getID());
    Respuestas->add(ik , comentario);
}

void Comentario::eliminarRespuesta(int id) const {
    IKey* key;
    for (IIterator* it = Respuestas->getIterator(); it->hasCurrent(); it->next()) {
        key = new Integer(id);
        auto* resp = dynamic_cast<Comentario*>(Respuestas->find(key));
        int id2 = resp->getID();
        resp->eliminarRespuesta(id2);

    }
}
