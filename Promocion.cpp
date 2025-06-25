
#include "Promocion.h"

Promocion::Promocion(string Nombre, string Descripcion, Date FVencimiento, int Descuento) :
Nombre(Nombre),Descripcion(Descripcion), FVencimiento(FVencimiento), Descuento(Descuento){}

Promocion::~Promocion() {}

void Promocion::agregarProducto(Producto* Producto, int cantidadMinima) {
   PromocionProducto* pp = new PromocionProducto(Producto, cantidadMinima);
   promocionProducto->add(pp);
}

string Promocion::getNombre(){return Nombre;}

string Promocion::getDescripcion(){return Descripcion;}

Date Promocion::getFVencimiento(){return FVencimiento;}

int Promocion::getDescuento(){return Descuento;}

ICollection* Promocion::getPromocionProducto(){return promocionProducto;}