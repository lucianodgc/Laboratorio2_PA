
#ifndef COMENTARIO_H
#define COMENTARIO_H

#include "Estructuras.h"
#include "Interfaces.h"
#include "Producto.h"
#include "Usuario.h"

using namespace std;



class Comentario: public ICollectible {
public:
    Comentario(int id, string texto, Date fComentario, Producto* prod, Usuario* usuario);
    ~Comentario() override;
    int getID() const;
    string getTexto();
    Date getFComentario();
    Producto* getProducto() const;
    Usuario* getUsuario() const;
   IDictionary* getRespuestas() const;
    void agregarRespuesta(int id, string texto, Date fComentario, Producto* prod, Usuario* usuario) const;
    void eliminarRespuesta(int id) const;
private:
	int ID;
    string Texto;
    Date FComentario;
    IDictionary* Respuestas;
    Producto* producto;
    Usuario* usuario;
};



#endif
