
#ifndef USUARIO_H
#define USUARIO_H

#include "Estructuras.h"
#include "Interfaces.h"

using namespace std;



class Usuario: public ICollectible {
public:
    virtual ~Usuario();
    Usuario(string Nickname, string Contraseña, Date Fnacimiento);
    string getNickname();
    Date getNacimiento();
protected:
    string Nickname;
    string Contraseña;
    Date Fnacimiento;
    IDictionary* Comentario;
};



#endif
