
#ifndef FABRICA_H
#define FABRICA_H

using namespace std;
#include "IControladorUsuario.h"
#include "IControladorProducto.h"
#include "IControladorPromocion.h"
#include "IControladorCompras.h"
#include "IControladorComentario.h"

class Fabrica {
private:
    static IControladorUsuario* controladorUsuario;
    static IControladorProducto* controladorProducto;
    static IControladorPromocion* controladorPromocion;
    static IControladorCompras* controladorCompras;
    static IControladorComentario* controladorComentarieo ;

public:
    static IControladorUsuario* getControladorUsuario();
    static IControladorProducto* getControladorProducto();
    static IControladorPromocion* getControladorPromocion();
    static IControladorCompras* getControladorCompras();
    static IControladorComentario* getControladorComentario();

};
#endif
