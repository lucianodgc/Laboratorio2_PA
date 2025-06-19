#include <iostream>
#include "Fabrica.h"
#include "Estructuras.h"

void cargarDatosPrueba();

int main() {



    IControladorUsuario* ctrl = Fabrica::getControladorUsuario();
    int op;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Alta de cliente\n";
        cout << "2. Listar usuarios\n";
        cout << "3. Cargar datos de prueba\n";
        cout << "0. Salir\n";
        cout << "Seleccione: ";
        cin >> op;
        cin.ignore();

        if (op == 1) {
            string Nombre, Contraseña, Ciudad, NomCalle;
            int d, m, a, NroPuerta;
            cout << "Nickname: "; getline(cin, Nombre);
            cout << "Contraseña: "; getline(cin, Contraseña);
            cout << "Fecha nacimiento (d m a): "; cin >> d, m, a; cin.ignore();
            cout << "Direccion: "; cin >> NomCalle, NroPuerta; cin.ignore();
            cout << "Ciudad: "; getline(cin, Ciudad);
            ctrl->altaCliente(Nombre, Contraseña, Date(d, m, a), DataDirec(NomCalle, NroPuerta), Ciudad);
        }
        else if (op == 2) ctrl->listarUsuarios();
        else if (op == 3) cargarDatosPrueba();
    } while (op != 0);

    return 0;
}

void cargarDatosPrueba() {
    auto ctrl = Fabrica::getControladorUsuario();
    ctrl->altaCliente("luciano", "clave123", Date(10,6,2000), DataDirec("Calle Falsa", 1234), "Maldonado");
    ctrl->altaCliente("sofia", "clave456", Date(5,5,1995), DataDirec("Av Siempreviva", 742), "Montevideo");
    cout << "\n[OK] Datos de prueba cargados.\n";
}