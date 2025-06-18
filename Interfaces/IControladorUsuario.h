
#ifndef ICONTROLADOR_H
#define ICONTROLADOR_H

#include "Usuario.h"
#include "DTProducto.h"
#include "DTProd.h"
#include <set>

using namespace std;



class IControladorUsuario {
public:
    virtual ~IControladorUsuario() = default;
    virtual void altaCliente(string nick, string pass, Date nac, string dir, string ciudad) = 0;
    virtual void altaVendedor(string nick, string pass, Date nac, string rut) = 0;
    virtual void listarUsuarios() = 0;
    virtual void SeleccionarProducto(string CodProd, int Cantidad) = 0;
    virtual DTprod MostrarDatosProducto(string CodProd) = 0;
    virtual void NuevoCliente(string Nombre, string Contraseña,
    Date FNacimiento, DataDirec Direccion, string Ciudad) = 0;
    virtual void NuevoVendedor(string Nombre, string Contraseña,
    Date FNacimiento, string RUT) = 0;
    virtual set<DTProducto> ListarProductos() = 0;

};



#endif
