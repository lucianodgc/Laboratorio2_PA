
#ifndef COMENTARIO_H
#define COMENTARIO_H

#include "Estructuras.h"
#include "Interfaces.h"

using namespace std;



class Comentario: public ICollectible {
public:
    Comentario();
    virtual ~Comentario();
    void RealizarComentario(string Texto);
    void ResponderComentario(int ID, string Texto);
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
