
#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "Interfaces.h"
#include "Usuario.h"

class Vendedor;

using namespace std;



class Producto: public ICollectible {
public:
    Producto(int CodProd, string const &Nombre, float Precio, int stock,
    string const &Descripcion, Cat Categoria, Vendedor* vendedor);
    ~Producto() override;
    int getCodProd() const;
    string getNombre() const;
    float getPrecio() const;
    int getStock() const;
    string getDescripcion() const;
    Cat getCategoria() const;
    Vendedor* getVendedor() const;
private:
	int CodProd;
    int Stock;
    float Precio;
    string Nombre;
    string Descripcion;
    Cat Categoria;
    IDictionary* Comentarios;
    Vendedor* vendedor;
};



#endif
