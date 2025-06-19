
#ifndef CLIENTE_H
#define CLIENTE_H

#include "Interfaces.h"
#include "Usuario.h"

using namespace std;



class Cliente:public Usuario {
public:
    Cliente(string Nickname, string Contraseña, Date Fnacimiento, DataDirec Direccion, string Ciudad);
    virtual ~Cliente();
    DataDirec getDireccion();
    string getCiudad();
private:
	DataDirec Direccion;
    string Ciudad;
    ICollection* Compras;
};



#endif
