
#ifndef PROMOCION_H
#define PROMOCION_H

#include "Estructuras.h"
#include "Interfaces.h"

using namespace std;



class Promocion: public ICollectible {
public:
    Promocion();
    virtual ~Promocion();
    void agregarProducto(string CodProd, int Cantidad);
private:
	string Nombre;
    string Descripcion;
    Date FVencimiento;
    ICollection* PromocionProducto;

};



#endif
