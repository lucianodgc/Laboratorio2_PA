
#ifndef ICONTROLADORPROMOCION_H
#define ICONTROLADORPROMOCION_H

#include "DTpromocion.h"

using namespace std;



class IControladorPromocion {
public:
    virtual ~IControladorPromocion() = default;
    virtual void CrearPromocion(string Nombre, string Descripcion, Date FVencimiento, string NicknameVendedor) = 0;
    virtual void AgregarProducto(string CodProd, int CantidadMinima) = 0;
    virtual void ListarPromosVigentes() = 0;
    virtual DTpromocion VerInfoPromo() = 0;

};

#endif
