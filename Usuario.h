
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
    void agregarComentario(int id, string texto, Date fComentario, Producto* producto, Usuario* usuario) const;
    int generarCodigoComentario() const;
    IDictionary* getComentarios() const;
    void eliminarComentario(int id) const;
protected:
    string Nickname;
    string Contraseña;
    Date Fnacimiento;
    IDictionary* Comentarios;
};



#endif
