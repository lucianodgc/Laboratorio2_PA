
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

    void CrearPromocion(string Nombre, string Descripcion, Date FVencimiento, int Descuento) override;
    void ListarPromosVigentes() override;
    void VerInfoPromo() override;

    void AltaProducto(string Nombre, float Precio, int Stock,
    string Descripcion, Cat Categoria, string NicknameVendedor) override;

    void ListarProductos() override;
    void ListarProductos(string NicknameVendedor) override;
    void mostrarDatosProducto(int CodProd) override;


    void RealizarComentario(string Texto) override;
    void ResponderComentario(int ID, string Texto) override;
    int generarCodigoProducto() override;
    bool productoEnPromocionVigente(Producto* &producto) const ;
    void SeleccionarProducto(int codProd, int cantidad) override;
    bool productoYaAgregado(Producto* p);
private:
    IDictionary* Usuarios;
    IDictionary* Promociones;
    IDictionary* Productos;
    IDictionary* Compras;
    IDictionary* Comentarios;
    Vendedor* vendedorSesion = nullptr;
    Promocion* promocionActual = nullptr;
};



#endif