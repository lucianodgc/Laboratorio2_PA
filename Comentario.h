
#ifndef COMENTARIO_H
#define COMENTARIO_H

#include "Estructuras.h"
#include "Interfaces.h"

using namespace std;



class Comentario: public ICollectible {
public:
    Comentario();
    virtual ~Comentario();
    int getID();
    string getTexto();
    Date getFComentario();
private:
	int ID;
    string Texto;
    Date FComentario;
    ICollection* Respuestas;
};



#endif
