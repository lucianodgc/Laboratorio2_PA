
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
    void crearCompra(float montoFinal, Date fCompra) const;
private:
	DataDirec Direccion;
    string Ciudad;
    ICollection* compras;
};



#endif
