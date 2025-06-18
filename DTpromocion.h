
#ifndef DTPROMOCION_H
#define DTPROMOCION_H

#include <iostream>
#include "Vendedor.h"
#include "DTprod.h"

using namespace std;

struct DTpromocion{
    Vendedor* vendedor;
    DTprod* produto;
};


#endif
