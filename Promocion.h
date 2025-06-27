
#ifndef PROMOCION_H
#define PROMOCION_H

#include "Estructuras.h"
#include "Interfaces.h"
#include "Producto.h"

using namespace std;



class Promocion: public ICollectible {
public:
    Promocion(string Nombre, string Descripcion, Date FVencimiento, int Descuento);
    virtual ~Promocion();
    void agregarProducto(Producto* Producto, int cantidadMinima);
    string getNombre();
    string getDescripcion();
    Date getFVencimiento();
    int getDescuento();
    ICollection* getPromocionProducto();
    bool productoYaAgregado(Producto* p);
private:
	string Nombre;
    string Descripcion;
    int Descuento;
    Date FVencimiento;
    ICollection* promocionProducto;

};



#endif
