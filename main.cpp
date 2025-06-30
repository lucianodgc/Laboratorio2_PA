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
        cout << "9. Eliminar comentario\n (terminar)";
        cout << "10. Enviar producto\n (terminar)";
        cout << "11. Expediente de Usuario\n";
        cout << "12. Cargar datos de prueba\n";
        cout << "0. Salir\n";
        cout << "Seleccione: ";
        cin >> op; cin.ignore(); cout << endl;
        string nombre, contraseña, nick, descripcion, categoria, texto;
        int d, m, a, stock, codP, descuento, cantidad, id;
        char z, op1;
        float precio;
        Cat Categoria;

        switch (op) {
            case 1:
                cout << "Ingresar Cliente(1) o Ingresar Vendedor(2): "; cin >> op; cin.ignore();
                cout << "Nickname: "; getline(cin, nombre);
                cout << "Contraseña: "; getline(cin, contraseña);
                cout << "Fecha nacimiento (dd/mm/aa): "; cin >> d >> z >> m >> z >> a; cin.ignore();

                if (op == 1) {
                    string ciudad, nomCalle;
                    int nroPuerta;
                    cout << "Direccion (calle): "; getline(cin, nomCalle);
                    cout << "Numero: "; cin >> nroPuerta; cin.ignore();
                    cout << "Ciudad: "; getline(cin, ciudad);
                    ctrl->altaCliente(nombre, contraseña, Date(d, m, a), DataDirec(nomCalle, nroPuerta), ciudad);
                } else {
                    string rut;
                    cout << "RUT: "; getline(cin, rut);
                    ctrl->altaVendedor(nombre, contraseña, Date(d, m, a), rut);
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
                ctrl->listarNickVendedores();
                cout << "\nSeleccione un vendedor: "; getline(cin, nick);
                cout << "Ingrese datos del producto: \nNombre:"; getline(cin, nombre);
                cout << "Precio: "; cin >> precio; cin.ignore();
                cout << "Cantidad en stock: "; cin >> stock; cin.ignore();
                cout << "Descripcion: "; getline(cin, descripcion);
                cout << "Categoria(ropa, electrodomésticos, otros): "; getline(cin, categoria);
                Categoria = stringToCat(categoria);
                ctrl->altaProducto(nombre, precio, stock, descripcion, Categoria, nick);
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            case 4:
                cout << "Productos: " << endl;
                ctrl->listarProductos();
                cout << "\nSeleccione un producto: "; cin >> codP; cin.ignore();
                ctrl->mostrarDatosProducto(codP);
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            case 5:
                cout << "Ingrese datos de la promoción: \nNombre:"; getline(cin, nombre);
                cout << "Descripcion: "; getline(cin, descripcion);
                cout << "F.Vencimiento (dd/mm/aa): "; cin >> d >> z >> m >> z >> a; cin.ignore();
                cout << "Descuento de la promoción: "; cin >> descuento; cin.ignore();
                cout << endl;
                ctrl->listarNickVendedores();
                cout << "\nSeleccione un vendedor: "; getline(cin, nick);
                ctrl->listarProductos(nick);
                ctrl->crearPromocion(nombre, descripcion, Date(d, m, a), descuento);
                do {
                    cout << "Ingrese el código del producto (0 para terminar): "; cin >> codP; cin.ignore();
                    if (codP == 0) {break;}
                    cout << "Cant.min para aplicar promoción: "; cin >> cantidad; cin.ignore();
                    ctrl->seleccionarProducto(codP, cantidad);
                } while (true);
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            case 6:
                cout << "Promociones vigentes: " << endl << endl;
                ctrl->listarPromosVigentes();
                cout << "Desea ver los detalles de la promoción (S/N): " << endl; cin >> op1; cin.ignore();
                if (op1 == 'S' || op1 == 's') {
                    cout << "Ingrese nombre de la promocion: "; getline(cin, nombre);
                    ctrl->verInfoPromo(nombre);
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            case 7:
                ctrl->listarNickClientes();
                cout << "\nSeleccione un cliente: "; getline(cin, nick);
                ctrl->crearCompra(nick);
                ctrl->listarProductos();
                do {
                    cout << "\nDesea agreagar productos a la compra? (S/N)"; cin >> op1; cin.ignore();
                    if (op1 != 'S' && op1 != 's') break;
                    cout << "Ingrese codigo de producto: "; cin >> codP; cin.ignore();
                    cout << "Ingrese cantidad deseada: "; cin >> cantidad; cin.ignore();
                    ctrl->agregarProducto(codP, cantidad);
                } while (true);
                ctrl->confirmarYMostrarCompra();
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            case 8:
                ctrl->listarNickUsuarios();
                cout << "\nSeleccione un usuario: "; getline(cin, nick);
                ctrl->seleccionarUsuario(nick);
                ctrl->listarProductos();
                cout << "\nSeleccione un producto: "; cin >> codP; cin.ignore();
                ctrl->seleccionarProducto(codP);
                cout << "\nRealizar comentario nuevo o responder comentario existente "
                        "(Nuevo: 1, Existente: 2): "; cin >> op; cin.ignore();
                if (op == 1) {
                    cout << "\nIngrese texto del comentario: "; getline(cin, texto);
                    ctrl->realizarComentario(texto);
                    cout << "\nPresione Enter para continuar...";
                    cin.get();
                } else if (op == 2) {
                    ctrl->listarComentarios();
                    cout << "\nSeleccione un comentario: "; cin >> id; cin.ignore();
                    cout << "\nIngrese texto del comentario: "; getline(cin, texto);
                    ctrl->responderComentario(id, texto);
                    cout << "\nPresione Enter para continuar...";
                    cin.get();
                }
                break;
            case 9://"FALTA HACER"
                ctrl->listarNickUsuarios();
                cout << "\nSeleccione un usuario: "; getline(cin, nick);
                ctrl->listarComentarios(nick);
                ctrl->listarComentarios();
                cout << "\nSeleccione un comentario: "; cin >> id; cin.ignore();
                ctrl->eliminarComentarios(id);
                ctrl->listarComentarios();
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            case 10:
                ctrl->listarNickVendedores();
                cout << "\nSeleccione un usuario: "; getline(cin, nick);
                ctrl->listarProductosPendiente(nick);
                cout << "Ingrese codigo de producto: "; cin >> codP; cin.ignore();
                ctrl->listarCompras(codP);
                cout << "Ingrese el nombre del cliente: "; getline(cin, nick);
                cout << "Ingrese fecha de compra (dd/mm/aa): "; cin >> d >> z >> m >> z >> a; cin.ignore();
                ctrl->marcarProducto(nick, Date(d, m, a));
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            case 11:
                ctrl->listarNickUsuarios();
                cout << "\nSeleccione un usuario: "; getline(cin, nick);
                ctrl->mostrarDatosUsuario(nick);
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;
            case 12:
                cargarDatosPrueba();
                cout << "\nPresione Enter para continuar...";
                cin.get();
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
    ctrl->altaCliente("Pepe", "clave123", Date(11,6,2010), DataDirec("Calle Falsa1", 1234), "Montevideo");
    ctrl->altaVendedor("Ignacio", "clave456", Date(5,5,1995),"123456789102");
    ctrl->altaVendedor("Thiago", "clave456", Date(5,5,1995),"123456789101");
    ctrl->altaProducto("Pan", 32, 20, "Qsy", Otros, "Ignacio");
    ctrl->altaProducto("Queso", 12, 50, "Qsy", Otros, "Ignacio");
    ctrl->altaProducto("Papas", 34, 30, "Qsy", Otros, "Ignacio");
    ctrl->altaProducto("Vino", 124, 45, "Qsy", Otros, "Thiago");
    ctrl->altaProducto("Lechuga", 24, 70, "Qsy", Otros, "Thiago");
    ctrl->altaProducto("Tomate", 14, 40, "Qsy", Otros, "Thiago");
    ctrl->listarProductos("Ignacio");
    ctrl->crearPromocion("Oferton", "descripcion", Date(1, 11, 2026), 30);
    ctrl->seleccionarProducto(1, 20);
    ctrl->seleccionarProducto(3, 4);
    ctrl->seleccionarProducto(5, 2);
    ctrl->seleccionarUsuario("Luciano");
    ctrl->seleccionarProducto(1);
    ctrl->realizarComentario("xdxdxd");
    ctrl->seleccionarUsuario("Ignacio");
    ctrl->responderComentario(1, "pepe");
    ctrl->seleccionarUsuario("Luciano");
    ctrl->responderComentario(2, "papa");
    ctrl->crearCompra("Luciano");
    ctrl->agregarProducto(1, 3);
    ctrl->agregarProducto(2, 1);
    ctrl->confirmarYMostrarCompra();
    ctrl->crearCompra("Pepe");
    ctrl->agregarProducto(1, 3);
    ctrl->agregarProducto(2, 1);
    ctrl->confirmarYMostrarCompra();
    ctrl->crearCompra("Luciano");
    ctrl->agregarProducto(4, 2);
    ctrl->agregarProducto(5, 7);
    ctrl->confirmarYMostrarCompra();
    ctrl->crearCompra("Pepe");
    ctrl->agregarProducto(4, 2);
    ctrl->agregarProducto(3, 5);
    ctrl->confirmarYMostrarCompra();

    cout << "\n[OK] Datos de prueba cargados.\n";
}