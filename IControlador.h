
#ifndef ICONTROLADOR_H
#define ICONTROLADOR_H

#include <iostream>
#include "Estructuras.h"

using namespace std;

class IControlador {
public:
    virtual ~IControlador() = default;
    virtual void realizarComentario(string Texto) = 0;
    virtual void responderComentario(int ID, string Texto) = 0;
    virtual void altaProducto(string Nombre, float Precio, int Stock,
    string Descripcion, Cat Categoria, string NicknameVendedor) = 0;
    virtual void listarProductos() = 0;
    virtual void listarProductos(string NicknameVendedor) = 0;
    virtual void mostrarDatosProducto(int CodProd) = 0;
    virtual void crearPromocion(string Nombre, string Descripcion,
    Date FVencimiento, int Descuento) = 0;
    virtual void seleccionarProducto(int codProd, int cantidad) = 0;
    virtual void seleccionarProducto(int codProd) = 0;
    virtual void seleccionarUsuario(string nombre) = 0;
    virtual void listarPromosVigentes() = 0;
    virtual void verInfoPromo(string nombre) = 0;
    virtual void altaCliente(string Nombre, string Contraseña,
    Date FNacimiento, DataDirec Direccion, string Ciudad) = 0;
    virtual void altaVendedor(string Nombre, string Contraseña,
    Date FNacimiento, string RUT) = 0;
    virtual void listarUsuarios() = 0;
    virtual void listarVendedores() = 0;
    virtual void listarNickUsuarios() = 0;
    virtual void listarComentarios() = 0;
    virtual int generarCodigoProducto() = 0;
    virtual void listarComentarios(string nick) = 0;
    virtual void eliminarComentarios(int id) = 0;
    virtual void listarNickClientes() = 0;
    virtual void agregarProducto(int codProd, int cantidad) = 0;
    virtual void confirmarYMostrarCompra() = 0;
    virtual void seleccionarCliente(string nick) = 0;
};
#endif