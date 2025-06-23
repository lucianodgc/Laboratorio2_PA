#include "Fabrica.h"
#include "Controlador.h"

IControlador* Fabrica::controlador = nullptr;

IControlador* Fabrica::getControlador() {
    if (!controlador)
        controlador = new Controlador();
    return controlador;
}