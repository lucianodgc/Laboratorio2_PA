
#include "Controlador.h"

#include "Comentario.h"

Controlador::Controlador() {
    usuarios = new OrderedDictionary();
    productos = new OrderedDictionary();
    promociones = new OrderedDictionary();
    compras = new OrderedDictionary();
}

Controlador::~Controlador() = default;

void Controlador::agregarProducto(int codProd, int cantidad) {
    IKey* key = new Integer(codProd);
    auto* prod = dynamic_cast<Producto*>(productos->find(key));
    compraActual->agregarProducto(prod, cantidad);
    delete key;
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

    auto* prod = new Producto(Nombre, Precio, Stock, Descripcion, Categoria, vendedor);
    key = new Integer(prod->getCodProd());
    productos->add(key, prod);
    vendedor->agregarProducto(prod);

    cout << "Producto agregado correctamente" << endl;
}

void Controlador::confirmarYMostrarCompra() {
    char op1;
    ICollection* compra = compraActual->getProductoCompras();
    Date const hoy = Date::obtenerFechaActual();
    Producto* prod = nullptr;
    float montoFinal = 0;
    for (IIterator* it = compra->getIterator(); it->hasCurrent(); it->next()) {
        auto* pp = dynamic_cast<ProductoCompras*>(it->getCurrent());
        prod = pp->getProducto();
        montoFinal += prod->getPrecio() * pp->getCantidad();
    }
    cout << "\nDetalles de la compra: " << endl;
    cout << "Precio total: " << montoFinal << endl;
    cout << "Fecha de compra: " << hoy.toString() << endl << endl;
    cout << "Datos de los productos: " << endl;
    for (IIterator* it = compra->getIterator(); it->hasCurrent(); it->next()) {
        auto* pp = dynamic_cast<ProductoCompras*>(it->getCurrent());
        if (prod != nullptr) {
            prod = pp->getProducto();
            cout << "Nombre: " << prod->getNombre() << endl;
            cout << "Precio: $" << prod->getPrecio() << endl;
            cout << "Descripción: " << prod->getDescripcion() << endl;
            cout << "Cantidad: " << pp->getCantidad()<< endl << endl;
        }
    }
    cout << "Confirmar compra? (S/N)"; cin >> op1; cin.ignore();
    if (op1 == 'S' || op1 == 's') {
        clienteActual->agregarCompra(compraActual);
        for (IIterator* it = compra->getIterator(); it->hasCurrent(); it->next()) {
            auto* pp = dynamic_cast<ProductoCompras*>(it->getCurrent());
            if (prod != nullptr) {
                auto* prod1 = pp->getProducto();
                prod1->agregarProdCompra(pp);
            }
        }
    } else cout << "Compra cancelada";
}

