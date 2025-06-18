
#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "Estructuras.h"
#include "Interfaces.h"
#include "DTprod.h"

using namespace std;



class Producto: public ICollectible {
public:
    Producto();
    virtual ~Producto();
    void NuevoProducto(string Nombre, float Precio, int Stock,
    string Descripcion, Cat Categoria);
    void AgregarProducto(string CodProd, int Cantidad);
    DTprod MostrarDatosProducto(string CodProd);
    string getCodProd();
    string getNombre();
    float getPrecio();
    int getStock();
    string getDescripcion();
    Cat getCategoria();
private:
	string CodProd;
    int Stock;
    float Precio;
    string Nombre;
    string Descripcion;
    Cat Categoria;
    IDictionary* Comentarios;
};



#endif
