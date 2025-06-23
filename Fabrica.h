
#ifndef FABRICA_H
#define FABRICA_H

using namespace std;

#include "IControlador.h"

class Fabrica {
private:
    static IControlador* controlador;

public:
    static IControlador* getControlador();
};
#endif
