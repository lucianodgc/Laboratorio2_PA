
#include "ControladorUsuario.h"

ControladorUsuario::ControladorUsuario() {Usuarios = new OrderedDictionary();}

ControladorUsuario::~ControladorUsuario() {}

void ControladorUsuario::altaCliente(string Nickname, string Contraseña,
Date FNacimiento, DataDirec Direccion, string Ciudad) {
    IKey* clave = new String(Nickname.c_str());
    if (Usuarios->member(clave)) {
        cout << "\n[ERROR] Ya existe un usuario con ese nickname.\n";
        delete clave;
        return;
    }
    Usuarios->add(clave, new Cliente(Nickname, Contraseña, FNacimiento, Direccion, Ciudad));
    cout << "\n[OK] Cliente registrado correctamente.\n";
}

void ControladorUsuario::altaVendedor(string Nickname, string Contraseña,
Date FNacimiento, string RUT) {
    IKey* clave = new String(RUT.c_str());
    if (Usuarios->member(clave)) {
        cout << "\n[ERROR] Ya existe un usuario con ese RUT.\n";
        delete clave;
        return;
    }
    Usuarios->add(clave, new Vendedor(Nickname, Contraseña, FNacimiento, RUT));
    cout << "\n[OK] Vendedor registrado correctamente.\n";
}

void ControladorUsuario::listarUsuarios() {
    IIterator* it = Usuarios->getIterator();
    while (it->hasCurrent()) {
        Usuario* u = dynamic_cast<Usuario*>(it->getCurrent());
        cout << "Nickname: " << u->getNickname() << "\nF.Nacimiento: " << u->getNacimiento().toString() << endl;
        Vendedor* v = dynamic_cast<Vendedor*>(u);
        if (v != nullptr) {
            cout << "RUT: " << v->getRUT() << endl;
        } else {
            Cliente* c = dynamic_cast<Cliente*>(u);
            if (c != nullptr) {
                cout << "Direccion: " << c->getDireccion().toString() << endl;
                cout << "Ciudad: " << c->getCiudad() << endl;
            }
        }

        it->next();
    }
    delete it;
}


