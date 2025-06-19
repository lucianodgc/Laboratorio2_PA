
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

void ControladorUsuario::altaVendedor(std::string nombre, std::string email,
Date nacimiento, std::string empresa) {
}

void ControladorUsuario::listarUsuarios() {
    IIterator* it = Usuarios->getIterator();
    while (it->hasCurrent()) {
        Usuario* u = dynamic_cast<Usuario*>(it->getCurrent());
        cout << "- " << u->getNickname() << "- Nac: " << u->getNacimiento().toString() << endl;
        it->next();
    }
    delete it;
}


