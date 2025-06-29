
#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Interfaces.h"
#include "IControlador.h"
#include "Producto.h"
#include "Promocion.h"
#include "Cliente.h"
#include "PromocionProducto.h"
#include "Vendedor.h"

using namespace std;



class Controlador:public IControlador {
public:
    Controlador();
    ~Controlador() override;
    void altaCliente(string Nombre, string Contraseña,Date FNacimiento,
    DataDirec Direccion, string Ciudad) override;
    void altaVendedor(string Nombre, string Contraseña,
    Date FNacimiento, string RUT) override;
    void listarUsuarios() override;
    void listarVendedores() override;

    void crearPromocion(string Nombre, string Descripcion, Date FVencimiento, int Descuento) override;
    void listarPromosVigentes() override;
    void verInfoPromo(string nombre) override;

    void altaProducto(string Nombre, float Precio, int Stock,
    string Descripcion, Cat Categoria, string NicknameVendedor) override;

    void listarProductos() override;
    void listarProductos(string NicknameVendedor) override;
    void mostrarDatosProducto(int CodProd) override;
    void listarNickUsuarios() override;


    void realizarComentario(string Texto) override;
    void responderComentario(int ID, string Texto) override;
    void listarComentarios() override;
    bool productoEnPromocionVigente(Producto* &producto) const ;
    void seleccionarProducto(int codProd, int cantidad) override;
    void seleccionarProducto(int codProd) override;
    void seleccionarUsuario(string nombre) override;
    bool productoYaAgregado(Producto* p);
    void listarComentarios(string nick) override;
    void eliminarComentarios(int id) override;
    void listarNickClientes() override;
    void agregarProducto(int codProd, int cantidad) override;
    void confirmarYMostrarCompra() override;
    void seleccionarCliente(string nick) override;
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