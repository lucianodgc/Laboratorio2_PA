#include <iostream>
#include "Fabrica.h"
#include "Estructuras.h"

int main() {


    IControladorUsuario* ctrlUsuario = Fabrica::getControladorUsuario();

    Date fecha(10, 6, 2000);
    ctrlUsuario->altaCliente("luciano", "clave123", fecha, {"Calle Falsa", 1234}, "Maldonado");

    IControladorProducto* ctrlProducto = Fabrica::getControladorProducto();

}