
#include "Usuario.h"

Usuario::Usuario(string Nickname, string Contraseña, Date Fnacimiento) {
    this->Nickname = Nickname;
    this->Contraseña = Contraseña;
    this->Fnacimiento = Fnacimiento;
}

Usuario::~Usuario() {}

string Usuario::getNickname(){return Nickname;}

Date Usuario::getNacimiento(){return Fnacimiento;}