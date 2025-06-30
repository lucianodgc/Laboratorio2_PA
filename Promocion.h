
#ifndef PROMOCION_H
#define PROMOCION_H

#include "Estructuras.h"
#include "Interfaces.h"
#include "Producto.h"

using namespace std;



class Promocion: public ICollectible {
public:
    Promocion(string const &Nombre, string const &Descripcion, Date const &FVencimiento, int Descuento);
    ~Promocion() override;
    string getNombre();
    string getDescripcion();
    Date getFVencimiento();
    int getDescuento() const;
    ICollection* getPromocionProducto() const;
    void agregarProducto(Producto* Producto, int cantidadMinima) const;
    bool productoYaAgregado(Producto* const &prod) const;

private:
	string Nombre;
    string Descripcion;
    int Descuento;
    Date FVencimiento;
    ICollection* promocionProducto;

};



#endif
