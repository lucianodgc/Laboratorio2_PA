
#ifndef ICONTROLADOR_H
#define ICONTROLADOR_H

#include <iostream>
#include "Cliente.h"
#include "Vendedor.h"
#include "Producto.h"
#include "Promocion.h"
#include "Compras.h"
#include "Comentario.h"
#include "Estructuras.h"
#include <set>

using namespace std;

class IControlador {
public:
    virtual ~IControlador() = default;
    virtual void RealizarComentario(string Texto) = 0;
    virtual void ResponderComentario(int ID, string Texto) = 0;
    virtual void agregarProducto(string &CodProd, int Cantidad) = 0;
    virtual void AltaProducto(string Nombre, float Precio, int Stock,
    string Descripcion, Cat Categoria, string NicknameVendedor) = 0;
    virtual void AgregarProducto(string CodProd, int Cantidad) = 0;
    virtual void ListarProductos() = 0;
    virtual void ListarProductos(string NicknameVendedor) = 0;
    virtual void mostrarDatosProducto(int CodProd) = 0;
    virtual void agregarProducto(Vendedor* Vend, Producto* Prod) = 0;
    virtual void CrearPromocion(string Nombre, string Descripcion,
    Date FVencimiento, string NicknameVendedor, int Descuento) = 0;
    virtual void ListarPromosVigentes() = 0;
    virtual void VerInfoPromo() = 0;
    virtual void altaCliente(string Nombre, string Contraseña,
    Date FNacimiento, DataDirec Direccion, string Ciudad) = 0;
    virtual void altaVendedor(string Nombre, string Contraseña,
    Date FNacimiento, string RUT) = 0;
    virtual void listarUsuarios() = 0;
    virtual void listarVendedores() = 0;
    virtual int generarCodigoProducto() = 0;
    virtual bool productoEnPromocionVigente(Producto* producto) = 0;
};
#endif