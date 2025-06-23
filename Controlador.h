
#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Interfaces.h"
#include "IControlador.h"
using namespace std;



class Controlador:public IControlador {
public:
    Controlador();
    virtual ~Controlador();
    void altaCliente(string Nombre, string Contraseña,Date FNacimiento,
    DataDirec Direccion, string Ciudad);
    void altaVendedor(string Nombre, string Contraseña,
    Date FNacimiento, string RUT);
    void listarUsuarios();
    void listarVendedores();
    void CrearPromocion(string Nombre, string Descripcion, Date FVencimiento, string NicknameVendedor);
    void ListarPromosVigentes();
    DTpromocion VerInfoPromo();
    void AltaProducto(string Nombre, float Precio, int Stock,
    string Descripcion, Cat Categoria, string NicknameVendedor);
    void AgregarProducto(string CodProd, int Cantidad);
    DTprod MostrarDatosProducto(string CodProd);
    set<DTproducto> ListarProductos();
    void agregarProducto(Vendedor* Vend, Producto* Prod);
    void agregarProducto(string &CodProd, int Cantidad);
    void RealizarComentario(string Texto);
    void ResponderComentario(int ID, string Texto);
    int generarCodigoProducto();
    Vendedor* SeleccionarVendedor(string nickname);
private:
    IDictionary* Usuarios;
    IDictionary* Promociones;
    IDictionary* Productos;
    IDictionary* Compras;
    IDictionary* Comentarios;
};



#endif