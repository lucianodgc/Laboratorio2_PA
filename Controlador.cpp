
#include "Controlador.h"

#include "Comentario.h"

Controlador::Controlador() {
    usuarios = new OrderedDictionary();
    productos = new OrderedDictionary();
    promociones = new OrderedDictionary();
}

Controlador::~Controlador() = default;

void Controlador::agregarProducto(int codProd, int cantidad) {
    IKey* key = new Integer(codProd);
    auto* prod = dynamic_cast<Producto*>(productos->find(key));
    delete key;
    compraActual->agregarProducto(prod, cantidad);
}

void Controlador::confirmarYMostrarCompra() {
    Date const hoy = Date::obtenerFechaActual();
    ICollection* col = compraActual->getProductoCompras();
    Producto* prod = nullptr;
    float montoFinal = 0;
    for (IIterator* it = col->getIterator(); it->hasCurrent(); it->next()) {
        auto* pp = dynamic_cast<ProductoCompras*>(it->getCurrent());
        prod = pp->getProducto();
        montoFinal =+ prod->getPrecio();
    }
    clienteActual->crearCompra(montoFinal, hoy);
    cout << "\nDetalles de la compra: " << endl;
    cout << "Precio total: " << compraActual->getMontoFinal() << endl;
    cout << "Fecha de compra: " << compraActual->getFCompra().toString() << endl;
    cout << "Datos de los productos: " << endl;
}

void Controlador::seleccionarCliente(string nick) {
    IKey* key = new String(nick.c_str());
    auto* cli = dynamic_cast<Cliente*>(usuarios->find(key));
    delete key;
    clienteActual = cli;
}

void Controlador::listarComentarios() {
        Producto* prod = productoActual;
        IDictionary* col = prod->getComentarios();
        for (IIterator* it = col->getIterator(); it->hasCurrent(); it->next()) {
            auto* comen = dynamic_cast<Comentario*>(it->getCurrent());
            cout << comen->getID() << endl;
            cout << comen->getTexto() << endl;
            cout << comen->getFComentario().toString() << endl;
        }
}

void Controlador::listarComentarios(string nick) {
    IKey* key = new String(nick.c_str());
    auto* us = dynamic_cast<Usuario*>(usuarios->find(key));
    IDictionary* col = us->getComentarios();
    for (IIterator* it = col->getIterator(); it->hasCurrent(); it->next()) {
        auto* comen = dynamic_cast<Comentario*>(it->getCurrent());
        cout << comen->getID() << endl;
        cout << comen->getTexto() << endl;
        cout << comen->getFComentario().toString() << endl;
    }
    usuarioActual = us;
}

void Controlador::realizarComentario(string texto) {
    Date const hoy = Date::obtenerFechaActual();
    Usuario* us = usuarioActual;
    int id = us->generarCodigoComentario();
    us->agregarComentario(id, texto, hoy, productoActual, usuarioActual);
    productoActual->agregarComentario(id, texto, hoy, productoActual, usuarioActual);
}

void Controlador::responderComentario(int id, string texto) {
    Date const hoy = Date::obtenerFechaActual();
    Producto* prod = productoActual;
    IDictionary* col = prod->getComentarios();
    IKey* key = new Integer(id);
    auto* comen = dynamic_cast<Comentario*>(col->find(key));
    Usuario* us = usuarioActual;
    int codComen = prod->generarCodigoComentario();
    us->agregarComentario(codComen, texto, hoy, productoActual, usuarioActual);
    prod->agregarComentario(codComen, texto, hoy, productoActual, usuarioActual);
    comen->agregarRespuesta(codComen, texto, hoy, productoActual, usuarioActual);

}

void Controlador::eliminarComentarios(int id) {
    Usuario* us = usuarioActual;
    us->eliminarComentario(id);
}

int Controlador::generarCodigoProducto() {
    int maxCod = 0;
    for (IIterator* it = productos->getIterator(); it->hasCurrent(); it->next()) {
        auto* prod = dynamic_cast<Producto *>(it->getCurrent());
        if (prod != nullptr && prod->getCodProd() > maxCod) {
            maxCod = prod->getCodProd();
        }
    }
    return maxCod + 1;
}

void Controlador::crearPromocion(string Nombre, string Descripcion,
Date FVencimiento, int Descuento) {
    string NicknameVendedor = vendedorActual->getNickname();
    IKey* key = new String(NicknameVendedor.c_str());

    auto* vendedor = dynamic_cast<Vendedor*>(usuarios->find(key));
    if (vendedor == nullptr) {
        cout << "\nVendedor no existe o no es válido.";
        return;
    }

    delete key;
    Promocion* promo = vendedorActual->crearPromocion(Nombre, Descripcion, FVencimiento, Descuento);
    key = new String(Nombre.c_str());
    promociones->add(key, promo);
    promocionActual = promo;
    cout << "Promoción creada correctamente.\n";
}

void Controlador::seleccionarProducto(int codProd) {
    IKey* key = new Integer(codProd);
    auto* prod = dynamic_cast<Producto*>(productos->find(key));
    delete key;
    productoActual = prod;
}

void Controlador::seleccionarUsuario(string nombre) {
    IKey* key = new String(nombre.c_str());
    auto* us = dynamic_cast<Usuario*>(usuarios->find(key));
    delete key;
    usuarioActual = us;
}

