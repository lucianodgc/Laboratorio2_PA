
#ifndef ICONTROLADOR_H
#define ICONTROLADOR_H

#include <iostream>
#include "Estructuras.h"

using namespace std;

class IControlador {
public:
    virtual ~IControlador() = default;
    virtual void realizarComentario(string texto) = 0;
    virtual void responderComentario(int id, string texto) = 0;
    virtual void altaProducto(string nombre, float precio, int stock,
    string descripcion, Cat categoria, string nicknameVendedor) = 0;
    virtual void listarProductos() = 0;
    virtual void listarProductos(string nicknameVendedor) = 0;
    virtual void mostrarDatosProducto(int CodProd) = 0;
    virtual void crearPromocion(string nombre, string descripcion,
    Date fVencimiento, int descuento) = 0;
    virtual void seleccionarProducto(int codProd, int cantidad) = 0;
    virtual void seleccionarProducto(int codProd) = 0;
    virtual void seleccionarUsuario(string nombre) = 0;
    virtual void listarPromosVigentes() = 0;
    virtual void verInfoPromo(string nombre) = 0;
    virtual void altaCliente(string nombre, string contraseña,
    Date fNacimiento, DataDirec direccion, string ciudad) = 0;
    virtual void altaVendedor(string nombre, string contraseña,
    Date fNacimiento, string RUT) = 0;
    virtual void listarUsuarios() = 0;
    virtual void listarNickVendedores() = 0;
    virtual void listarNickUsuarios() = 0;
    virtual void listarComentarios() = 0;
    virtual void listarComentarios(string nick) = 0;
    virtual void eliminarComentarios(int id) = 0;
    virtual void listarNickClientes() = 0;
    virtual void agregarProducto(int codProd, int cantidad) = 0;
    virtual void confirmarYMostrarCompra() = 0;
    virtual void crearCompra(string nick) = 0;
    virtual void mostrarDatosUsuario(string nick) = 0;
    virtual void listarProductosPendiente(string nicknameVendedor) = 0;
    virtual void listarCompras(int codProd) = 0;
    virtual void marcarProducto(string nickCliente, Date fechaCompra) = 0;
};
#endif