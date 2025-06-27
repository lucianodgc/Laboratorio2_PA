
#ifndef COMENTARIO_H
#define COMENTARIO_H

#include "Estructuras.h"
#include "Interfaces.h"

using namespace std;



class Comentario: public ICollectible {
public:
    Comentario(int id);
    ~Comentario() override;
    int getID() const;
    string getTexto();
    Date getFComentario();
private:
	int ID;
    string Texto;
    Date FComentario;
    ICollection* Respuestas;
};



#endif
