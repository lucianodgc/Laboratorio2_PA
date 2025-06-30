
#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Interfaces.h"
#include "IControlador.h"
#include "Producto.h"
#include "Promocion.h"
#include "Cliente.h"
#include "Vendedor.h"

using namespace std;



class Controlador:public IControlador {
public:
    Controlador();
    ~Controlador() override;
    void agregarProducto(int codProd, int cantidad) override;
    void altaCliente(string nombre, string contraseña,Date fNacimiento,
    DataDirec direccion, string ciudad) override;
    void altaVendedor(string nombre, string contraseña,
    Date fNacimiento, string rut) override;
    void altaProducto(string nombre, float precio, int stock,
    string descripcion, Cat categoria, string nicknameVendedor) override;
    void confirmarYMostrarCompra() override;
    void crearCompra(string nick) override;
    void crearPromocion(string nombre, string descripcion, Date fVencimiento, int descuento) override;
    void eliminarComentarios(int id) override;
    void listarComentarios() override;
    void listarComentarios(string nick) override;
    void listarCompras(int codProd) override;
    void listarNickUsuarios() override;
    void listarNickClientes() override;
    void listarNickVendedores() override;
    void listarProductos() override;
    void listarProductos(string nicknameVendedor) override;
    void listarProductosPendiente(string nicknameVendedor) override;
    void listarPromosVigentes() override;
    void listarUsuarios() override;
    void marcarProducto(string nicknameCliente, Date fechaCompra) override;
    void mostrarDatosProducto(int codProd) override;
    void mostrarDatosUsuario(string nick) override;
    bool productoEnPromocionVigente(Producto* &producto) const ;
    bool productoYaAgregado(Producto* p);
    void realizarComentario(string texto) override;
    void responderComentario(int id, string texto) override;
    void seleccionarProducto(int codProd, int cantidad) override;
    void seleccionarProducto(int codProd) override;
    void seleccionarUsuario(string nombre) override;
    void verInfoPromo(string nombre) override;

private:
    IDictionary* usuarios;
    IDictionary* promociones;
    IDictionary* productos;
    IDictionary* compras;
    Vendedor* vendedorActual = nullptr;
    Cliente* clienteActual = nullptr;
    Promocion* promocionActual = nullptr;
    Producto* productoActual = nullptr;
    Usuario* usuarioActual = nullptr;
    Compras* compraActual = nullptr;
};



#endif