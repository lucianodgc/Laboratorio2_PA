
#include "Usuario.h"

Usuario::Usuario(string const &Nickname, string const &Contraseña, Date const &Fnacimiento) : Nickname(Nickname), Contraseña(Contraseña),
Fnacimiento(Fnacimiento) {Comentarios = new OrderedDictionary();}

Usuario::~Usuario() = default;

string Usuario::getNickname() {return Nickname;}

Date Usuario::getNacimiento() {return Fnacimiento;}