void Controlador::crearCompra(string nick) {
    IKey* key = new String(nick.c_str());
    auto* cli = dynamic_cast<Cliente*>(usuarios->find(key));
    delete key;
    clienteActual = cli;
    compraActual = clienteActual->crearCompra();
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

void Controlador::eliminarComentarios(int id) {
    IKey* key = new Integer(id);
    for (IIterator* it = usuarios->getIterator();it->hasCurrent();it->next()) {
        auto* us = dynamic_cast<Usuario*>(it->getCurrent());
        IDictionary *col = us->getComentarios();
        bool esta = col->member(key);
        if (esta) {
            auto* comen = dynamic_cast<Comentario*>(col->find(key));
            us->eliminarComentario(comen, productos);
        }
    }
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

void Controlador::listarCompras(int codProd) {
    for (IIterator* it = usuarios->getIterator(); it->hasCurrent(); it->next()) {
        auto* cli = dynamic_cast<Cliente*>(it->getCurrent());
        if (cli != nullptr) {
            auto* comprasCliente = cli->getCompras();
            for (IIterator* itComp = comprasCliente->getIterator(); itComp->hasCurrent(); itComp->next()) {
                auto* compra = dynamic_cast<Compras*>(itComp->getCurrent());
                if (compra != nullptr) {
                    auto* productosCompra = compra->getProductoCompras();
                    for (IIterator* itProd = productosCompra->getIterator(); itProd->hasCurrent(); itProd->next()) {
                        auto* prodComp = dynamic_cast<ProductoCompras*>(itProd->getCurrent());
                        bool enviado = prodComp->getEnviado();
                        if (!enviado) {
                            if (prodComp->getProducto()->getCodProd() == codProd) {
                                cout << "Nickname del cliente: " << cli->getNickname() << endl;
                                cout << "Fecha de compra: " << compra->getFCompra().toString() << endl << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    IKey* key = new Integer(codProd);
    auto* prod = dynamic_cast<Producto*>(productos->find(key));
    productoActual = prod;
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

void Controlador::listarNickVendedores() {

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

void Controlador::listarProductosPendiente(string NicknameVendedor) {
    IKey* key = new String(NicknameVendedor.c_str());
    auto* vendedor = dynamic_cast<Vendedor*>(usuarios->find(key));
    delete key;
    if (vendedor != nullptr) {
        ProductoCompras* pp = nullptr;
        IDictionary* Productos = vendedor->getProductos();
        for (IIterator* it = Productos->getIterator(); it->hasCurrent(); it->next()) {
            auto* prod = dynamic_cast<Producto*>(it->getCurrent());
            if (prod != nullptr) {
                pp = prod->getProdComp();
                cout << "Productos: " << endl << endl;
                if (pp != nullptr) {
                    bool enviado = pp->getEnviado();
                    if (!enviado) {
                        cout << "Código: " << prod->getCodProd() << endl;
                        cout << "Nombre: " << prod->getNombre() << endl << endl;
                    }
                }
            }
        }
    }
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

void Controlador::marcarProducto(string nickCliente, Date fechaCompra) {
    IKey* key = new String(nickCliente.c_str());
    auto* cli = dynamic_cast<Cliente*>(usuarios->find(key));
    delete key;

    if (cli != nullptr) {
        auto* comprasCliente = cli->getCompras();
        for (IIterator* itCompra = comprasCliente->getIterator(); itCompra->hasCurrent(); itCompra->next()) {
            auto* compra = dynamic_cast<Compras*>(itCompra->getCurrent());
            if (compra != nullptr) {
                if (compra->getFCompra().fechaEsMayorIgual(fechaCompra)) {
                    auto* productosCompra = compra->getProductoCompras();
                    for (IIterator* itPC = productosCompra->getIterator(); itPC->hasCurrent(); itPC->next()) {
                        auto* prodComp = dynamic_cast<ProductoCompras*>(itPC->getCurrent());
                        if (prodComp != nullptr){

                            auto* prod = prodComp->getProducto();
                            if (prod && prod->getCodProd() == productoActual->getCodProd() && !prodComp->getEnviado()) {
                                prodComp->enviarProducto();
                                cout << "Producto marcado como enviado." << endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No se encontró el producto o ya fue enviado." << endl;
}

void Controlador::mostrarDatosUsuario(string nick) {
    int z = 1;
    IKey* key = new String(nick.c_str());
    if (!usuarios->member(key)) {
        delete key;
        cout << "Usuario no encontrado." << endl;
        return;
    }
    auto* us = dynamic_cast<Usuario*>(usuarios->find(key));
    cout << "Nickname: " << us->getNickname() << endl;
    cout << "Nacimiento: " << us->getNacimiento().toString() << endl;

    auto vend = dynamic_cast<Vendedor*>(us);
    if (vend != nullptr) {
        auto* prod = vend->getProductos();
        auto* promo = vend->getPromociones();
        cout << "\nProductos: " << endl;
        for (IIterator* it = prod->getIterator(); it->hasCurrent(); it->next()) {
            auto* producto = dynamic_cast<Producto*>(it->getCurrent());
            if (producto != nullptr) cout << "Nombre: " << producto->getNombre() << endl;
        }
        cout << "\nPromociones: " << endl;
        for (IIterator* it = promo->getIterator(); it->hasCurrent(); it->next()) {
            auto* promo = dynamic_cast<Promocion*>(it->getCurrent());
            if (promo != nullptr) cout << "Nombre: " << promo->getNombre() << endl;
        }
    }
    auto c = dynamic_cast<Cliente*>(us);
    if (c != nullptr) {
        ICollection* comp = c->getCompras();
        for (IIterator* it = comp->getIterator(); it->hasCurrent(); it->next()) {
            auto* compra = dynamic_cast<Compras*>(it->getCurrent());
            ICollection* prodCom = compra->getProductoCompras();
            cout << "\nCompra"<<z<<": " << endl;
            for (IIterator* it = prodCom->getIterator(); it->hasCurrent(); it->next()) {
                auto* prodCompra = dynamic_cast<ProductoCompras*>(it->getCurrent());
                Producto* prod = prodCompra->getProducto();
                cout << "\nProductos: " << endl;
                cout << "Nombre: "<< prod->getNombre() << endl;
                cout << "Descripcion: "<< prod->getDescripcion() << endl;
                cout << "Precio: "<< prod->getPrecio() << endl;
                cout << "Stock: "<< prod->getStock() << endl;
                cout << "Categoría: "<< prod->getCategoria() << endl;
            }
            z++;
        }
    }
    delete key;
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

void Controlador::realizarComentario(string texto) {
    Comentario* comen = usuarioActual->nuevoComentario(texto);
    productoActual->agregarComentario(comen);
}

void Controlador::responderComentario(int id, string texto) {
    Date const hoy = Date::obtenerFechaActual();
    Comentario* comen = usuarioActual->nuevoComentario(texto);
    IDictionary* col = productoActual->getComentarios();
    IKey* key = new Integer(id);
    auto* comentario = dynamic_cast<Comentario*>(col->find(key));
    comentario->agregarRespuesta(comen);
    productoActual->agregarComentario(comen);
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


