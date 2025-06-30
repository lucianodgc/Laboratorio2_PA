
#include "Comentario.h"

int Comentario::ultimoID = 0;

Comentario::Comentario(string const &texto, Date const &fComentario)
    : ID(++ultimoID), Texto(texto), FComentario(fComentario) { Respuestas = new OrderedDictionary; }

Comentario::~Comentario() = default;

int Comentario::getID() const {return ID;}

string Comentario::getTexto(){return Texto;}

Date Comentario::getFComentario(){return FComentario;}

IDictionary* Comentario::getRespuestas() const {return Respuestas;}

void Comentario::agregarRespuesta(Comentario* &comen) const {
    IKey* key = new Integer(comen->getID());
    Respuestas->add(key , comen);
    delete key;
}
