
#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Interfaces.h"
#include "Usuario.h"
#include "Producto.h"
#include <iostream>

class Promocion;
using namespace std;



class Vendedor:public Usuario {
public:
    Vendedor(string const &Nickname, string const &Contraseña, Date const &Fnacimiento, string const &RUT);
    ~Vendedor() override;
    string getRUT();
    void agregarProducto(Producto* p) const;
    IDictionary* getProductos() const;
    void agregarPromocion(Promocion* promo) const;
    Promocion* crearPromocion(string const &nombre, string const &descripcion, Date const &fechaVencimiento, int descuento) const;
    IDictionary* getPromociones() const;
private:
    string RUT;
    IDictionary *Productos;
    IDictionary *Promociones;
};



#endif
