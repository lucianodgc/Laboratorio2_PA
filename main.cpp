#include <iostream>
#include "Fabrica.h"
#include "Estructuras.h"

void cargarDatosPrueba();

int main() {



    IControlador* ctrl = Fabrica::getControlador();
    int op, op1;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Alta de usuario\n";
        cout << "2. Listado de usuarios\n";
        cout << "3. Alta de producto\n";
        cout << "4. Consultar producto\n";
        cout << "5. Crear promoción\n";
        cout << "6. Realizar compra\n";
        cout << "7. Dejar comentario\n";
        cout << "8. Eliminar comentario\n";
        cout << "9. Enviar producto\n";
        cout << "10. Expediente de Usuario\n";
        cout << "0. Salir\n";
        cout << "Seleccione: ";
        cin >> op; cin.ignore(); cout << endl;
        string Nombre, Contraseña, Ciudad, NomCalle, RUT, Nick, Descripcion, categoria;
        int d, m, a, NroPuerta, Stock, CodP, Desc;
        char z;
        float Precio;
        Cat Categoria;

        switch (op) {
            case 1:
                cout << "Ingresar Cliente(1) o Ingresar Vendedor(2): "; cin >> op1; cin.ignore();
                cout << "Nickname: "; getline(cin, Nombre);
                cout << "Contraseña: "; getline(cin, Contraseña);
                cout << "Fecha nacimiento (dd/mm/aa): "; cin >> d >> z >> m >> z >> a; cin.ignore();

                if (op1 == 1) {
                    cout << "Direccion (calle): "; getline(cin, NomCalle);
                    cout << "Numero: "; cin >> NroPuerta; cin.ignore();
                    cout << "Ciudad: "; getline(cin, Ciudad);
                    ctrl->altaCliente(Nombre, Contraseña, Date(d, m, a), DataDirec(NomCalle, NroPuerta), Ciudad);
                } else {
                    cout << "RUT: "; getline(cin, RUT);
                    ctrl->altaVendedor(Nombre, Contraseña, Date(d, m, a), RUT);
                }
                break;
            case 2:
                ctrl->listarUsuarios();
                break;
            case 3:
                cout << "Vendedores: " << endl;
                ctrl->listarVendedores();
                cout << "\nSeleccione un vendedor: "; getline(cin, Nick);
                cout << "Ingrese datos del producto: \nNombre:"; getline(cin, Nombre);
                cout << "Precio: "; cin >> Precio; cin.ignore();
                cout << "Cantidad en stock: "; cin >> Stock; cin.ignore();
                cout << "Descripcion: "; getline(cin, Descripcion);
                cout << "Categoria(ropa, electrodomésticos, otros): "; getline(cin, categoria);
                Categoria = stringToCat(categoria);
                ctrl->AltaProducto(Nombre, Precio, Stock, Descripcion, Categoria, Nick);
                break;
            case 4:
                cout << "Productos: " << endl;
                ctrl->ListarProductos();
                cout << "\nSeleccione un producto: "; cin >> CodP;
                ctrl->mostrarDatosProducto(CodP);
                break;
            case 5:
                cout << "Ingrese datos de la promoción: \nNombre:"; getline(cin, Nombre);
                cout << "Descripcion: "; getline(cin, Descripcion);
                cout << "F.Vencimiento (dd/mm/aa): "; cin >> d >> z >> m >> z >> a; cin.ignore();
                cout << "Descuento de la promoción: "; cin >> Desc; cin.ignore();
                cout << endl;
                ctrl->listarVendedores();
                cout << "\nSeleccione un vendedor: "; getline(cin, Nick);
                ctrl->ListarProductos(Nick);
                ctrl->CrearPromocion(Nombre, Descripcion, Date(d, m, a), Nick, Desc);
                break;
            case 6:
                cargarDatosPrueba();
                break;
            case 7:
                cargarDatosPrueba();
                break;
            case 8:
                cargarDatosPrueba();
                break;
            case 9:
                cargarDatosPrueba();
                break;
            case 10:
                cargarDatosPrueba();
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
                }
    } while (op != 0);

    return 0;
}

void cargarDatosPrueba() {
    auto ctrl = Fabrica::getControlador();
    ctrl->altaCliente("Luciano", "clave123", Date(10,6,2000), DataDirec("Calle Falsa", 1234), "Maldonado");
    ctrl->altaVendedor("Ignacio", "clave456", Date(5,5,1995),"123456789102");
    ctrl->altaVendedor("Thiago", "clave456", Date(5,5,1995),"123456789101");
    ctrl->AltaProducto("Pan", 1234, 12, "Qsy", Otros, "Ignacio");
    ctrl->AltaProducto("Vino", 1234, 12, "Qsy", Otros, "Thiago");
    cout << "\n[OK] Datos de prueba cargados.\n";
}