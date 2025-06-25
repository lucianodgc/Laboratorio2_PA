
#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "Interfaces.h"
#include "Usuario.h"

class Vendedor;

using namespace std;



class Producto: public ICollectible {
public:
    Producto(int CodProd, string Nombre, float Precio, int stock,
    string Descripcion, Cat Categoria, Vendedor* vendedor);
    virtual ~Producto();
    int getCodProd();
    string getNombre();
    float getPrecio();
    int getStock();
    string getDescripcion();
    Cat getCategoria();
    Vendedor* getVendedor();
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
