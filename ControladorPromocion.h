
#ifndef CONTROLADORPROMOCION_H
#define CONTROLADORPROMOCION_H

#include "Interfaces.h"
#include "IControladorPromocion.h"

using namespace std;



class ControladorPromocion:public IControladorPromocion {
public:
    ControladorPromocion();
    virtual ~ControladorPromocion();
    void CrearPromocion(string Nombre, string Descripcion, Date FVencimiento, string NicknameVendedor);
    void AgregarProducto(string CodProd, int CantidadMinima);
    void ListarPromosVigentes();
    DTpromocion VerInfoPromo();
private:
    IDictionary* Promociones;
};



#endif
