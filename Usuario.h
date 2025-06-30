
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
    IDictionary* getComentarios() const;
    void eliminarComentario(Comentario* const &comen, IDictionary* &productos);
    Comentario* nuevoComentario(string const &texto) const;


protected:
    string Nickname;
    string Contraseña;
    Date Fnacimiento;
    IDictionary* Comentarios;
};



#endif
