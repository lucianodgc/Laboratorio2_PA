
#ifndef CONTROLADORCOMENTARIO_H
#define CONTROLADORCOMENTARIO_H

#include "Interfaces.h"
#include "IControladorComentario.h"

using namespace std;



class ControladorComentario: public IControladorComentario {
public:
    ControladorComentario();
    virtual ~ControladorComentario();
    void RealizarComentario(string Texto);
    void ResponderComentario(int ID, string Texto);
private:
    IDictionary* Comentarios;
};



#endif
