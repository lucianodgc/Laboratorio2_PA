#include "Fabrica.h"
#include "ControladorUsuario.h"
#include "ControladorProducto.h"
#include "IControladorPromocion.h"
#include "IControladorCompras.h"
#include "IControladorComentario.h"

IControladorUsuario* Fabrica::controladorUsuario = nullptr;
IControladorProducto* Fabrica::controladorProducto = nullptr;
IControladorPromocion* Fabrica::controladorPromocion = nullptr;
IControladorCompras* Fabrica::controladorCompras = nullptr;
IControladorComentario* Fabrica::controladorComentarieo = nullptr;

IControladorUsuario* Fabrica::getControladorUsuario() {
    if (!controladorUsuario)
        controladorUsuario = new ControladorUsuario();
    return controladorUsuario;
}

/*IControladorProducto* Fabrica::getControladorProducto() {
    if (!controladorProducto)
        controladorProducto = new ControladorProducto();
    return controladorProducto;
}*/