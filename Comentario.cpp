
#include "Comentario.h"

Comentario::Comentario(int id) : ID(id){Respuestas = new List();}

Comentario::~Comentario() = default;

int Comentario::getID() const {return ID;}

string Comentario::getTexto(){return Texto;}

Date Comentario::getFComentario(){return FComentario;}