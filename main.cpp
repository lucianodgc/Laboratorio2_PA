#include <iostream>
#include "Fabrica.h"
#include "Estructuras.h"

void cargarDatosPrueba();

int main() {

    IControlador* ctrl = Fabrica::getControlador();
    int op;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Alta de usuario\n";
        cout << "2. Listado de usuarios\n";
        cout << "3. Alta de producto\n";
        cout << "4. Consultar producto\n";
        cout << "5. Crear promoción\n";
        cout << "6. Consultar promoción\n";
        cout << "7. Realizar compra\n";
        cout << "8. Dejar comentario\n";
        cout << "9. Eliminar comentario\n";
        cout << "10. Enviar producto\n";
        cout << "11. Expediente de Usuario\n";
        cout << "0. Salir\n";
        cout << "Seleccione: ";
        cin >> op; cin.ignore(); cout << endl;
        string Nombre, Contraseña, Nick, Descripcion, categoria;
        int d, m, a, Stock, CodP, Desc, cantidad;
        char z, op1;
        float Precio;
        Cat Categoria;

        switch (op) {
            case 1:
                cout << "Ingresar Cliente(1) o Ingresar Vendedor(2): "; cin >> op; cin.ignore();
                cout << "Nickname: "; getline(cin, Nombre);
                cout << "Contraseña: "; getline(cin, Contraseña);
                cout << "Fecha nacimiento (dd/mm/aa): "; cin >> d >> z >> m >> z >> a; cin.ignore();

                if (op == 1) {
                    string ciudad, nomCalle;
                    int nroPuerta;
                    cout << "Direccion (calle): "; getline(cin, nomCalle);
                    cout << "Numero: "; cin >> nroPuerta; cin.ignore();
                    cout << "Ciudad: "; getline(cin, ciudad);
                    ctrl->altaCliente(Nombre, Contraseña, Date(d, m, a), DataDirec(nomCalle, nroPuerta), ciudad);
                } else {
                    string rut;
                    cout << "RUT: "; getline(cin, rut);
                    ctrl->altaVendedor(Nombre, Contraseña, Date(d, m, a), rut);
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            case 2:
                ctrl->listarUsuarios();
                cout << "Presione Enter para continuar...";
                cin.get();
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
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            case 4:
                cout << "Productos: " << endl;
                ctrl->ListarProductos();
                cout << "\nSeleccione un producto: "; cin >> CodP; cin.ignore();
                ctrl->mostrarDatosProducto(CodP);
                cout << "\nPresione Enter para continuar...";
                cin.get();
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
                ctrl->CrearPromocion(Nombre, Descripcion, Date(d, m, a), Desc);
                do {
                    cout << "Ingrese el código del producto (0 para terminar): "; cin >> CodP; cin.ignore();
                    if (CodP == 0) {break;}
                    cout << "Cant.min para aplicar promoción: "; cin >> cantidad; cin.ignore();
                    ctrl->SeleccionarProducto(CodP, cantidad);
                } while (true);
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            case 6:
                cout << "Promociones vigentes: " << endl << endl;
                ctrl->ListarPromosVigentes();
                cout << "Desea ver los detalles de la promoción (S/N): " << endl; cin >> op1; cin.ignore();
                if (op1 == 'S' || op1 == 's') {
                    cout << "Ingrese nombre de la promocion: "; getline(cin, Nombre);
                    ctrl->VerInfoPromo(Nombre);
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
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
            case 11:
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
    ctrl->AltaProducto("Queso", 1234, 12, "Qsy", Otros, "Ignacio");
    ctrl->AltaProducto("Papas", 1234, 12, "Qsy", Otros, "Ignacio");
    ctrl->AltaProducto("Vino", 1234, 12, "Qsy", Otros, "Thiago");
    ctrl->AltaProducto("Lechuga", 1234, 12, "Qsy", Otros, "Thiago");
    ctrl->AltaProducto("Tomate", 1234, 12, "Qsy", Otros, "Thiago");
    /*ctrl->ListarProductos("Ignacio");
    ctrl->CrearPromocion("Promo1", "Descripcion", Date(27, 8, 2025), 20);
    ctrl->SeleccionarProducto(1, 10);
    ctrl->SeleccionarProducto(2, 12);
    ctrl->ListarProductos("Thiago");
    ctrl->CrearPromocion("Promo2", "Descripcion", Date(28, 8, 2025), 20);
    ctrl->SeleccionarProducto(4, 15);
    ctrl->SeleccionarProducto(6, 14);*/
    cout << "\n[OK] Datos de prueba cargados.\n";
}