
#ifndef CLIENTE_H
#define CLIENTE_H

#include "Interfaces.h"
#include "Usuario.h"
#include "Compras.h"

using namespace std;



class Cliente:public Usuario {
public:
    Cliente(string const &Nickname, string const &Contraseña, Date const &Fnacimiento,
    DataDirec const &Direccion, string const &Ciudad);
    ~Cliente() override;
    DataDirec getDireccion();
    string getCiudad();
    ICollection* getCompras() const;
    static Compras* crearCompra() ;
    void agregarCompra(Compras *comp) const;


private:
	DataDirec Direccion;
    string Ciudad;
    ICollection* compras;
};



#endif
