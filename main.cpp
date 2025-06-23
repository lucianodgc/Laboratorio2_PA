#include <iostream>
#include "Fabrica.h"
#include "Estructuras.h"

void cargarDatosPrueba();

int main() {



    IControlador* ctrl = Fabrica::getControlador();
    int op, op1;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Alta Usuario\n";
        cout << "2. Listar usuarios\n";
        cout << "3. Cargar datos de prueba\n";
        cout << "0. Salir\n";
        cout << "Seleccione: ";
        cin >> op; cin.ignore(); cout << endl;
        string Nombre, Contraseña, Ciudad, NomCalle, RUT;
        int d, m, a, NroPuerta;
        char z;

        switch (op) {
            case 1:
                cout << "Ingresar Cliente(1) o Ingresar Vendedor(2): "; cin >> op1; cin.ignore();
                cout << "Nickname: "; getline(cin, Nombre);
                cout << "Contraseña: "; getline(cin, Contraseña);
                cout << "Fecha nacimiento (dd/mm/aa): ";
                cin >> d >> z >> m >> z >> a;
                cin.ignore();

                if (op1 == 1) {
                    cout << "Direccion (calle): ";
                    getline(cin, NomCalle);
                    cout << "Numero: ";
                    cin >> NroPuerta; cin.ignore();
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
                ctrl->listarVendedores();
                //ctrl->cargarDatosPrueba();
                break;
            case 4:
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
    ctrl->altaVendedor("Ignacio1", "clave456", Date(5,5,1995),"123456789102");
    ctrl->altaVendedor("Ignacio2", "clave456", Date(5,5,1995),"123456789103");
    ctrl->altaCliente("Luciano1", "clave123", Date(10,6,2000), DataDirec("Calle Falsa", 1234), "Maldonado");
    ctrl->altaVendedor("Ignacio3", "clave456", Date(5,5,1995),"123456789104");
    cout << "\n[OK] Datos de prueba cargados.\n";
}