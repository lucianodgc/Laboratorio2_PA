
#ifndef ICONTROLADORCOMENTARIO_H
#define ICONTROLADORCOMENTARIO_H

#include <iostream>

using namespace std;

class IControladorComentario {
public:
    virtual ~IControladorComentario() = default;
    virtual void RealizarComentario(string Texto) = 0;
    virtual void ResponderComentario(int ID, string Texto) = 0;
};

#endif
