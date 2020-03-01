// Fichero que define la instruccion halt
#pragma once
#include "instruccion.hpp"

class halt : public instruccion {
  public:
    halt();
    ~halt();

    bool ejecutar(memoria&, cinta_escritura&, cinta_lectura&,
        std::tuple<int, int, std::string>,int&);
};


