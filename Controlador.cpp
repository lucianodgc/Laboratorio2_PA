
#include "Controlador.h"

Controlador::Controlador() {
    Usuarios = new OrderedDictionary();
    Productos = new OrderedDictionary();
    Promociones = new OrderedDictionary();
    Compras = new OrderedDictionary();
    Comentarios = new OrderedDictionary();
}

Controlador::~Controlador() = default;

void Controlador::RealizarComentario(string texto) {}

void Controlador::ResponderComentario(int id, string texto) {}

int Controlador::generarCodigoProducto() {
    int maxCod = 0;
    for (IIterator* it = Productos->getIterator(); it->hasCurrent(); it->next()) {
        auto* prod = dynamic_cast<Producto *>(it->getCurrent());
        if (prod != nullptr && prod->getCodProd() > maxCod) {
            maxCod = prod->getCodProd();
        }
    }
    return maxCod + 1;
}


void Controlador::CrearPromocion(string Nombre, string Descripcion,
Date FVencimiento, int Descuento) {
    string NicknameVendedor = vendedorSesion->getNickname();
    IKey* key = new String(NicknameVendedor.c_str());

    auto* vendedor = dynamic_cast<Vendedor*>(Usuarios->find(key));
    if (vendedor == nullptr) {
        cout << "\nVendedor no existe o no es válido.";
        return;
    }

    delete key;
    Promocion* promo = vendedorSesion->crearPromocion(Nombre, Descripcion, FVencimiento, Descuento);
    key = new String(Nombre.c_str());
    Promociones->add(key, promo);
    promocionActual = promo;
    cout << "Promoción creada correctamente.\n";
}

void Controlador::SeleccionarProducto(int codProd, int cantidad) {
        IKey* key = new Integer(codProd);
        auto* p = dynamic_cast<Producto*>(Productos->find(key));
        delete key;
        if (p == nullptr) {
            cout << "Producto no existe.\n";
            return;
        } if (productoEnPromocionVigente(p)) {
            cout << "Ese producto ya está en una promoción vigente.\n";
            return;
        }
        if (promocionActual->productoYaAgregado(p)) {
            cout << "El producto ya existe en esta promoción" << endl;
            return;
        }

        string nombre = promocionActual->getNombre();
        key = new String(nombre.c_str());
        auto* promo = dynamic_cast<Promocion*>(Promociones->find(key));
        promo->agregarProducto(p, cantidad);

        cout << "Producto agregado a la promoción.\n";
}

void Controlador::altaCliente(string Nickname, string Contraseña,
Date FNacimiento, DataDirec Direccion, string Ciudad) {
    IKey* clave = new String(Nickname.c_str());
    if (Usuarios->member(clave)) {
        cout << "\n[ERROR] Ya existe un usuario con ese nickname.\n";
        delete clave;
        return;
    } if (Contraseña.length() < 6) {
        cout << "\n[ERROR] La contraseña debe ser de al menos 6 caracteres.\n";
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
    } if (Contraseña.length() < 6) {
        cout << "\n[ERROR] La contraseña debe ser de al menos 6 caracteres.\n";
        delete clave;
        return;
    } if (RUT.length() != 12) {
        cout << "\n[ERROR] El RUT debe ser de 12 caracteres.\n";
        delete clave;
        return;
    }
    clave = new String(Nickname.c_str());
    Usuarios->add(clave, new Vendedor(Nickname, Contraseña, FNacimiento, RUT));
    cout << "[OK] Vendedor registrado correctamente.\n";
}

void Controlador::AltaProducto(string Nombre, float Precio, int Stock,
    string Descripcion, Cat Categoria, string NicknameVendedor) {
    IKey* key = new String(NicknameVendedor.c_str());
    auto* vendedor = dynamic_cast<Vendedor*>(Usuarios->find(key));
    if (vendedor == nullptr) {
        cout << "\nVendedor no existe o no es válido.";
        return;
    }

    int codigo = generarCodigoProducto();
    auto* p = new Producto(codigo, Nombre, Precio, Stock, Descripcion, Categoria, vendedor);

    key = new Integer(codigo);
    Productos->add(key, p);

    vendedor->agregarProducto(p);

    cout << "Producto agregado correctamente" << endl;
}

void Controlador::listarUsuarios() {
    for (IIterator* it = Usuarios->getIterator();it->hasCurrent();it->next()) {
        auto* u = dynamic_cast<Usuario*>(it->getCurrent());
        cout << "Nickname: " << u->getNickname() << "\nF.Nacimiento: " << u->getNacimiento().toString() << endl;
        auto* v = dynamic_cast<Vendedor*>(u);
        if (v != nullptr) {
            cout << "RUT: " << v->getRUT() << endl << endl;
        } else {
            auto* c = dynamic_cast<Cliente*>(u);
            if (c != nullptr) {
                cout << "Direccion: " << c->getDireccion().toString() << endl;
                cout << "Ciudad: " << c->getCiudad() << endl << endl;
            }
        }
    }
}

