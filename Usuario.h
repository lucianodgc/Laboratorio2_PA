
#ifndef USUARIO_H
#define USUARIO_H

#include "Estructuras.h"
#include "Interfaces.h"
#include "Comentario.h"

using namespace std;



class Usuario: public ICollectible {
public:
    ~Usuario() override;
    Usuario(string const &Nickname, string const &Contraseña, Date const &Fnacimiento);
    string getNickname();
    Date getNacimiento();
    Comentario* nuevoComentario(string texto) const;
    IDictionary* getComentarios() const;
    void eliminarComentario(Comentario* comen, IDictionary* &productos) const;
protected:
    string Nickname;
    string Contraseña;
    Date Fnacimiento;
    IDictionary* Comentarios;
};



#endif
