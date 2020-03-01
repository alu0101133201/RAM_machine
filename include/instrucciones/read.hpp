// Fichero que define la instruccion read
#pragma once
#include "instruccion.hpp"

class read : public instruccion {
  public:
    read();
    ~read();

    bool ejecutar(memoria&, cinta_escritura&, cinta_lectura&,
        std::tuple<int, int, std::string>,int&);
};


