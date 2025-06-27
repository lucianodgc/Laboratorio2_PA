
#include "Promocion.h"

Promocion::Promocion(string Nombre, string Descripcion, Date FVencimiento, int Descuento) :
Nombre(Nombre),Descripcion(Descripcion), FVencimiento(FVencimiento), Descuento(Descuento){promocionProducto = new List();}

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

bool Promocion::productoYaAgregado(Producto* p) {
   for (IIterator* it = promocionProducto->getIterator(); it->hasCurrent(); it->next()) {
      ICollectible* collectible = it->getCurrent();
      PromocionProducto* pp = dynamic_cast<PromocionProducto*>(collectible);
      if (pp->getProducto() == p) {
         delete it;
         return true;
      }
   }
   return false;
}