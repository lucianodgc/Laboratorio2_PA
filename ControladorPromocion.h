
#ifndef CONTROLADORPROMOCION_H
#define CONTROLADORPROMOCION_H

#include "Interfaces.h"
#include "IControladorPromocion.h"

using namespace std;



class ControladorPromocion:public IControladorPromocion {
public:
    ControladorPromocion();
    virtual ~ControladorPromocion();
    void CrearPromocion(string Nombre, string Descripcion, Date FVencimiento, string NicknameVendedor) = 0;
    void AgregarProducto(string CodProd, int CantidadMinima) = 0;
    void ListarPromosVigentes() = 0;
    DTpromocion VerInfoPromo() = 0;
private:
    IDictionary* Promociones;
};



#endif
