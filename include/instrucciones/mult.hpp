// Fichero que define la instruccion mult
#pragma once
#include "instruccion.hpp"

class mult : public instruccion {
  public:
    mult();
    ~mult();

    bool ejecutar(memoria&, cinta_escritura&, cinta_lectura&,
        std::tuple<int, int, std::string>,int&);
};


