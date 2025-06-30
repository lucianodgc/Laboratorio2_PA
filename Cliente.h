
#ifndef CLIENTE_H
#define CLIENTE_H

#include "Interfaces.h"
#include "Usuario.h"
#include "Compras.h"

using namespace std;



class Cliente:public Usuario {
public:
    Cliente(string const &nickname, string const &contraseña, Date const &fNacimiento,
    DataDirec const &direccion, string const &ciudad);
    ~Cliente() override;
    DataDirec getDireccion();
    string getCiudad();
    ICollection* getCompras() const;
    static Compras* crearCompra() ;
    void agregarCompra(Compras *comp) const;


private:
	DataDirec direccion;
    string ciudad;
    ICollection* compras;
};



#endif
