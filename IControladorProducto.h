
#ifndef ICONTROLADORPRODUCTO_H
#define ICONTROLADORPRODUCTO_H

#include "DTProducto.h"
#include "DTprod.h"
#include "Estructuras.h"
#include <set>

using namespace std;



class IControladorProducto {
public:
    virtual ~IControladorProducto() = default;
    virtual void AltaProducto(string Nombre, float Precio, int Stock,
    string Descripcion, Cat Categoria) = 0;
    virtual void AgregarProducto(string CodProd, int Cantidad) = 0;
    virtual DTprod MostrarDatosProducto(string CodProd) = 0;
    virtual set<DTproducto> ListarProductos() = 0;
};

#endif
