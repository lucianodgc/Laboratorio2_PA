
#ifndef CONTROLADORPRODUCTO_H
#define CONTROLADORPRODUCTO_H

#include "Interfaces.h"
#include "IControladorProducto.h"

using namespace std;



class ControladorProducto:public IControladorProducto {
public:
    ControladorProducto();
    virtual ~ControladorProducto();
    void AltaProducto(string Nombre, float Precio, int Stock,
    string Descripcion, Cat Categoria);
    void AgregarProducto(string CodProd, int Cantidad);
    DTprod MostrarDatosProducto(string CodProd);
    set<DTproducto> ListarProductos();
private:
    IDictionary* Productos;
};



#endif
