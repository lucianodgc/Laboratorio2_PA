
#include "Compras.h"

Compras::Compras(float montoFinal) : MontoFinal(montoFinal) {ProdutoCompras = new List();}

Compras::~Compras() = default;

Date Compras::getFCompra(){return FCompra;}

float Compras::getMontoFinal() const {return MontoFinal;}