void Controlador::seleccionarProducto(int codProd, int cantidad) {
        IKey* key = new Integer(codProd);
        auto* p = dynamic_cast<Producto*>(productos->find(key));
        delete key;
        if (productoEnPromocionVigente(p)) {
            cout << "Ese producto ya está en una promoción vigente.\n";
            return;
        }
        if (promocionActual->productoYaAgregado(p)) {
            cout << "El producto ya existe en esta promoción" << endl;
            return;
        }

        string nombre = promocionActual->getNombre();
        key = new String(nombre.c_str());
        auto* promo = dynamic_cast<Promocion*>(promociones->find(key));
        promo->agregarProducto(p, cantidad);

        cout << "Producto agregado a la promoción.\n";
}

void Controlador::altaCliente(string Nickname, string Contraseña,
Date FNacimiento, DataDirec Direccion, string Ciudad) {
    IKey* clave = new String(Nickname.c_str());
    if (usuarios->member(clave)) {
        cout << "\n[ERROR] Ya existe un usuario con ese nickname.\n";
        delete clave;
        return;
    } if (Contraseña.length() < 6) {
        cout << "\n[ERROR] La contraseña debe ser de al menos 6 caracteres.\n";
        delete clave;
        return;
    }
    usuarios->add(clave, new Cliente(Nickname, Contraseña, FNacimiento, Direccion, Ciudad));
    cout << "[OK] Cliente registrado correctamente.\n";
}

void Controlador::altaVendedor(string Nickname, string Contraseña,
Date FNacimiento, string RUT) {
    IKey* clave = new String(RUT.c_str());
    if (usuarios->member(clave)) {
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
    usuarios->add(clave, new Vendedor(Nickname, Contraseña, FNacimiento, RUT));
    cout << "[OK] Vendedor registrado correctamente.\n";
}

void Controlador::altaProducto(string Nombre, float Precio, int Stock,
string Descripcion, Cat Categoria, string NicknameVendedor) {
    IKey* key = new String(NicknameVendedor.c_str());
    auto* vendedor = dynamic_cast<Vendedor*>(usuarios->find(key));
    if (vendedor == nullptr) {
        cout << "\nVendedor no existe o no es válido.";
        return;
    }

    int codigo = generarCodigoProducto();
    auto* p = new Producto(codigo, Nombre, Precio, Stock, Descripcion, Categoria, vendedor);

    key = new Integer(codigo);
    productos->add(key, p);

    vendedor->agregarProducto(p);

    cout << "Producto agregado correctamente" << endl;
}

void Controlador::listarUsuarios() {
    for (IIterator* it = usuarios->getIterator();it->hasCurrent();it->next()) {
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

void Controlador::listarNickUsuarios() {
    for (IIterator* it = usuarios->getIterator();it->hasCurrent();it->next()) {
        auto* u = dynamic_cast<Usuario*>(it->getCurrent());
        cout << "Nickname: " << u->getNickname() << endl;
    }
}

void Controlador::listarNickClientes() {
    for (IIterator* it = usuarios->getIterator();it->hasCurrent();it->next()) {
        auto* cli = dynamic_cast<Cliente*>(it->getCurrent());
        if (cli != nullptr) cout << "Nickname: " << cli->getNickname() << endl;
    }
}

void Controlador::listarVendedores() {

    for (IIterator* it = usuarios->getIterator(); it->hasCurrent(); it->next()) {
        auto* u = dynamic_cast<Usuario*>(it->getCurrent());
        auto* v = dynamic_cast<Vendedor*>(u);
        if (v != nullptr) cout << "Nickname: " << v->getNickname() << endl;
    }
}

void Controlador::listarProductos() {
    for (IIterator* it = productos->getIterator(); it->hasCurrent(); it->next()) {
        auto* p = dynamic_cast<Producto*>(it->getCurrent());
        cout << "Código: " << p->getCodProd() << " - " << p->getNombre() << endl;
    }
}

void Controlador::listarProductos(string NicknameVendedor) {
    IKey* key = new String(NicknameVendedor.c_str());
    auto* vendedor = dynamic_cast<Vendedor*>(usuarios->find(key));
    delete key;
    IDictionary* Productos = vendedor->getProductos();

    for (IIterator* it = Productos->getIterator(); it->hasCurrent(); it->next()) {
        if (auto* p = dynamic_cast<Producto*>(it->getCurrent()))
            cout << "Código: " << p->getCodProd() << " - " << p->getNombre() << endl;
    }
    vendedorActual = vendedor;
}

void Controlador::listarPromosVigentes() {
    Date const hoy = Date::obtenerFechaActual();

    for (IIterator* it = promociones->getIterator(); it->hasCurrent(); it->next()) {
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
    if (!productos->member(key)) {
        delete key;
        cout << "Producto no encontrado." << endl;
        return;
    }

    auto* p = dynamic_cast<Producto*>(productos->find(key));
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

void Controlador::verInfoPromo(string nombre) {
    IKey* ik = new String(nombre.c_str());
    auto* promo = dynamic_cast<Promocion*>(promociones->find(ik));
    delete ik;
    ICollection* col = promo->getPromocionProducto();
    Producto* prod = nullptr;
    cout << "Productos: " << endl;
    for (IIterator* it = col->getIterator(); it->hasCurrent(); it->next()) {
        auto* pp = dynamic_cast<PromocionProducto*>(it->getCurrent());
        prod = pp->getProducto();
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

    for (IIterator* it = promociones->getIterator(); it->hasCurrent(); it->next()) {
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
