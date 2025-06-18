
#ifndef CONTROLADORCOMENTARIO_H
#define CONTROLADORCOMENTARIO_H

#include "Interfaces.h"
#include "IControladorComentario.h"

using namespace std;



class ControladorComentario: public IControladorComentario {
public:
    ControladorComentario();
    virtual ~ControladorComentario();
private:
    IDictionary* Comentarios;
};



#endif
