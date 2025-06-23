#include "Fabrica.h"
#include "Controlador.h"

Controlador::Controlador() {
}

Controlador::~Controlador() {
}

void Controlador::RealizarComentario(std::string texto) {
}

void Controlador::ResponderComentario(int id, std::string texto) {
}

int Controlador::generarCodigoProducto() {
    IIterator* it;
    int cod;
    Producto* P;
    for (it = Productos->getIterator(); it->hasCurrent(); it->next()) {
        P = dynamic_cast<Producto *>(it->getCurrent());
        cod = P->getCodProd();
    }
    return cod+1;
}

void Controlador::AltaProducto(string Nombre, float Precio, int Stock,
    string Descripcion, Cat Categoria, string NicknameVendedor) {

    Vendedor* vendedor = SeleccionarVendedor(NicknameVendedor);
    if (vendedor == nullptr) cout << "Vendedor no existe o no es válido.";
    int codigo = generarCodigoProducto();
    Producto* p = new Producto(codigo, Nombre, Precio, Stock, Descripcion, Categoria);

    IKey* key = new Integer(codigo);
    Productos->add(key, p);

    vendedor->agregarProducto(p);

    cout << "Producto agregado correctamente" << endl;
}

void Controlador::AgregarProducto(string nombre, int cantidad) {
}

void Controlador::agregarProducto(Vendedor* Vend, Producto* Prod) {
    if (Vend != nullptr && Prod != nullptr) {
        //Vend->agregarProducto(Prod);
    }
}

DTprod Controlador::MostrarDatosProducto(string nombre) {
    return DTprod();
}

set<DTproducto> Controlador::ListarProductos() {
    return set<DTproducto>();
}

void Controlador::agregarProducto(string &CodProd, int Cantidad){}

void Controlador::CrearPromocion(string Nombre, string Descripcion,
Date FVencimiento, string NicknameVendedor) {
}

void Controlador::ListarPromosVigentes() {
}

DTpromocion Controlador::VerInfoPromo() {
    return DTpromocion();
}

void Controlador::altaCliente(string Nickname, string Contraseña,
Date FNacimiento, DataDirec Direccion, string Ciudad) {
    IKey* clave = new String(Nickname.c_str());
    if (Usuarios->member(clave)) {
        cout << "\n[ERROR] Ya existe un usuario con ese nickname.\n";
        delete clave;
        return;
    } else if (Nickname.length() < 6) {
        cout << "\n[ERROR] El Nickname debe ser de al menos 6 caracteres.\n";
        delete clave;
        return;
    }
    Usuarios->add(clave, new Cliente(Nickname, Contraseña, FNacimiento, Direccion, Ciudad));
    cout << "[OK] Cliente registrado correctamente.\n";
}

void Controlador::altaVendedor(string Nickname, string Contraseña,
Date FNacimiento, string RUT) {
    IKey* clave = new String(RUT.c_str());
    if (Usuarios->member(clave)) {
        cout << "\n[ERROR] Ya existe un usuario con ese RUT.\n";
        delete clave;
        return;
    } else if (Nickname.length() < 6) {
        cout << "\n[ERROR] El Nickname debe ser de al menos 6 caracteres.\n";
        delete clave;
        return;
    } else if (RUT.length() != 12) {
        cout << "\n[ERROR] El RUT debe ser de 12 caracteres.\n";
        delete clave;
        return;
    }
    Usuarios->add(clave, new Vendedor(Nickname, Contraseña, FNacimiento, RUT));
    cout << "[OK] Vendedor registrado correctamente.\n";
}

void Controlador::listarUsuarios() {
    IIterator* it;
    for (it = Usuarios->getIterator();it->hasCurrent();it->next()) {
        Usuario* u = dynamic_cast<Usuario*>(it->getCurrent());
        cout << "Nickname: " << u->getNickname() << "\nF.Nacimiento: " << u->getNacimiento().toString() << endl;
        Vendedor* v = dynamic_cast<Vendedor*>(u);
        if (v != nullptr) {
            cout << "RUT: " << v->getRUT() << endl << endl;
        } else {
            Cliente* c = dynamic_cast<Cliente*>(u);
            if (c != nullptr) {
                cout << "Direccion: " << c->getDireccion().toString() << endl;
                cout << "Ciudad: " << c->getCiudad() << endl << endl;
            }
        }
    }
    delete it;
}

void Controlador::listarVendedores() {
    IIterator* it;
    for (it = Usuarios->getIterator(); it->hasCurrent(); it->next()) {
        Usuario* u = dynamic_cast<Usuario*>(it->getCurrent());
        Vendedor* v = dynamic_cast<Vendedor*>(u);
        if (v != nullptr) cout << "Nickname: " << v->getNickname() << endl;
    }
    delete it;
}

Vendedor* Controlador::SeleccionarVendedor(string nickname) {
    IKey* key = new String(nickname.c_str());

    if (!Usuarios->member(key)) {
        delete key;
        return nullptr;
    }

    Vendedor* vendedor = dynamic_cast<Vendedor*>(Usuarios->find(key));
    delete key;

    return vendedor;
}