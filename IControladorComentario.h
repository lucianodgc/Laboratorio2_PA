
#ifndef ICONTROLADORCOMENTARIO_H
#define ICONTROLADORCOMENTARIO_H

using namespace std;

class IControladorComentario {
public:
    virtual ~IControladorComentario() = default;
    virtual void RealizarComentario(string Texto);
    virtual void ResponderComentario(int ID, string Texto);
};

#endif
