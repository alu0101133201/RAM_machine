//Fichero que define una cinta de lectura
//Clase que hereda de cinta
#pragma once

#include "cinta.hpp"

class cinta_lectura : public cinta {
  public:
    cinta_lectura(std::ifstream&);
    int leer(void);
};