void Controlador::listarVendedores() {

    for (IIterator* it = Usuarios->getIterator(); it->hasCurrent(); it->next()) {
        auto* u = dynamic_cast<Usuario*>(it->getCurrent());
        auto* v = dynamic_cast<Vendedor*>(u);
        if (v != nullptr) cout << "Nickname: " << v->getNickname() << endl;
    }
}

void Controlador::ListarProductos() {
    for (IIterator* it = Productos->getIterator(); it->hasCurrent(); it->next()) {
        auto* p = dynamic_cast<Producto*>(it->getCurrent());
        cout << "Código: " << p->getCodProd() << " - " << p->getNombre() << endl;
    }
}

void Controlador::ListarProductos(string NicknameVendedor) {
    IKey* key = new String(NicknameVendedor.c_str());
    auto* vendedor = dynamic_cast<Vendedor*>(Usuarios->find(key));
    delete key;
    IDictionary* Productos = vendedor->getProductos();

    for (IIterator* it = Productos->getIterator(); it->hasCurrent(); it->next()) {
        if (auto* p = dynamic_cast<Producto*>(it->getCurrent()))
            cout << "Código: " << p->getCodProd() << " - " << p->getNombre() << endl;
    }
    vendedorSesion = vendedor;
}

void Controlador::ListarPromosVigentes() {
    Date const hoy = Date::obtenerFechaActual();

    for (IIterator* it = Promociones->getIterator(); it->hasCurrent(); it->next()) {
        auto* p = dynamic_cast<Promocion*>(it->getCurrent());
        if (p->getFVencimiento().fechaEsMayorIgual(hoy)) {
            cout << "Nombre: " << p->getNombre() << endl;
            cout << "Descripción: " << p->getDescripcion() << endl;
            cout << "Descuento: " << p->getDescuento() << endl;
            cout << "Fecha de vencimiento: " << p->getFVencimiento().toString() << endl << endl;
        }
    }
}

void Controlador::mostrarDatosProducto(int CodProd) {
    IKey* key = new Integer(CodProd);
    if (!Productos->member(key)) {
        delete key;
        cout << "Producto no encontrado." << endl;
        return;
    }

    auto* p = dynamic_cast<Producto*>(Productos->find(key));
    delete key;

    cout << "Nombre: " << p->getNombre() << endl;
    cout << "Precio: $" << p->getPrecio() << endl;
    cout << "Stock: " << p->getStock() << endl;
    cout << "Descripción: " << p->getDescripcion() << endl;

    Cat cat = p->getCategoria();
    if (cat == Ropa) cout << "Categoría: Ropa" << endl;
    else if (cat == Electrodomesticos) cout << "Categoría: Electrodomésticos" << endl;
    else cout << "Categoría: Otros" << endl;

    Vendedor* v = p->getVendedor();
    if (v != nullptr) cout << "Vendedor: " << v->getNickname() << endl;
}

void Controlador::VerInfoPromo(string nombre) {
    IKey* ik = new String(nombre.c_str());
    auto* promo = dynamic_cast<Promocion*>(Promociones->find(ik));
    delete ik;
    ICollection* col = promo->getPromocionProducto();
    Producto* prod = nullptr;
    cout << "Productos: " << endl;
    for (IIterator* it = col->getIterator(); it->hasCurrent(); it->next()) {
        auto* p = dynamic_cast<PromocionProducto*>(it->getCurrent());
        prod = p->getProducto();
        cout << "\nDatos del Producto: " << endl;
        cout << "Nombre: " << prod->getNombre() << endl;
        cout << "Stock: " << prod->getStock() << endl;
        cout << "Categoria: " << prod->getCategoria() << endl;
        cout << "Descripción: " << prod->getDescripcion() << endl;
    }
    Vendedor* vend = prod->getVendedor();
    cout << "\nDatos del Vendedor: " << endl;
    cout << "Nombre: " << vend->getNickname() << endl;
    cout << "RUT: " << vend->getRUT() << endl;
    cout << "Fecha de Nacimiento: " << vend->getNacimiento().toString() << endl;
}

bool Controlador::productoEnPromocionVigente(Producto* &producto) const {
    Date const hoy = Date::obtenerFechaActual();

    for (IIterator* it = Promociones->getIterator(); it->hasCurrent(); it->next()) {
        auto* prom = dynamic_cast<Promocion*>(it->getCurrent());
        if (prom != nullptr && prom->getFVencimiento().fechaEsMayorIgual(hoy)) {
            ICollection* col = prom->getPromocionProducto();
            for (IIterator* itPP = col->getIterator(); itPP->hasCurrent(); itPP->next()) {
                auto* pp = dynamic_cast<PromocionProducto*>(itPP->getCurrent());
                if (pp != nullptr && pp->getProducto() == producto) {
                    delete itPP;
                    delete it;
                    return true;
                }
            }
        }
    }
    return false;
}
