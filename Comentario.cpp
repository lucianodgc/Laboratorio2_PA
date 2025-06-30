
#include "Comentario.h"

int Comentario::ultimoID = 0;

Comentario::Comentario(string const &texto, Date const &fComentario)
    : ID(++ultimoID), texto(texto), fComentario(fComentario) { respuestas = new OrderedDictionary; }

Comentario::~Comentario() = default;

int Comentario::getID() const {return ID;}

string Comentario::getTexto(){return texto;}

Date Comentario::getFComentario(){return fComentario;}

IDictionary* Comentario::getRespuestas() const {return respuestas;}

void Comentario::agregarRespuesta(Comentario* &comen) const {
    IKey* key = new Integer(comen->getID());
    respuestas->add(key , comen);
}
