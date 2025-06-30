
#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "Interfaces.h"
#include "Estructuras.h"
#include <string>

class ProductoCompras;
class Comentario;
class Usuario;
class Vendedor;

using namespace std;



class Producto: public ICollectible {
public:
    Producto(string const &Nombre, float Precio, int stock,
    string const &Descripcion, Cat Categoria, Vendedor* vendedor);
    ~Producto() override;
    int getCodProd() const;
    string getNombre() const;
    float getPrecio() const;
    int getStock() const;
    string getDescripcion() const;
    Cat getCategoria() const;
    Vendedor* getVendedor() const;
    IDictionary* getComentarios() const;
    ProductoCompras* getProdComp() const;
    void agregarComentario(Comentario* comen) const;
    void eliminarComentario(Comentario* comen) const;
    void agregarProdCompra(ProductoCompras* prodComp);
private:
    static int ultimoCodProd;
	int CodProd;
    int Stock;
    float Precio;
    string Nombre;
    string Descripcion;
    Cat Categoria;
    ProductoCompras* prodComp;
    IDictionary* Comentarios;
    Vendedor* vendedor;
};



#endif
