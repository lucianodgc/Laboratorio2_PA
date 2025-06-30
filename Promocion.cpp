
#include "Promocion.h"
#include "PromocionProducto.h"

Promocion::Promocion(string const &Nombre, string const &Descripcion, Date const &FVencimiento, int Descuento) :
Nombre(Nombre),Descripcion(Descripcion), Descuento(Descuento), FVencimiento(FVencimiento){promocionProducto = new List();}

Promocion::~Promocion() = default;

string Promocion::getNombre(){return Nombre;}

string Promocion::getDescripcion(){return Descripcion;}

Date Promocion::getFVencimiento(){return FVencimiento;}

int Promocion::getDescuento() const {return Descuento;}

ICollection* Promocion::getPromocionProducto() const {return promocionProducto;}

void Promocion::agregarProducto(Producto* Producto, int cantidadMinima) const {
   auto* pp = new PromocionProducto(Producto, cantidadMinima);
   promocionProducto->add(pp);
}

bool Promocion::productoYaAgregado(Producto* const &prod) const {
   IIterator* it;
   for (it = promocionProducto->getIterator(); it->hasCurrent(); it->next()) {
      ICollectible* col = it->getCurrent();
      auto* promProd = dynamic_cast<PromocionProducto*>(col);
      if (promProd != nullptr && promProd->getProducto() == prod) {
         delete it;
         return true;
      }
   }
   delete it;
   return false;
}
