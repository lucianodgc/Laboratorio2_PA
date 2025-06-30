
#ifndef COMENTARIO_H
#define COMENTARIO_H

#include "Estructuras.h"
#include "Interfaces.h"
#include "Producto.h"
#include "Usuario.h"

using namespace std;



class Comentario: public ICollectible {
public:
    Comentario(string texto, Date fComentario);
    ~Comentario() override;
    int getID() const;
    string getTexto();
    Date getFComentario();
    Producto* getProducto() const;
    Usuario* getUsuario() const;
   IDictionary* getRespuestas() const;
    void agregarRespuesta(Comentario* comen) const;

private:
    static int ultimoID;
	int ID;
    string Texto;
    Date FComentario;
    IDictionary* Respuestas;
};



#endif
